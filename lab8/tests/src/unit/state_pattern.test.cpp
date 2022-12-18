#include "pch.h"

#include "../../src/gumball_machine/Description.h"
#include "../../src/gumball_machine/state/CState/msg/all.h"

#include "../../src/gumball_machine/CGumballMachine/GumballMachine.h"

#include "../../src/gumball_machine/state/CState/NoQuarterState.h"

struct GMWith10GumballsFx
{
	GMWith10GumballsFx()
		: oTestStream()
		, gMachine(INITIAL_GUMBALLS_COUNT, oTestStream)
	{
	}

	const size_t INITIAL_GUMBALLS_COUNT = 4;

	std::stringstream oTestStream;
	gumball_machine::GumballMachine gMachine;
};

struct GMWith0GumballsFx
{
	GMWith0GumballsFx()
		: oTestStream()
		, gMachine(INITIAL_GUMBALLS_COUNT, oTestStream)
	{
	}

	const size_t INITIAL_GUMBALLS_COUNT = 0;

	std::stringstream oTestStream;
	gumball_machine::GumballMachine gMachine;
};

std::string GetMachineDescription(size_t gumCount, const std::string& stateDescription)
{
	auto fmt = boost::format(gumball_machine::dscrp::BOOST_FORMAT_MACHINE_WITH_STATE_DSCRP);
	return (fmt % "dynamic" % gumCount % (gumCount != 1 ? "s" : "") % stateDescription).str();
}

std::string Repeat(const std::string& src, size_t times)
{
	std::ostringstream repeated;
	std::fill_n(std::ostream_iterator<std::string>(repeated), times, src);
	return repeated.str();
}

namespace states_msgs = gumball_machine::state::msg;

