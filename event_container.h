#ifndef EVENT_CONTAINER_H
#define EVENT_CONTAINER_H

#include "exceptions.h"
#include "base_event.h"

namespace mtm {
	class EventContainer
	{
	public:
		EventContainer() :
			events(List<BaseEvent>()) {}
		~EventContainer() {}
		
		class EventIterator
		{
		public:
			EventIterator() :
				current(NULL) {}
			EventIterator(Node<BaseEvent>& node) :
				current(&node) {}
			EventIterator(Node<BaseEvent>* node) :
				current(node) {}
			~EventIterator() {}

			EventIterator& operator=(const EventIterator& nodeIterator) {
				current = nodeIterator.current;
				return *this;
			}
			EventIterator& operator++() {
				current = current->getNext();
				return *this;
			}
			BaseEvent& operator*() const {
				return current->getValue();
			}

			friend bool operator==(const EventIterator& iterator1, const EventIterator& iterator2) {
				return iterator1.current == iterator2.current;
			}

			bool operator!=(const EventIterator& iterator) const {
				return !(*this == iterator);
			}

		private:
			Node<BaseEvent>* current;
		};

		virtual void add(const BaseEvent&) = 0;
		EventIterator begin() const;
		EventIterator end() const;

	protected:
		List<BaseEvent> events;
	};
}

#endif