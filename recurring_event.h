#ifndef RECURRING_EVENT_H
#define RECURRING_EVENT_H

#include "event_container.h"

namespace mtm {

	template <class EventType>
	class RecurringEvent : public EventContainer
	{
	public:
		RecurringEvent(DateWrap first_date, const char* name, int num_occurrences, int interval_days) :
			EventContainer()
		{
			if (num_occurrences <= 0)
			{
				throw InvalidNumber();
			}
			if (interval_days <= 0)
			{
				throw InvalidInterval();
			}

			for (int i = 1; i <= num_occurrences; i++)
			{
				events.insertLast(new EventType(first_date, name));
				first_date += interval_days;
			}
		}
		~RecurringEvent() = default;

		void add(const BaseEvent&) override;
	};

	template <class EventType>
	void RecurringEvent<EventType>::add(const BaseEvent& event) {
		throw NotSupported();
	}
}

#endif