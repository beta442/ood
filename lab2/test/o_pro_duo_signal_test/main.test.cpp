#define BOOST_TEST_MODULE Observer_with_signals_tests
#include <boost/test/included/unit_test.hpp>

#include "../../observer_pro_duo_signals/include/SignallingValue.hpp"

struct ValueWithoutCompareOp
{
	ValueWithoutCompareOp(int holdingV)
		: holdingV(holdingV)
	{
	}

	int holdingV = 0;
};

template <typename T = int>
class TestingObservable
{
public:
	template <typename T>
	TestingObservable(T&& initialVal)
		: m_signal(std::forward<T>(initialVal))
	{
	}

	template <typename T>
	void Set(T&& newValue)
	{
		m_signal.SetValue(std::forward<T>(newValue));
	}

	template <typename OnChange>
	Signal::Connection OnChange(OnChange&& onChange)
	{
		return m_signal.Connect(std::forward<OnChange>(onChange));
	}

private:
	Signal::SignallingValue<T> m_signal;
};

BOOST_AUTO_TEST_SUITE(ObserverWithSignalingValue)

	BOOST_AUTO_TEST_CASE(SignallingValueHasntCompareOp)
	{
		const int initialV = 10, newV = 10;
		TestingObservable<ValueWithoutCompareOp> oAble{ ValueWithoutCompareOp(initialV) };
		size_t emittingCount = 0;

		oAble.OnChange([&](auto& oldV, auto& newV) noexcept {
			++emittingCount;
		});
		oAble.Set(ValueWithoutCompareOp(newV));

		BOOST_CHECK(emittingCount == 1);
	}

	BOOST_AUTO_TEST_CASE(ObserverEmittingSignal)
	{
		const int initV = 2, newV = 5;
		TestingObservable oAble(initV);

		oAble.OnChange([&](auto& _oldV, auto& _newV) noexcept {
			BOOST_CHECK(_oldV == initV);
			BOOST_CHECK(newV == _newV);
		});
		oAble.Set(newV);
	}

	BOOST_AUTO_TEST_CASE(ObserverDoesntEmittingSignalAfterDisconnect)
	{
		const int initV = 2, newV = 5;
		TestingObservable oAble(initV);
		size_t signalsAmount = 0;

		const auto& connection = oAble.OnChange([&](auto& _oldV, auto& _newV) noexcept {
			BOOST_CHECK(_oldV == initV);
			BOOST_CHECK(newV == _newV);
			++signalsAmount;
		});

		oAble.Set(newV);
		connection.disconnect();
		oAble.Set(initV);

		BOOST_CHECK(signalsAmount == 1);
	}

	BOOST_AUTO_TEST_CASE(ObserverDoesntEmittingSignalIfNewValueIsSame)
	{
		const int value = 2;
		TestingObservable oAble(value);
		size_t signalsAmount = 0;

		const auto& connection = oAble.OnChange([&](auto& _oldV, auto& _newV) noexcept {
			++signalsAmount;
		});

		oAble.Set(value);

		BOOST_CHECK(signalsAmount == 0);
	}

BOOST_AUTO_TEST_SUITE_END();
