#include "include/pch.h"

#include "../observer_priority/include/Observer.h"

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

	Observer(const OnUpdateEventFuncType& onUpdateEvent)
		: m_onUpdateEvent(onUpdateEvent)
	{
	}

private:
	void Update(const Data& data) override
	{
		m_onUpdateEvent();
	}

	OnUpdateEventFuncType m_onUpdateEvent;
};

template <typename Comp>
std::function<void()> Get(size_t lastPriority, size_t priority, bool compareResult, Comp comporator)
{
	return [=, localPriority = priority]() mutable -> void {
		std::cout << lastPriority << " " << localPriority << '\n';
		if (lastPriority != 0)
		{
			BOOST_TEST(compareResult == comparator(lastPriority, localPriority));
		}
		lastPriority = localPriority;
	};
}

template <typename Comp>
void ValidatePriorityOrder(Comp comparator, bool compareResult)
{
	ObservableSubject<int, Comp> s{};
	size_t lastPriority = 0;

	for (size_t priority = 0; priority < 10; ++priority)
	{
		Observer<int> observer{
			[&, localPriority = priority]() {
				std::cout << lastPriority << " " << localPriority << '\n';
				if (lastPriority != 0)
				{
					BOOST_TEST(compareResult == comparator(lastPriority, localPriority));
				}
				lastPriority = localPriority;
			}
		};
		s.RegisterObserver(priority, observer);
		if (priority == 9)
		{
			s.NotifyObservers();
		}
	}
}

BOOST_AUTO_TEST_CASE(ObserverPriorityTestCase)
{
	ValidatePriorityOrder(std::greater<size_t>(), false);
}
