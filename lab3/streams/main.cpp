#include "include/pch.h"

#include "include/FileInputStream.h"
#include "include/FileOutputStream.h"

#include "include/DecoratorHelpers.hpp"

#include "include/InputStreamDeCrypter.h"

int main(int, char*)
{
	try
	{
		auto handler = std::make_unique<FileInputStream>("input.txt") << DecorateStream<InputStreamDeCrypter>(10) << DecorateStream<InputStreamDeCrypter>(50);

		while (!handler->IsEOF())
		{
			std::cout << handler->ReadByte() << std::endl;
		}
		/*auto des = new uint8_t[9];
		handler->ReadBlock(des, 7);

		std::copy(des, des + 9, std::ostream_iterator<uint8_t>(std::cout, "|"));
		delete[] des;*/
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
