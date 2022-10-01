#include <random>

#include "../include/CryptTableGenerator.h"

std::vector<uint8_t> GenerateTable(unsigned char key)
{
	std::vector<uint8_t> res;
	res.resize(255);

	std::for_each(res.begin(), res.end(), [counter = 0](auto& val) mutable noexcept {
		val = counter++;
	});

	std::mt19937 m(key);
	std::shuffle(res.begin(), res.end(), m);

	res.shrink_to_fit();

	return res;
}
