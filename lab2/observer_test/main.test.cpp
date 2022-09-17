#include "include/pch.h"

#include "include/ObserverPriority.h"

BOOST_AUTO_TEST_SUITE(ObserverPriority);
BOOST_AUTO_TEST_CASE(UpdateObserversInNormalOrder)
{
	ValidatePriorityOrder<std::greater<size_t>>(CompareResult::GREATER);
}

BOOST_AUTO_TEST_CASE(UpdateObserversInReversedOrder)
{
	ValidatePriorityOrder<std::less<size_t>>(CompareResult::LESS);
}

BOOST_AUTO_TEST_CASE(UpdateObserversWithEqualPriority)
{
	ValidatePriorityOrder<std::greater<size_t>>(CompareResult::EQUAL, 0);
}

BOOST_AUTO_TEST_SUITE_END();
