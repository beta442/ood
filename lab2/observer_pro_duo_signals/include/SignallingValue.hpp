#ifndef SIGNALLINGVALUE_HPP
#define SIGNALLINGVALUE_HPP

#include <boost/signals2.hpp>

namespace Observer
{
namespace value_detail
{
// detail's explanation https://stackoverflow.com/questions/6534041/how-to-check-whether-operator-exists
struct No
{
};
template <typename T, typename Arg>
No operator==(const T&, const Arg&);

template <typename T, typename Arg = T>
struct EqualExists
{
	enum
	{
		value = !std::is_same<decltype(std::declval<T>() == std::declval<Arg>()), No>::value
	};
};
} // namespace value_detail

template <typename T, typename SignalSignature = void(const T&, const T&)>
class SignallingValue
{
public:
	using Signal = boost::signals2::signal<SignalSignature>;
	using Slot = typename Signal::slot_type;

	SignallingValue() = default;

	template <typename T>
	explicit SignallingValue(T&& val)
		: m_value(std::forward<T>(val))
		, onChange()
	{
	}

	const T& GetValue() const { return m_value; }

	template <typename T>
	void SetValue(T&& newValue)
	{
		if constexpr (value_detail::EqualExists<T>::value)
		{
			T incomingValue(std::forward<T>(newValue));
			if (m_value != incomingValue)
			{
				std::swap(m_value, incomingValue);
				onChange(incomingValue, m_value);
			}
		}
		else
		{
			auto prevVal = m_value;
			m_value = std::forward<T>(newValue);
			onChange(prevVal, m_value);
		}
	}

	template <typename T>
	void SetSilently(T&& newValue)
	{
		m_value = T(std::forward<T>(newValue));
	}

	template <typename Slot>
	boost::signals2::connection Connect(Slot&& slot)
	{
		return onChange.connect(std::forward<Slot>(slot));
	}

	template <typename Slot>
	void Disconnect(Slot&& slot)
	{
		onChange.disconnect(std::forward<Slot>(slot));
	}

	void DisconnectAll()
	{
		onChange.disconnect_all_slots();
	}

	explicit operator T() const { return m_value; }
	explicit operator const T&() const { return m_value; }
	const T& operator*() const { return m_value; }
	const T* operator->() const { return &m_value; }
	void operator=(const T& newValue) { SetValue(newValue); }

	SignallingValue(const SignallingValue&) = delete;
	SignallingValue& operator=(const SignallingValue&) = delete;
	SignallingValue(SignallingValue&&) = delete;
	SignallingValue& operator=(SignallingValue&&) = delete;

protected:
	T m_value = T();

	Signal onChange; // SignalT()(_1, _2) _1 holds old, _2 - new
};

} // namespace Observer

#endif // SIGNALLINGVALUE_HPP
