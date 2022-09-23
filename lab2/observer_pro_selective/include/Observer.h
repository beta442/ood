#ifndef OBSERVER_H
#define OBSERVER_H

#include <set>
#include <map>
#include <string>

class Event
{
public:
	template <typename EventName = std::string>
	Event(EventName&& name)
		: m_eventType(std::forward<EventName>(name))
	{
	}

	friend bool operator==(const Event& lhs, const Event& rhs)
	{
		return lhs.m_eventType == rhs.m_eventType;
	}

	friend bool operator<(const Event& lhs, const Event& rhs)
	{
		return lhs.m_eventType < rhs.m_eventType;
	}

protected:
	std::string m_eventType;
};

template <typename T>
class IObservable;

template <typename T>
class IObserver
{
public:
	virtual void Update(const T& data, const IObservable<T>& updateSource) = 0;
	virtual ~IObserver() = default;
};

template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T>& observer, const Event& updateEvent) = 0;
	virtual void NotifyObservers(const Event& updateEvent) = 0;
	virtual void RemoveObserver(IObserver<T>& observer) = 0;
	virtual void RemoveObserver(IObserver<T>& observer, const Event& updateEvent) = 0;
};

template <typename T>
class Observable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType& observer, const Event& updateEvent = "OnUpdate") final
	{
		if (m_eventToObserversMap.find(updateEvent) == std::end(m_eventToObserversMap))
		{
			m_eventToObserversMap.emplace(updateEvent, ObserverSet());
		}
		m_eventToObserversMap[updateEvent].emplace(&observer);
	}

	void NotifyObservers(const Event& updateEvent) final
	{
		auto data = GetChangedData();
		for (auto& [_updateEvent, _observers] : m_eventToObserversMap)
		{
			if (_updateEvent == updateEvent)
			{
				for (auto it = std::begin(_observers), end = std::end(_observers); it != end;)
				{
					auto slowIt = it;
					++it;
					(*slowIt)->Update(data, *this);
				}
			}
		}
	}

	void RemoveObserver(ObserverType& observer) final
	{
		for (auto& [_, _observers] : m_eventToObserversMap)
		{
			_observers.erase(&observer);
		}
	}

	void RemoveObserver(ObserverType& observer, const Event& updateEvent) final
	{
		for (auto& [_event, _observers] : m_eventToObserversMap)
		{
			if (_event == updateEvent)
			{
				_observers.erase(&observer);
			}
		}
	}

protected:
	virtual T GetChangedData() const = 0;

private:
	using ObserverSet = std::set<ObserverType*>;

	std::map<Event, ObserverSet> m_eventToObserversMap;
};

#endif // !OBSERVER_H