BOOST_AUTO_TEST_SUITE(Test_gumball_machine_state_pattern)

	BOOST_FIXTURE_TEST_CASE(Test_initial_info, GMWith10GumballsFx)
	{
		oTestStream << gMachine.Description();
		auto machineDscrp = GetMachineDescription(INITIAL_GUMBALLS_COUNT, states_msgs::no_quarter::STATE_DSCRP_MSG);

		BOOST_CHECK_EQUAL(oTestStream.str(), machineDscrp);
	}

	BOOST_FIXTURE_TEST_CASE(Test_eject_quarter_at_init, GMWith10GumballsFx)
	{
		gMachine.EjectQuarter();

		BOOST_CHECK_EQUAL(states_msgs::no_quarter::EJECT_MSG, oTestStream.str());
	}

	BOOST_FIXTURE_TEST_CASE(Test_ball_count_on_init, GMWith10GumballsFx)
	{
		BOOST_CHECK_EQUAL(gMachine.GetBallCount(), INITIAL_GUMBALLS_COUNT);
	}

	BOOST_FIXTURE_TEST_CASE(Test_turn_crank_on_init, GMWith10GumballsFx)
	{
		using namespace states_msgs::no_quarter;
		const auto expectedOutput = std::string(TURN_CRANK_MSG) + DISPENSE_MSG;

		gMachine.TurnCrank();

		BOOST_CHECK_EQUAL(expectedOutput, oTestStream.str());
	}

	BOOST_FIXTURE_TEST_CASE(Test_insert_quarter, GMWith10GumballsFx)
	{
		// clang-format off
		const auto expectedOutput = std::string(states_msgs::no_quarter::INSERT_MSG) +
			GetMachineDescription(INITIAL_GUMBALLS_COUNT, states_msgs::has_quarter::STATE_DSCRP_MSG);
		// clang-format on

		gMachine.InsertQuarter();
		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedOutput, oTestStream.str());
	}

	BOOST_FIXTURE_TEST_CASE(Test_insert_quarter_twice, GMWith10GumballsFx)
	{
		// clang-format off
		const auto expectedOutput = std::string(states_msgs::no_quarter::INSERT_MSG) +
			states_msgs::has_quarter::INSERT_MSG +
			GetMachineDescription(INITIAL_GUMBALLS_COUNT, states_msgs::has_quarter::STATE_DSCRP_MSG);
		// clang-format on

		gMachine.InsertQuarter();
		gMachine.InsertQuarter();
		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedOutput, oTestStream.str());
	}

	BOOST_FIXTURE_TEST_CASE(Test_eject_quarter_after_inserting, GMWith10GumballsFx)
	{
		// clang-format off
		const auto expectedOutput = std::string(states_msgs::no_quarter::INSERT_MSG) +
			states_msgs::has_quarter::EJECT_MSG +
			GetMachineDescription(INITIAL_GUMBALLS_COUNT, states_msgs::no_quarter::STATE_DSCRP_MSG);
		// clang-format on

		gMachine.InsertQuarter();
		gMachine.EjectQuarter();
		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedOutput, oTestStream.str());
	}

	BOOST_FIXTURE_TEST_CASE(Test_sell_ball, GMWith10GumballsFx)
	{
		const auto expectedBallCount = INITIAL_GUMBALLS_COUNT - 1;
		// clang-format off
		const auto expectedOutput = std::string(states_msgs::no_quarter::INSERT_MSG) +
			states_msgs::has_quarter::TURN_CRANK_MSG +
			states_msgs::sold::DISPENSE_MSG +
			GetMachineDescription(expectedBallCount, states_msgs::no_quarter::STATE_DSCRP_MSG);
		// clang-format on

		gMachine.InsertQuarter();
		gMachine.TurnCrank();
		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedBallCount, gMachine.GetBallCount());
		BOOST_CHECK_EQUAL(expectedOutput, oTestStream.str());
	}

	BOOST_FIXTURE_TEST_CASE(Test_try_sell_when_empty, GMWith0GumballsFx)
	{
		const auto expectedBallCount = 0;
		// clang-format off
		const auto expectedOutput = std::string(states_msgs::sold_out::INSERT_MSG) +
				states_msgs::sold_out::TURN_CRANK_MSG +
				states_msgs::sold_out::DISPENSE_MSG +
				GetMachineDescription(expectedBallCount, states_msgs::sold_out::STATE_DSCRP_MSG);
		// clang-format on

		gMachine.InsertQuarter();
		gMachine.TurnCrank();
		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedBallCount, gMachine.GetBallCount());
		BOOST_CHECK_EQUAL(expectedOutput, oTestStream.str());
	}

	BOOST_FIXTURE_TEST_CASE(Test_try_insert_when_empty, GMWith0GumballsFx)
	{
		const auto expectedBallCount = 0;
		// clang-format off
		const auto expectedOutput = std::string(states_msgs::sold_out::INSERT_MSG) +
				GetMachineDescription(expectedBallCount, states_msgs::sold_out::STATE_DSCRP_MSG);
		// clang-format on

		gMachine.InsertQuarter();
		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedBallCount, gMachine.GetBallCount());
		BOOST_CHECK_EQUAL(expectedOutput, oTestStream.str());
	}

	BOOST_FIXTURE_TEST_CASE(Test_try_eject_when_empty, GMWith0GumballsFx)
	{
		const auto expectedBallCount = 0;
		// clang-format off
		const auto expectedOutput = std::string(states_msgs::sold_out::EJECT_MSG) +
				GetMachineDescription(expectedBallCount, states_msgs::sold_out::STATE_DSCRP_MSG);
		// clang-format on

		gMachine.EjectQuarter();
		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedBallCount, gMachine.GetBallCount());
		BOOST_CHECK_EQUAL(expectedOutput, oTestStream.str());
	}

	BOOST_FIXTURE_TEST_CASE(Test_try_turn_crank_when_empty, GMWith0GumballsFx)
	{
		const auto expectedBallCount = 0;
		// clang-format off
		const auto expectedOutput = std::string(states_msgs::sold_out::TURN_CRANK_MSG) +
				states_msgs::sold_out::DISPENSE_MSG +
				GetMachineDescription(expectedBallCount, states_msgs::sold_out::STATE_DSCRP_MSG);
		// clang-format on

		gMachine.TurnCrank();
		oTestStream << gMachine.Description();

		BOOST_CHECK_EQUAL(expectedBallCount, gMachine.GetBallCount());
		BOOST_CHECK_EQUAL(expectedOutput, oTestStream.str());
	}

BOOST_AUTO_TEST_SUITE_END()
