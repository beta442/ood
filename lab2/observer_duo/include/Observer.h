#ifndef OBSERVER_H
#define OBSERVER_H

#include <set>

template <typename T>
class IObservable;

template <typename T>
class IObserver
{
public:
	virtual void Update(const T& data, IObservable<T>& updateInitiator) = 0;
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

		for (auto it = std::begin(m_observers), end = std::end(m_observers); it != end;)
		{
			auto slowIt = it;
			++it;
			(*slowIt)->Update(data, *this);
		}
	}

	void RemoveObserver(ObserverType& observer) final
	{
		m_observers.erase(&observer);
	}

protected:
	virtual T GetChangedData() const = 0;

private:
	std::set<ObserverType*> m_observers;
};

#endif // !OBSERVER_H
