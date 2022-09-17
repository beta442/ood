#ifndef STATISTICVALUEHOLDER_H
#define STATISTICVALUEHOLDER_H

#include <concepts>
#include <string>

template <typename T = double>
class StatisticValueHolder
{
public:
	explicit StatisticValueHolder(const std::string& valName = "%EMPTY_VAL_NAME%")
		: m_valName(valName)
		, m_min((std::is_same<T, double>::value || std::is_same<T, long double>::value || std::is_same<T, float>::value)
				  ? std::numeric_limits<T>::infinity()
				  : std::numeric_limits<T>::max())
		, m_max((std::is_same<T, double>::value || std::is_same<T, long double>::value || std::is_same<T, float>::value)
				  ? -std::numeric_limits<T>::infinity()
				  : std::numeric_limits<T>::min())
		, m_accumulatedValue(0)
		, m_takenCounter(0)
	{
	}

	template <typename T>
	void TakeNextValue(T&& nextVal)
	{
		m_min = std::min(m_min, nextVal);
		m_max = std::max(m_max, nextVal);

		m_accumulatedValue += nextVal;

		++m_takenCounter;
	}

	std::string ToString() const
	{
		return std::string(
			"Max " + m_valName + ": " + std::to_string(m_max) + '\n' +
			"Min " + m_valName + ": " + std::to_string(m_min) + '\n' +
			"Average " + m_valName + ": " + std::to_string(m_accumulatedValue / m_takenCounter) + '\n' +
			"----------------"
		);
	}

private:
	std::string m_valName;

	T m_min;
	T m_max;
	T m_accumulatedValue;
	std::size_t m_takenCounter;
};

#endif // !STATISTICVALUEHOLDER_H
