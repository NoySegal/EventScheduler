#include "event_container.h"

namespace mtm {
	
	EventContainer::EventIterator EventContainer::begin() const {
		return events.getFirst();
	}
	
	EventContainer::EventIterator EventContainer::end() const {
		return NULL;
	}
}