#include "include/pch.h"

#include "../../observer_duo/include/Observer.h"

using Data = int;

class TestObservable : public Observable<Data>
{
public:
	TestObservable() = default;

private:
	Data GetChangedData() const override
	{
		return m_data;
	}

	Data m_data;
};

class TestObserver : public AbstractObserver<Data>
{
public:
	size_t GetLastInitiatorIndex()
	{
		return m_lastInitiatorIndex;
	}

private:
	void Update(const Data& data, IObservable<Data>& updateInitiator) override
	{
		if (const auto it = m_observables.find(&updateInitiator); it != std::end(m_observables))
		{
			m_lastInitiatorIndex = std::distance(std::begin(m_observables), it);
		}
	}

	size_t m_lastInitiatorIndex;
};

BOOST_AUTO_TEST_SUITE(ObserverDuo);

BOOST_AUTO_TEST_CASE(ObserverKnowsUpdateInitiator)
{
	TestObservable oAble1, oAble2, oAble3;
	TestObserver o;

	oAble1.RegisterObserver(o);
	oAble2.RegisterObserver(o);
	oAble3.RegisterObserver(o);

	oAble2.NotifyObservers();
	BOOST_TEST(o.GetLastInitiatorIndex() == 1);

	oAble1.NotifyObservers();
	BOOST_TEST(o.GetLastInitiatorIndex() == 0);

	oAble3.NotifyObservers();
	BOOST_TEST(o.GetLastInitiatorIndex() == 2);
}

BOOST_AUTO_TEST_SUITE_END();
