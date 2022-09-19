#ifndef OBSERVERPRIORITY_H
#define OBSERVERPRIORITY_H

#include <vector>

#include "../../observer_priority/include/Observer.h"

template <typename Data = int, typename Comp = std::greater<size_t>>
class ObservableSubject : public PrioritizedObservable<Data, Comp>
{
public:
	ObservableSubject()
		: m_data()
	{
	}

protected:
	Data GetChangedData() const override
	{
		return m_data;
	}

private:
	Data m_data;
};

template <typename Data>
class Observer : public IObserver<Data>
{
public:
	using OnUpdateEventFuncType = std::function<void()>;

	explicit Observer(const OnUpdateEventFuncType& onUpdateEvent)
		: m_onUpdateEvent(onUpdateEvent)
	{
	}

private:
	void Update(const Data& data, IObservable<Data>& updateSource) override
	{
		m_onUpdateEvent();
	}

	OnUpdateEventFuncType m_onUpdateEvent;
};

enum class CompareResult
{
	LESS = -1,
	EQUAL = 0,
	GREATER = 1,
};

template <typename T>
CompareResult Compare(const T& lhs, const T& rhs)
{
	return (lhs == rhs)
		? CompareResult::EQUAL
		: (lhs < rhs)
		? CompareResult::LESS
		: CompareResult::GREATER;
}

constexpr auto OBSERVERS_TEST_AMOUNT = 100;

template <typename Comp, typename Data = int>
void ValidatePriorityOrder(CompareResult excpectedComporatorResult, size_t priorityStep = 1)
{
	ObservableSubject<Data, Comp> s{};
	std::vector<Observer<Data>*> observersHolder;
	observersHolder.resize(OBSERVERS_TEST_AMOUNT);

	size_t lastPriority = 0;
	for (size_t priority = 0; priority < OBSERVERS_TEST_AMOUNT; ++priority)
	{
		auto observer = new Observer<Data>(
			[&, localPriority = priority * priorityStep]() mutable -> void {
				if (lastPriority != 0)
				{
					auto result = Compare(lastPriority, localPriority);

					BOOST_TEST((result == excpectedComporatorResult));
				}
				lastPriority = localPriority;
			});
		s.RegisterObserver(priority, *observer);
		observersHolder[priority] = observer;
	}
	s.NotifyObservers();

	std::for_each(std::begin(observersHolder), std::end(observersHolder), [&](auto& p) { s.RemoveObserver(*p); });
	std::for_each(std::begin(observersHolder), std::end(observersHolder), [&](auto& p) { delete p; });
}

#endif // OBSERVERPRIORITY_H
