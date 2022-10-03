#ifndef EVENTHOLDER_HPP
#define EVENTHOLDER_HPP

#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid.hpp>

#include <functional>
#include <list>
#include <map>

template <class... Ts>
struct OverloadedLamda : Ts...
{
	using Ts::operator()...;
};

template <class... Ts>
OverloadedLamda(Ts...) -> OverloadedLamda<Ts...>;

namespace value_detail
{
// detail's explanation https://stackoverflow.com/questions/6534041/how-to-check-whether-operator-exists
struct No
{
};
template <typename T, typename Arg>
No operator==(const T&, const Arg&);

template <typename T, typename Arg = T>
struct EqualExists
{
	enum
	{
		value = !std::is_same<decltype(std::declval<T>() == std::declval<Arg>()), No>::value
	};
};
} // namespace value_detail

using Unsubscriber = std::function<void()>;

class IEventInitiator
{
public:
	virtual ~IEventInitiator() = default;
};

template <typename T>
class EventHolder
{
public:
	using Action = std::function<void(T&)>;
	class ActionWrapper;

	template <typename OnChange = Action>
	static Unsubscriber AddListener(IEventInitiator* updateInitiator, OnChange&& listener, bool instantNotify = false)
	{
		auto actionWrapper = ActionWrapper(std::forward<OnChange>(listener));
		SaveListener(updateInitiator, std::forward<OnChange>(listener));

		if (instantNotify)
		{
			listener(s_currentState);
		}

		return [uI = updateInitiator, aW = actionWrapper]() {
			RemoveListener(uI, aW);
		};
	}

	template <typename T>
	static void NotifyListeners(IEventInitiator* updateInitiator, T&& newState)
	{
		if constexpr (value_detail::EqualExists<T>::value)
		{
			if (s_currentState == newState)
			{
				return;
			}
		}

		s_currentState = std::forward<T>(newState);

		auto it = s_listeners.find(updateInitiator);
		if (it == s_listeners.end())
		{
			return;
		}
		
		auto [_, lCopy] = *it;
		for (auto& listener : lCopy)
		{
			listener(s_currentState);
		}
	}

private:
	static void RemoveListener(IEventInitiator* updateInitiator, const ActionWrapper& listener)
	{
		auto it = s_listeners.find(updateInitiator);
		if (it == s_listeners.end())
		{
			return;
		}

		auto& [_, _actionList] = *it;
		_actionList.remove(listener);
	}

	template <typename OnChange = Action>
	static void SaveListener(IEventInitiator* updateInitiator, OnChange&& listener)
	{
		auto it = s_listeners.find(updateInitiator);
		if (it == s_listeners.end())
		{
			it = s_listeners.insert({ updateInitiator, ActionList() }).first;
		}
		
		auto& [_, actionList] = *it;
		actionList.emplace_back(std::forward<OnChange>(listener));
	}

	class ActionWrapper
	{
	public:
		bool operator==(const ActionWrapper& other) const noexcept
		{
			return m_tag == other.m_tag;
		}

		template <typename A = Action>
		ActionWrapper(A&& action)
			: m_action(std::forward<A>(action))
			, m_tag(boost::uuids::random_generator()())
		{
		}

		template <typename T>
		void operator()(T&& newState) const
		{
			m_action(std::forward<T>(newState));
		}

	private:
		boost::uuids::uuid m_tag;
		Action m_action;
	};

	using ActionList = std::list<ActionWrapper>;

	static inline T s_currentState = T();
	static inline std::map<IEventInitiator*, ActionList> s_listeners{};
};

#endif // !EVENTHOLDER_HPP
