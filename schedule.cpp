#include "schedule.h"

namespace mtm {
	bool compareEvent(BaseEvent* event1, BaseEvent* event2) {
		return *event1 < *event2;
	}

	void Schedule::addEvents(const EventContainer& container) {
		for (EventContainer::EventIterator ec_iter = container.begin(); ec_iter != container.end(); ++ec_iter) {
			vector<BaseEvent*>::iterator iter = find_if(events.begin(), events.end(),
				[=](const BaseEvent* event) {
					return *(event) == *ec_iter;
				});
			if (iter != events.end())
			{
				throw EventAlreadyExists();
			}
		}
		
		for (EventContainer::EventIterator ec_iter = container.begin(); ec_iter != container.end(); ++ec_iter) {
			events.push_back((*ec_iter).clone());
		}

		sort(events.begin(), events.end(), compareEvent);
	}

	vector<BaseEvent*>::iterator Schedule::findEvent(DateWrap date, const char* eventName) {
		vector<BaseEvent*>::iterator iter = find_if(events.begin(), events.end(),
			[=](const BaseEvent* event) {
				return event->getDate() == date && event->getName() == eventName;
			});
		if (iter == events.end())
		{
			throw EventDoesNotExist();
		}

		return iter;
	}

	void Schedule::registerToEvent(DateWrap date, const char* eventName, int student) {
		vector<BaseEvent*>::iterator iter = findEvent(date, eventName);
		(*iter)->registerParticipant(student);
	}

	void Schedule::unregisterFromEvent(DateWrap date, const char* eventName, int student) {
		vector<BaseEvent*>::iterator iter = findEvent(date, eventName);
		(*iter)->unregisterParticipant(student);
	}

	void Schedule::printAllEvents() const {
		for (auto ptr : events)
		{
			ptr->printShort(std::cout);
			std::cout << std::endl;
		}
	}

	void Schedule::printMonthEvents(int month, int year) const {
		for (auto ptr : events)
		{
			if ((ptr->getDate()).month() == month && (ptr->getDate()).year() == year)
			{
				ptr->printShort(std::cout);
				std::cout << std::endl;
			}
		}
	}

	void Schedule::printEventDetails(DateWrap date, const char* eventName) const {
		for (auto ptr : events)
		{
			if (ptr->getDate() == date && ptr->getName() == eventName)
			{
				ptr->printLong(std::cout);
				std::cout << std::endl;
				return;
			}
		}

		throw EventDoesNotExist();
	}
}