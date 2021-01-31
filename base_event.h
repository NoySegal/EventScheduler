#ifndef BASE_EVENT_H
#define BASE_EVENT_H

#include "date_wrap.h"
#include "linked_list.h"
#include "string.h"
#include "exceptions.h"

namespace mtm {
	class BaseEvent
	{
	public:
		BaseEvent(const DateWrap eventDate, const char* eventName) : 
			name(String(eventName)), 
			date(DateWrap(eventDate)),
			members(List<int>()) {}
		BaseEvent(const BaseEvent&  event) :
			name(String(event.name)),
			date(DateWrap(event.date)),
			members(List<int>())
		{
			addMembers(event.members);
		}
		virtual ~BaseEvent() {}
		
		virtual void registerParticipant(int student);
		virtual void unregisterParticipant(int student);
		virtual std::ostream& printShort(std::ostream&);
		virtual std::ostream& printLong(std::ostream&);
		virtual BaseEvent* clone() const = 0;
		DateWrap getDate() const;
		String getName() const;

		bool operator==(const BaseEvent&) const;
		friend bool operator<(const BaseEvent&, const BaseEvent&);

	protected:
		String name;
		DateWrap date;
		List<int> members;

		void addMembers(const List<int>&);
		static void verifyStudent(int student);
		void insertNewMember(int student);

	private:
		void removeMember(int student);
		void printMembers(std::ostream&);
	};
}

#endif