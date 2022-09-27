#ifndef OBSERVER_H
#define OBSERVER_H

#include <functional>
#include <set>

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
	virtual void RegisterObserver(IObserver<T>& observer) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T>& observer) = 0;
};

template <typename T>
class Observable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType& observer) final
	{
		m_observers.insert(&observer);
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();

		auto oCopy = m_observers;
		for (auto& o : oCopy)
		{
			o->Update(data, *this);
		}
	}

	void RemoveObserver(ObserverType& observer) final
	{
		if (auto findIt = m_observers.find(&observer); findIt != m_observers.end())
		{
			m_observers.erase(findIt);
		}
	}

protected:
	virtual T GetChangedData() const = 0;

private:
	std::set<ObserverType*> m_observers;
};

#endif // !OBSERVER_H
