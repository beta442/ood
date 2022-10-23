#include "../../include/Commands/UndoManager.h"

bool UndoManager::CanUndo() const noexcept
{
	return m_nextEditIndex != 0;
}

bool UndoManager::CanRedo() const noexcept
{
	return m_nextEditIndex != m_edits.size();
}

void UndoManager::Undo()
{
	if (CanUndo())
	{
		m_edits[m_nextEditIndex - 1]->Undo();
		--m_nextEditIndex;
	}
}

void UndoManager::Redo()
{
	if (CanRedo())
	{
		m_edits[m_nextEditIndex]->Redo();
		++m_nextEditIndex;
	}
}

void UndoManager::AddAndExecuteEdit(const IUndoableEditSharedPtr& edit)
{
	if (m_nextEditIndex < m_edits.size())
	{
		edit->Execute();

		m_edits.resize(++m_nextEditIndex);
		m_edits.back() = edit;
	}
	else
	{
		m_edits.emplace_back(nullptr);

		try
		{
			edit->Execute();

			m_edits.back() = edit;
			++m_nextEditIndex;
		}
		catch (...)
		{
			m_edits.pop_back();
			throw;
		}
	}
}

bool UndoManager::DerivedExecute()
{
	return false;
}

bool UndoManager::DerivedUndo()
{
	return false;
}

bool UndoManager::DerivedRedo()
{
	return false;
}
