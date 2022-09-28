#ifndef EVENTHOLDER_HPP
#define EVENTHOLDER_HPP

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

template <typename T>
class EventHolder
{
public:
	using Action = std::function<void(T&)>;

	template <typename OnChange = Action>
	static void AddListener(OnChange&& listener, bool instantNotify = false)
	{
		s_listeners.emplace_back(std::forward<OnChange>(listener));
		if (instantNotify)
		{
			listener(s_currentState);
		}
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

	template <typename OnChange = Action>
	static void RemoveListener(OnChange&& listener)
	{
		s_listeners.remove(std::forward<OnChange>(listener));
	}

private:
	static inline T s_currentState = T();

	static inline std::list<Action> s_listeners{};
};

#endif // !EVENTHOLDER_HPP
