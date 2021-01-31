#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "base_event.h"
#include "event_container.h"
#include <vector>
#include <algorithm>

using std::shared_ptr;
using std::vector;
using std::find_if;
using std::make_shared;
using std::sort;

namespace mtm {
	class Schedule
	{
	public:
		Schedule() :
			events() {}
		~Schedule()
		{
			for (auto ptr : events)
			{
				delete ptr;
			}
			events.clear();
		}

		void addEvents(const EventContainer&);
		void registerToEvent(DateWrap date, const char* eventName, int student);
		void unregisterFromEvent(DateWrap date, const char* eventName, int student);
		void printAllEvents() const;
		void printMonthEvents(int month, int year) const;
		template<typename Predicate>
		void printSomeEvents(Predicate predicate, bool verbose = false) const;
		void printEventDetails(DateWrap date, const char* eventName) const;


	private:
		vector<BaseEvent*> events;

		vector<BaseEvent*>::iterator findEvent(DateWrap date, const char* eventName);
	};

	template<typename Predicate>
	void Schedule::printSomeEvents(Predicate predicate, bool verbose) const {
		for (auto ptr : events)
		{
			if (predicate(*ptr))
			{
				if (verbose)
				{
					ptr->printLong(std::cout);
					std::cout << std::endl;
				}
				else
				{
					ptr->printShort(std::cout);
					std::cout << std::endl;
				}
			}
		}
	}
}

#endif