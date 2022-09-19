#ifndef STATISTICVALUEHOLDER_H
#define STATISTICVALUEHOLDER_H

#include <string>

template <typename T = double>
class StatisticValueHolder
{
public:
	StatisticValueHolder()
		: m_min((std::is_same<T, double>::value || std::is_same<T, long double>::value || std::is_same<T, float>::value)
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

	T GetMin() const
	{
		return m_min;
	}

	T GetMax() const
	{
		return m_max;
	}

	T GetAverage() const
	{
		return m_accumulatedValue / m_takenCounter;
	}

private:
	T m_min;
	T m_max;
	T m_accumulatedValue;
	std::size_t m_takenCounter;
};

template <typename T>
std::string StatHolderToString(const StatisticValueHolder<T>& holder)
{
	return std::string(
		"Max: " + std::to_string(holder.GetMax()) + '\n' +
		"Min: " + std::to_string(holder.GetMin()) + '\n' +
		"Average: " + std::to_string(holder.GetAverage()) + '\n'
	);
}

#endif // !STATISTICVALUEHOLDER_H
