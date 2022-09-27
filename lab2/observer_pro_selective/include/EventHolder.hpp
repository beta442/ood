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
