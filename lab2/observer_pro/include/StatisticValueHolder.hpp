#ifndef STATISTICVALUEHOLDER_H
#define STATISTICVALUEHOLDER_H

#include <string>

template <typename T = double>
class IStatisticValueHolder
{
public:
	virtual void TakeNextValue(const T& nextVal) noexcept = 0;

	virtual T GetMin() const noexcept = 0;
	virtual T GetMax() const noexcept = 0;
	virtual T GetAverage() const noexcept = 0;
};

template <typename T = double>
class StatisticValueHolder : public IStatisticValueHolder<T>
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

	void TakeNextValue(const T& nextVal) noexcept override
	{
		m_min = std::min(m_min, nextVal);
		m_max = std::max(m_max, nextVal);

		m_accumulatedValue += nextVal;

		++m_takenCounter;
	}

	T GetMin() const noexcept override final
	{
		return m_min;
	}

	T GetMax() const noexcept override final
	{
		return m_max;
	}

	T GetAverage() const noexcept override
	{
		return (m_takenCounter != 0) ? m_accumulatedValue / m_takenCounter : T();
	}

protected:
	T m_min;
	T m_max;
	T m_accumulatedValue;
	T m_takenCounter;
};

constexpr auto MAX_ANGLE = 360;
constexpr auto MAX_ANGLE_2 = 180;
constexpr auto M_PI = 3.14159265358979323846;

class WindAngleStatisticHolder : public StatisticValueHolder<double>
{
public:
	void TakeNextValue(const double& nextVal) noexcept override
	{
		m_min = std::min(m_min, std::fmod(nextVal, MAX_ANGLE));
		m_max = std::max(m_max, std::fmod(nextVal, MAX_ANGLE));

		m_sumOfSin = m_sumOfSin + std::sin(ToRadians(nextVal));
		m_sumOfCos = m_sumOfCos + std::cos(ToRadians(nextVal));

		auto x = ToDegrees(std::atan2(m_sumOfSin, m_sumOfCos)) + MAX_ANGLE;
		m_average = std::fmod(x, MAX_ANGLE);
	}

	double GetAverage() const noexcept final
	{
		return m_average;
	}

private:
	double ToRadians(double degrees) const
	{
		return M_PI * degrees / MAX_ANGLE_2;
	}

	double ToDegrees(double radians) const
	{
		return MAX_ANGLE_2 * radians / M_PI;
	}

	double m_sumOfSin = 0;
	double m_sumOfCos = 0;
	double m_average = 0;
};

template <typename T>
static std::string StatHolderToString(const IStatisticValueHolder<T>& holder)
{
	return std::string(
		"Max: " + std::to_string(holder.GetMax()) + '\n' +
		"Min: " + std::to_string(holder.GetMin()) + '\n' +
		"Average: " + std::to_string(holder.GetAverage()) + '\n'
	);
}

#endif // !STATISTICVALUEHOLDER_H
