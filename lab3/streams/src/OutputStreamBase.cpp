#include <ios>

#include "../include/OutputStreamBase.h"

constexpr auto WRITE_BLOCK_FAILURE_NULLPTR_MSG = "Failed write block attempt. nullptr in _1 parameter is provided";

void OutputStreamBase::WriteBlock(const void* srcData, std::streamsize size)
{
	if (srcData == nullptr)
	{
		throw std::ios_base::failure(WRITE_BLOCK_FAILURE_NULLPTR_MSG);
	}

	DerivedWriteBlock(srcData, size);
}
