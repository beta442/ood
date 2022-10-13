#ifndef IEQUAL_STRINGS_HPP_
#define IEQUAL_STRINGS_HPP_

template <typename StringSource, typename StringTest>
bool IEqualStrings(StringSource&& str1, StringTest&& str2)
{
	return ((str1.size() == str2.size()) && std::equal(str1.begin(), str1.end(), str2.begin(), [](auto& c1, auto& c2) {
		if (c1 == c2)
			return true;
		else if (std::toupper(c1) == std::toupper(c2))
			return true;
		return false;
	}));
}

#endif // !IEQUAL_STRINGS_HPP_
