#ifndef OBSERVER_H
#define OBSERVER_H

#include <list>
#include <map>
#include <ranges>

template <typename T>
class IObserver
{
public:
	virtual void Update(const T& data) = 0;
	virtual ~IObserver() = default;
};

template <typename T>
class IPriorityObservable
{
public:
	virtual ~IPriorityObservable() = default;
	virtual void RegisterObserver(std::size_t priority, IObserver<T>& observer) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(std::size_t priority, IObserver<T>& observer) = 0;
};

template <typename T>
class Observable : public IPriorityObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(std::size_t priority, ObserverType& observer) override
	{
		if (!m_prioritizedObservers.contains(priority))
		{
			m_prioritizedObservers[priority] = ObserverList();
		}
		m_prioritizedObservers[priority].push_back(&observer);
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();
		for (auto& [priority, observers] : std::ranges::views::reverse(m_prioritizedObservers))
		{
			for (auto& observer : observers)
			{
				observer->Update(data);
			}
		}
	}

	void RemoveObserver(std::size_t priority, ObserverType& observer) override
	{
		if (!m_prioritizedObservers.contains(priority))
		{
			return;
		}
		m_prioritizedObservers[priority].remove(&observer);
	}

protected:
	virtual T GetChangedData() const = 0;

private:
	using ObserverList = std::list<ObserverType*>;
	using PrioritizedObserverMap = std::map<std::size_t, ObserverList>;

	PrioritizedObserverMap m_prioritizedObservers;
};

#endif // !OBSERVER_H
