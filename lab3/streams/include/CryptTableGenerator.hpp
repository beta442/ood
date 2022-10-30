#ifndef CRYPT_TABLE_GENERATOR_HPP
#define CRYPT_TABLE_GENERATOR_HPP

#include <cstdint>
#include <random>
#include <vector>

enum class CryptMode
{
	ENCRYPT = 0,
	DECRYPT,
};

template <CryptMode MODE = CryptMode::ENCRYPT>
std::vector<unsigned char> GenerateCryptTable(unsigned char key)
{
	std::vector<unsigned char> res;
	res.resize(256);

	std::for_each(res.begin(), res.end(), [counter = 0](auto& val) mutable noexcept {
		val = counter++;
	});
	std::shuffle(res.begin(), res.end(), std::move(std::mt19937(key)));

	if constexpr (MODE == CryptMode::DECRYPT)
	{
		std::vector<unsigned char> inverted = res;
		std::for_each(res.begin(), res.end(), [&, counter = 0](auto& val) mutable noexcept {
			inverted[val] = counter++;
		});
		res = std::move(inverted);
	}

	res.shrink_to_fit();

	return res;
}

#endif // !CRYPT_TABLE_GENERATOR_HPP
