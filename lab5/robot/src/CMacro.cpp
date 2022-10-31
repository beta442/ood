#include "../include/CMacro.h"

using namespace robot;

void CMacro::AddCommand(ICommandPtr&& cmd)
{
	m_commands.push_back(std::move(cmd));
}

void CMacro::Execute()
{
	for (auto& cmd : m_commands)
	{
		cmd->Execute();
	}
}
