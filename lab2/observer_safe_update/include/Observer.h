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
		bool eraseRes = (m_observables.erase(&observable) == 1);
		return eraseRes ? observable.RemoveObserver(*this) : eraseRes;
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

		for (auto& observer : m_observers)
		{
			observer->Update(data);
		}
	}

	bool RemoveObserver(ObserverType& observer) final
	{
		bool eraseRes = (m_observers.erase(&observer) == 1);
		return eraseRes ? observer.RemoveObservable(*this) : eraseRes;
	}

protected:
	virtual T GetChangedData() const = 0;

private:
	std::set<ObserverType*> m_observers;
};

#endif // !OBSERVER_H
