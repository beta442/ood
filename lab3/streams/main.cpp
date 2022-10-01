#include "include/pch.h"

#include "include/FileInputStream.h"

int main(int, char*)
{
	try
	{
		FileInputStream fIStream{ "main.cpp" };
		char* dest[100];
		std::cout << fIStream.ReadBlock(dest, 100) << '\n'
				  << dest + '\0' << '\n';
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
