#ifndef OPEN_EVENT_H
#define OPEN_EVENT_H

#include "base_event.h"

namespace mtm {
	class OpenEvent : public BaseEvent
	{
	public:
		OpenEvent(const DateWrap eventDate, const char* eventName) :
			BaseEvent(eventDate, eventName) {}
		OpenEvent(const OpenEvent& event) :
			BaseEvent(event) {}
		~OpenEvent() {}

		OpenEvent* clone() const override;
	};

	OpenEvent* OpenEvent::clone() const {
		return new OpenEvent(*this);
	}
}

#endif