#include "include/pch.h"

#include "../../observer_duo/include/Observer.h"

using Data = int;

class TestObservable : public Observable<Data>
{
public:
	TestObservable()
		: m_data()
	{
	}

private:
	Data GetChangedData() const override
	{
		return m_data;
	}

	Data m_data;
};

class TestObserver : public IObserver<Data>
{
public:
	TestObserver(const TestObservable& oAble1, const TestObservable& oAble2, const TestObservable& oAble3)
		: m_oAble1(&oAble1)
		, m_oAble2(&oAble2)
		, m_oAble3(&oAble3)
	{
	}

	size_t GetLastInitiatorIndex()
	{
		return m_lastInitiatorIndex;
	}

private:
	using ObservableType = const TestObservable*;

	void Update(const Data& data, IObservable<Data>& updateInitiator) override
	{
		m_lastInitiatorIndex = (&updateInitiator == m_oAble1)
			? 1
			: (&updateInitiator == m_oAble2)
			? 2
			: (&updateInitiator == m_oAble3)
			? 3
			: 0;
	}

	size_t m_lastInitiatorIndex;
	ObservableType m_oAble1, m_oAble2, m_oAble3;
};

BOOST_AUTO_TEST_SUITE(ObserverDuo)

	BOOST_AUTO_TEST_CASE(ObserverKnowsUpdateInitiator)
	{
		TestObservable oAble1, oAble2, oAble3;
		TestObserver o{ oAble1, oAble2, oAble3 };

		oAble1.RegisterObserver(o);
		oAble2.RegisterObserver(o);
		oAble3.RegisterObserver(o);

		oAble2.NotifyObservers();
		BOOST_TEST(o.GetLastInitiatorIndex() == 2);

		oAble1.NotifyObservers();
		BOOST_TEST(o.GetLastInitiatorIndex() == 1);

		oAble3.NotifyObservers();
		BOOST_TEST(o.GetLastInitiatorIndex() == 3);
	}

BOOST_AUTO_TEST_SUITE_END();
