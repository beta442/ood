#ifndef EVENTHOLDER_HPP
#define EVENTHOLDER_HPP

#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid.hpp>

#include <functional>
#include <list>

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

template <typename T>
class EventHolder
{
public:
	using Action = std::function<void(T&)>;
	class ActionWrapper;

	template <typename OnChange = Action>
	static Unsubscriber AddListener(OnChange&& listener, bool instantNotify = false)
	{
		auto actionWrapper = ActionWrapper(std::forward<OnChange>(listener));
		s_listeners.push_back(actionWrapper);

		if (instantNotify)
		{
			listener(s_currentState);
		}

		return [aW = actionWrapper]() {
			RemoveListener(aW);
		};
	}

	template <typename T>
	static void NotifyListeners(T&& newState)
	{
		if constexpr (value_detail::EqualExists<T>::value)
		{
			if (s_currentState == newState)
			{
				return;
			}
		}

		s_currentState = std::forward<T>(newState);

		auto lCopy = s_listeners;
		for (auto& listener : lCopy)
		{
			listener(s_currentState);
		}
	}

private:
	static void RemoveListener(const ActionWrapper& listener)
	{
		s_listeners.remove(listener);
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

	static inline T s_currentState = T();
	static inline std::list<ActionWrapper> s_listeners{};
};

#endif // !EVENTHOLDER_HPP
