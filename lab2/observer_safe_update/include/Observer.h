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
	virtual bool RegisterObservable(IObservable<T>& observable) = 0;
	virtual bool RemoveObservable(IObservable<T>& observable) = 0;
	virtual void Update(const T& data) = 0;
	virtual ~IObserver() = default;
};

template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual bool RegisterObserver(IObserver<T>& observer) = 0;
	virtual void NotifyObservers() = 0;
	virtual bool RemoveObserver(IObserver<T>& observer) = 0;
};

template <typename T>
class AbstractObserver : public IObserver<T>
{
protected:
	using Observable = IObservable<T>;

	AbstractObserver() = default;

	bool RegisterObservable(Observable& observable) final
	{
		bool insertionResult = m_observables.insert(&observable).second;
		return insertionResult ? observable.RegisterObserver(*this) : insertionResult;
	}

	bool RemoveObservable(Observable& observable) final
	{
		if (auto findIt = m_observables.find(&observable); findIt != m_observables.end())
		{
			m_observables.erase(findIt);
			observable.RemoveObserver(*this);
			return true;
		}
		return false;
	}

	std::set<Observable*> m_observables;
};

template <typename T>
class Observable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	bool RegisterObserver(ObserverType& observer) final
	{
		bool insertionResult = m_observers.insert(&observer).second;
		return insertionResult ? observer.RegisterObservable(*this) : insertionResult;
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();

		auto copyO = m_observers; // Update() may change m_observers
		for (auto& observer : copyO)
		{
			observer->Update(data);
		}
	}

	bool RemoveObserver(ObserverType& observer) final
	{
		if (auto findIt = m_observers.find(&observer); findIt != m_observers.end())
		{
			m_observers.erase(findIt);
			observer.RemoveObservable(*this);
			return true;
		}
		return false;
	}

protected:
	virtual T GetChangedData() const = 0;

private:
	std::set<ObserverType*> m_observers;
};

#endif // !OBSERVER_H
