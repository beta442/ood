#include "include/pch.h"

#include "include/ObserverSafeUpdate.h"

BOOST_AUTO_TEST_SUITE(ObserverSafeUpdate);

BOOST_AUTO_TEST_CASE(UnsafeDeleteObserverTest)
{
	TestingObservableSafeUpdate oAble{};

	TestingObserverSafeUpdate o1{ [] { BOOST_TEST(1 == 1); } }, o2{ [] { BOOST_TEST(1 == 1); } };

	oAble.RegisterObserver(o1);
	oAble.RegisterObserver(o2);

	oAble.NotifyObservers();
}

BOOST_AUTO_TEST_SUITE_END();
