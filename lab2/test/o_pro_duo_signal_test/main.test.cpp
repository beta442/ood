#define BOOST_TEST_MODULE Observer_with_signals_tests
#include <boost/test/included/unit_test.hpp>

#include "../../observer_pro_duo_signals/include/Observer.h"

// template <typename T = int>
// class TestingObservable : public Observer::Observable<T>
//{
// public:
//	using MyBase = Observer::Observable<T>;
//
//	template <typename T>
//	TestingObservable(T&& initialVal)
//		: MyBase(std::forward<T>(initialVal))
//	{
//	}
//
//	template <typename T>
//	void Set(T&& newValue)
//	{
//		this->m_signallingValue.SetValue(std::forward<T>(newValue));
//	}
// };

class TestingObservable : public Observer::Observable<int>
{
public:
	using MyBase = Observer::Observable<int>;

	TestingObservable(int initialVal)
		: MyBase(initialVal)
	{
	}

	void Set(int newValue)
	{
		m_signallingValue.SetValue(newValue);
	}
};

BOOST_AUTO_TEST_SUITE(SignallingValueHasntCompareOp)

	/*struct ValueWithoutCompareOp
	{
		ValueWithoutCompareOp(int holdingV)
			: holdingV(holdingV)
		{
		}

		int holdingV = 0;
	};

	BOOST_AUTO_TEST_CASE(TestingEmittingSignalOnNoChange)
	{
		int initialV = 10, newV = 10;
		TestingObservable<ValueWithoutCompareOp> oAble{ ValueWithoutCompareOp(initialV) };

		oAble.Connect([](auto& oldV, auto& newV) { BOOST_CHECK(oldV == newV); });
		oAble.Set(newV);
	}*/

BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(ObserverEmittingSignal)

	BOOST_AUTO_TEST_CASE(EmittingSignalTest)
	{
		const int initV = 2, newV = 5;
		TestingObservable oAble(initV);

		oAble.Connect([&](auto& _oldV, auto& _newV) { BOOST_CHECK(_oldV == initV); BOOST_CHECK(newV == _newV); });
		oAble.Set(newV);
	}

BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(ObserverDoesntEmittingSignalAfterDisconnect)

	BOOST_AUTO_TEST_CASE(StopEmittingSignalTest)
	{
		const int initV = 2, newV = 5;
		TestingObservable oAble(initV);
		size_t signalsAmount = 0;

		const auto& connection = oAble.Connect([&](auto& _oldV, auto& _newV) {
			BOOST_CHECK(_oldV == initV); BOOST_CHECK(newV == _newV);
			++signalsAmount;
		});

		oAble.Set(newV);
		connection.disconnect();
		oAble.Set(initV);

		BOOST_CHECK(signalsAmount == 1);
	}

BOOST_AUTO_TEST_SUITE_END();
