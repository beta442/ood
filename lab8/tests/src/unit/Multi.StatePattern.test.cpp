#include "pch.h"

#include "../../src/gumball_machine/CGumballMachine/multi/MultiGumballMachine.h"

#include "../../src/gumball_machine/Description.h"
#include "../../src/gumball_machine/state/CState/msg/all.h"
#include "../../src/gumball_machine/state/CState/msg/common.h"
#include "../../src/gumball_machine/state/CState/multi/msg/all.h"

static inline std::string GetMachineDescription(size_t gumCount, const std::string& stateDescription, size_t quartersCount)
{
	auto fmt = boost::format(gumball_machine::dscrp::BOOST_FORMAT_MACHINE_WITH_STATE_DSCRP);
	return (fmt % "multi" % gumCount % (gumCount != 1 ? "s" : "") % quartersCount % (quartersCount != 1 ? "s" : "") % stateDescription).str();
}

static inline std::string Repeat(const std::string& src, size_t times)
{
	std::ostringstream repeated;
	std::fill_n(std::ostream_iterator<std::string>(repeated), times, src);
	return repeated.str();
}

struct GMWith_1_MaxQuartersInHoldWith_3_GumballsFx
{
	GMWith_1_MaxQuartersInHoldWith_3_GumballsFx()
		: oTestStream()
		, gMachine(MAX_QUARTERS_IN_HOLD, INITIAL_GUMBALLS_COUNT, oTestStream)
	{
	}

	const size_t INITIAL_GUMBALLS_COUNT = 3;
	const size_t MAX_QUARTERS_IN_HOLD = 1;

	std::stringstream oTestStream;
	gumball_machine::multi::GumballMachine gMachine;
};

struct GMWith_4_MaxQuartersInHoldWith_3_GumballsFx
{
	GMWith_4_MaxQuartersInHoldWith_3_GumballsFx()
		: oTestStream()
		, gMachine(MAX_QUARTERS_IN_HOLD, INITIAL_GUMBALLS_COUNT, oTestStream)
	{
	}

	const size_t INITIAL_GUMBALLS_COUNT = 3;
	const size_t MAX_QUARTERS_IN_HOLD = 4;

	std::stringstream oTestStream;
	gumball_machine::multi::GumballMachine gMachine;
};

namespace states_msgs = gumball_machine::state::msg;
namespace states_multi_msg = gumball_machine::state::multi::msg;

