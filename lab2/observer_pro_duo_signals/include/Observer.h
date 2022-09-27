#ifndef OBSERVER_H
#define OBSERVER_H

#include <set>

#include "SignallingValue.hpp"

namespace Observer
{

template <typename T, typename SignalV = SignallingValue<T>>
class IObservable
{
public:
	using SignalValue = SignalV;
	using Callback = typename SignalValue::Slot;

	virtual boost::signals2::connection Connect(const Callback& onChange) = 0;
	virtual ~IObservable() = default;
};

template <typename T>
class Observable : public IObservable<T>
{
public:
	using SignalValue = typename IObservable<T>::SignalValue;
	using Callback = typename IObservable<T>::Callback;

	boost::signals2::connection Connect(const Callback& onChange) final
	{
		return m_signallingValue.Connect(onChange);
	}

protected:
	Observable() = default;

	template <typename T>
	Observable(T&& initValue)
		: m_signallingValue(std::forward<T>(initValue))
	{
	}

	SignalValue m_signallingValue;
};

} // namespace Observer

#endif // !OBSERVER_H
