#ifndef OBSERVER_H
#define OBSERVER_H

#include <functional>
#include <list>

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
		m_observables.emplace_back(&observable);
		bool insertionResult = (m_observables.unique() != 0); 
		return insertionResult ? observable.RegisterObserver(*this) : insertionResult;
	}

	bool RemoveObservable(Observable& observable) final
	{
		bool eraseRes = (m_observables.remove(&observable) == 1);
		return eraseRes ? observable.RemoveObserver(*this) : eraseRes;
	}

	std::list<Observable*> m_observables;
};

template <typename T>
class Observable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	bool RegisterObserver(ObserverType& observer) final
	{
		m_observers.emplace_back(&observer);
		bool insertionResult = (m_observers.unique() != 0); 
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
		bool eraseRes = (m_observers.remove(&observer) == 1);
		return eraseRes ? observer.RemoveObservable(*this) : eraseRes;
	}

protected:
	virtual T GetChangedData() const = 0;

private:
	std::list<ObserverType*> m_observers;
};

#endif // !OBSERVER_H
