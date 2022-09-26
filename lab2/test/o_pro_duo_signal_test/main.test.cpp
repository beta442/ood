#define BOOST_TEST_MODULE Observer_with_signals_tests
#include <boost/test/included/unit_test.hpp>

#include "../../observer_pro_duo_signals/include/Observer.h"

 template <typename T = int>
 class TestingObservable : public Observer::Observable<T>
{
 public:
	using MyBase = Observer::Observable<T>;

	template <typename T>
	TestingObservable(T&& initialVal)
		: MyBase(std::forward<T>(initialVal))
	{
	}

	template <typename T>
	void Set(T&& newValue)
	{
		this->m_signallingValue.SetValue(std::forward<T>(newValue));
	}
 };

BOOST_AUTO_TEST_SUITE(ObserverWithSignalingValue)

	struct ValueWithoutCompareOp
	{
		ValueWithoutCompareOp(int holdingV)
			: holdingV(holdingV)
		{
		}

		int holdingV = 0;
	};

	BOOST_AUTO_TEST_CASE(SignallingValueHasntCompareOp)
	{
		int initialV = 10, newV = 10;
		TestingObservable<ValueWithoutCompareOp> oAble{ ValueWithoutCompareOp(initialV) };
		size_t emittingCount = 0;

		oAble.Connect([&](auto& oldV, auto& newV) noexcept { 
			++emittingCount;
		});
		oAble.Set(ValueWithoutCompareOp(newV));

		BOOST_CHECK(emittingCount == 1);
	}

	BOOST_AUTO_TEST_CASE(ObserverEmittingSignal)
	{
		int initV = 2, newV = 5;
		TestingObservable oAble(initV);

		oAble.Connect([&](auto& _oldV, auto& _newV) noexcept {
			BOOST_CHECK(_oldV == initV); BOOST_CHECK(newV == _newV);
		});
		oAble.Set(newV);
	}


	BOOST_AUTO_TEST_CASE(ObserverDoesntEmittingSignalAfterDisconnect)
	{
		int initV = 2, newV = 5;
		TestingObservable oAble(initV);
		size_t signalsAmount = 0;

		const auto& connection = oAble.Connect([&](auto& _oldV, auto& _newV) noexcept {
			BOOST_CHECK(_oldV == initV); BOOST_CHECK(newV == _newV);
			++signalsAmount;
		});

		oAble.Set(newV);
		connection.disconnect();
		oAble.Set(initV);

		BOOST_CHECK(signalsAmount == 1);
	}

	BOOST_AUTO_TEST_CASE(ObserverDoesntEmittingSignalIfNewValueIsSame)
	{
		int initV = 2;
		TestingObservable oAble(initV);
		size_t signalsAmount = 0;

		const auto& connection = oAble.Connect([&](auto& _oldV, auto& _newV) noexcept {
			++signalsAmount;
		});

		oAble.Set(initV);

		BOOST_CHECK(signalsAmount == 0);
	}

BOOST_AUTO_TEST_SUITE_END();
