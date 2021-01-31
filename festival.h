#ifndef FESTIVAL_H
#define FESTIVAL_H

#include "event_container.h"

namespace mtm {
	class Festival : public EventContainer
	{
	public:
		Festival(DateWrap plannedDate) :
			EventContainer(),
			date(plannedDate) {}
		~Festival() = default;

		void add(const BaseEvent&) override;

	private:
		DateWrap date;
	};

	void Festival::add(const BaseEvent& event) {
		if (event.getDate() != date)
		{
			throw DateMismatch();
		}

		BaseEvent* eventClone = event.clone();
		if (events.getSize() == 0)
		{
			events.insertStart(eventClone);
			return;
		}

		Node<BaseEvent>* current = events.getFirst();
		while (current != NULL)
		{
			if (*eventClone < current->getValue())
			{
				events.insertBefore(*current, eventClone);
				return;
			}
			current = current->getNext();
		}

		events.insertLast(eventClone);
	}
}

#endif