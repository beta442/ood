#ifndef OBSERVERSAFEUPDATE_H
#define OBSERVERSAFEUPDATE_H

#include <functional>

#include "../../observer_safe_update/include/Observer.h"

using Data = int;

class TestingObservableSafeUpdate : public Observable<Data>
{
public:
	TestingObservableSafeUpdate()
		: m_data()
	{
	}

protected:
	Data GetChangedData() const override
	{
		return m_data;
	}

private:
	Data m_data;
};

class TestingObserverSafeUpdate : public IObserver<Data>
{
public:
	using OnUpdateEvent = std::function<void()>;

	TestingObserverSafeUpdate(const OnUpdateEvent& e)
		: m_event(e)
	{
	}

private:
	void Update(const Data& data, IObservable<Data>& updateSource) override
	{
		updateSource.RemoveObserver(*this);
		m_event();
	}

	OnUpdateEvent m_event;
};

#endif // !OBSERVERSAFEUPDATE_H