BOOST_AUTO_TEST_SUITE(Test_suite_gumball_machine_with_multi_quarters)

	BOOST_AUTO_TEST_CASE(Test_create_machine_with_0_max_quarters_in_hold_throws)
	{
		BOOST_CHECK_THROW(gumball_machine::multi::GumballMachine(0, 1, std::cout), std::invalid_argument);
	}

	BOOST_FIXTURE_TEST_CASE(Test_initial_info, GMWith_1_MaxQuartersInHoldWith_3_GumballsFx)
	{
		const auto expectedMachineDscrp = GetMachineDescription(INITIAL_GUMBALLS_COUNT, states_msgs::no_quarter::STATE_DSCRP_MSG, gMachine.GetQuarterCount());

		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedMachineDscrp, oTestStream.str());
		BOOST_CHECK_EQUAL(INITIAL_GUMBALLS_COUNT, gMachine.GetBallCount());
		BOOST_CHECK_EQUAL(MAX_QUARTERS_IN_HOLD, gMachine.GetMaxQuarterCount());
		BOOST_CHECK_EQUAL(0, gMachine.GetQuarterCount());
	}

	BOOST_FIXTURE_TEST_CASE(Test_eject_on_init, GMWith_1_MaxQuartersInHoldWith_3_GumballsFx)
	{
		// clang-format off
		const auto expectedMachineDscrp = std::string(states_msgs::no_quarter::EJECT_MSG) +
			GetMachineDescription(INITIAL_GUMBALLS_COUNT, states_msgs::no_quarter::STATE_DSCRP_MSG, gMachine.GetQuarterCount());
		// clang-format on

		gMachine.EjectQuarter();
		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedMachineDscrp, oTestStream.str());
	}

	BOOST_FIXTURE_TEST_CASE(Test_turn_crank_on_init, GMWith_1_MaxQuartersInHoldWith_3_GumballsFx)
	{
		// clang-format off
		const auto expectedMachineDscrp = std::string(states_msgs::no_quarter::TURN_CRANK_MSG) +
			states_msgs::no_quarter::DISPENSE_MSG +
			GetMachineDescription(INITIAL_GUMBALLS_COUNT, states_msgs::no_quarter::STATE_DSCRP_MSG, gMachine.GetQuarterCount());
		// clang-format on

		gMachine.TurnCrank();
		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedMachineDscrp, oTestStream.str());
	}

	BOOST_FIXTURE_TEST_CASE(Test_insert_on_init, GMWith_1_MaxQuartersInHoldWith_3_GumballsFx)
	{
		// clang-format off
		const auto expectedMachineDscrp = std::string(states_msgs::no_quarter::INSERT_MSG) +
			GetMachineDescription(INITIAL_GUMBALLS_COUNT, (boost::format(states_multi_msg::has_quarter::STATE_DSCRP_MSG) % 1 % "").str(), 1);
		// clang-format on

		gMachine.InsertQuarter();
		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedMachineDscrp, oTestStream.str());
	}

	BOOST_FIXTURE_TEST_CASE(Test_insert_till_cap_reached, GMWith_1_MaxQuartersInHoldWith_3_GumballsFx)
	{
		const size_t expectedQuartersCount = 1;
		// clang-format off
		const auto expectedMachineDscrp = std::string(states_msgs::no_quarter::INSERT_MSG) +
			(boost::format(states_multi_msg::has_quarter::INSERT_AT_MAX_MSG) % expectedQuartersCount % "").str() +
			GetMachineDescription(INITIAL_GUMBALLS_COUNT, (boost::format(states_multi_msg::has_quarter::STATE_DSCRP_MSG) % expectedQuartersCount % "").str(), expectedQuartersCount);
		// clang-format on

		for (size_t i = 0; i <= MAX_QUARTERS_IN_HOLD; ++i)
		{
			gMachine.InsertQuarter();
		}
		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedMachineDscrp, oTestStream.str());
		BOOST_CHECK_EQUAL(expectedQuartersCount, gMachine.GetQuarterCount());
	}

	BOOST_FIXTURE_TEST_CASE(Test_insert_then_eject, GMWith_1_MaxQuartersInHoldWith_3_GumballsFx)
	{
		const size_t expectedQuartersCount = 0;
		// clang-format off
		const auto expectedMachineDscrp = std::string(states_msgs::no_quarter::INSERT_MSG) +
			(boost::format(states_multi_msg::has_quarter::EJECT_MSG) % (expectedQuartersCount + 1) % (((expectedQuartersCount + 1) != 1) ? "s" : "")).str() +
			GetMachineDescription(INITIAL_GUMBALLS_COUNT, states_msgs::no_quarter::STATE_DSCRP_MSG, expectedQuartersCount);
		// clang-format on

		gMachine.InsertQuarter();
		gMachine.EjectQuarter();
		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedMachineDscrp, oTestStream.str());
		BOOST_CHECK_EQUAL(expectedQuartersCount, gMachine.GetQuarterCount());
	}

	BOOST_FIXTURE_TEST_CASE(Test_insert_till_cap_reached_then_crank_till_empty_on_gums, GMWith_4_MaxQuartersInHoldWith_3_GumballsFx)
	{
		const size_t expectedQuartersCount = 1, expectedGumballs = 0;
		// clang-format off
		const auto expectedMachineDscrp = std::string(states_msgs::no_quarter::INSERT_MSG) +
			Repeat(states_multi_msg::has_quarter::INSERT_MSG, (4 - 1)) +
			Repeat(std::string(states_multi_msg::has_quarter::TURN_CRANK_MSG) + states_msgs::sold::DISPENSE_MSG, (gMachine.GetBallCount() - expectedGumballs)) +
			GetMachineDescription(expectedGumballs, states_multi_msg::sold_out::STATE_DSCRP_MSG, expectedQuartersCount);
		// clang-format on

		for (size_t i = 0; i < MAX_QUARTERS_IN_HOLD; ++i)
		{
			gMachine.InsertQuarter();
		}
		for (size_t i = 0, total = INITIAL_GUMBALLS_COUNT; i < total; ++i)
		{
			gMachine.TurnCrank();
		}
		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedMachineDscrp, oTestStream.str());
		BOOST_CHECK_EQUAL(expectedQuartersCount, gMachine.GetQuarterCount());
	}

	BOOST_FIXTURE_TEST_CASE(Test_refill, GMWith_4_MaxQuartersInHoldWith_3_GumballsFx)
	{
		const size_t expectedQuartersCount = 0, expectedGumballs = 3;
		// clang-format off
		const std::string _1Iteration = std::string(states_msgs::no_quarter::INSERT_MSG) +
			Repeat(states_multi_msg::has_quarter::INSERT_MSG, 2) +
			Repeat(std::string(states_multi_msg::has_quarter::TURN_CRANK_MSG) + states_msgs::sold::DISPENSE_MSG, expectedGumballs) +
			(boost::format(gumball_machine::state::msg::common::REFILL_MSG) % gMachine.GetBallCount() % ((gMachine.GetBallCount() != 1) ? "s" : "")).str() +
			GetMachineDescription(gMachine.GetBallCount(), states_msgs::no_quarter::STATE_DSCRP_MSG, expectedQuartersCount);
		const auto expectedMachineDscrp = Repeat(_1Iteration, 2);
		// clang-format on

		for (size_t j = 0; j < 2; ++j)
		{
			for (size_t i = 1; i < MAX_QUARTERS_IN_HOLD; ++i)
			{
				gMachine.InsertQuarter();
			}
			for (size_t i = 0, total = INITIAL_GUMBALLS_COUNT; i < total; ++i)
			{
				gMachine.TurnCrank();
			}
			gMachine.RefillBalls(3);
			oTestStream << gMachine.Description();
		}

		BOOST_CHECK_EQUAL(expectedMachineDscrp, oTestStream.str());
		BOOST_CHECK_EQUAL(expectedQuartersCount, gMachine.GetQuarterCount());
		BOOST_CHECK_EQUAL(expectedGumballs, gMachine.GetBallCount());
	}

BOOST_AUTO_TEST_SUITE_END()
