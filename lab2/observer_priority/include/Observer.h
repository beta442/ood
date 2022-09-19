#ifndef OBSERVER_H
#define OBSERVER_H

#include <functional>
#include <map>

template <typename T>
class IObservable;

template <typename T>
class IObserver
{
public:
	virtual void Update(const T& data, IObservable<T>& updateSource) = 0;
	virtual ~IObserver() = default;
};

template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(std::size_t priority, IObserver<T>& observer) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T>& observer) = 0;
};

template <typename Map, typename F>
static const void MapEraseIf(Map& m, F pred)
{
	for (typename Map::iterator i = m.begin(), end = m.end(); (i = std::find_if(i, end, pred)) != end; m.erase(i++));
}

template <typename T, typename Comp = std::greater<std::size_t>>
class PrioritizedObservable : public IObservable<T>
{
public:
	using ObserverType = IObserver<T>;

	void RegisterObserver(std::size_t priority, ObserverType& observer) final
	{
		RemoveObserver(observer);
		m_prioritizedObservers.emplace(priority, &observer);
	}

	void NotifyObservers() final
	{
		T data = GetChangedData();

		for (auto it = std::begin(m_prioritizedObservers), end = std::end(m_prioritizedObservers); it != end;)
		{
			auto slowIt = it;
			auto& [_, observerPtr] = *it;
			++it;
			observerPtr->Update(data, *this);
		}
	}

	void RemoveObserver(ObserverType& observer) final
	{
		MapEraseIf(m_prioritizedObservers, [&](auto& p) { return p.second == &observer; });
	}

protected:
	virtual T GetChangedData() const = 0;

private:
	using PrioritizedObserverMultiMap = std::multimap<std::size_t, ObserverType*, Comp>;

	PrioritizedObserverMultiMap m_prioritizedObservers;
};

#endif // !OBSERVER_H
