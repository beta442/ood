#include "include/pch.h"

#include "include/FileInputStream.h"
#include "include/FileOutputStream.h"

#include <sstream>

int main(int, char*)
{
	try
	{
		/*FileInputStream fIStream{ "main.cpp" };
		char* dest[100];
		std::cout << fIStream.ReadBlock(dest, 100) << '\n'
				  << dest + '\0' << '\n';*/

		//FileOutputStream fOStream{ "lock.txt" };
		//fOStream.WriteByte('1');
		std::istringstream ss{};

		std::cout << "'" << ss.get() << "'" << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
