#ifndef ONE_TIME_EVENT_H
#define ONE_TIME_EVENT_H

#include "event_container.h"

namespace mtm {

	template <class EventType>
	class OneTimeEvent : public EventContainer
	{
	public:
		OneTimeEvent(DateWrap date, const char* name) :
			EventContainer()
		{
			events.insertStart(new EventType(date, name));
		}
		~OneTimeEvent() = default;

		void add(const BaseEvent&) override;
	};

	template <class EventType>
	void OneTimeEvent<EventType>::add(const BaseEvent& event) {
		throw NotSupported();
	}
}

#endif