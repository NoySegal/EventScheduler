#ifndef CLOSED_EVENT_H
#define CLOSED_EVENT_H

#include "base_event.h"

namespace mtm {
	class ClosedEvent : public BaseEvent
	{
	public:
		ClosedEvent(const DateWrap eventDate, const char* eventName) :
			BaseEvent(eventDate, eventName),
			invitees(List<int>()) {}
		ClosedEvent(const ClosedEvent& event) :
			BaseEvent(event),
			invitees(List<int>())
		{
			addInvitees(event.invitees);
		}
		~ClosedEvent() {}

		void addInvitee(int student);
		void registerParticipant(int student) override;
		ClosedEvent* clone() const override;

	private:
		List<int> invitees;

		void addInvitees(const List<int>&);
	};

	void ClosedEvent::addInvitees(const List<int>& targetInvitees) {
		Node<int>* current = targetInvitees.getFirst();
		while (current != NULL)
		{
			invitees.insertLast(new int(current->getValue()));
			current = current->getNext();
		}
	}

	void ClosedEvent::addInvitee(int student) {
		verifyStudent(student);
		if (invitees.contains(student))
		{
			throw AlreadyInvited();
		}
		invitees.insertStart(new int(student));
	}

	void ClosedEvent::registerParticipant(int student) {
		verifyStudent(student);
		if (!invitees.contains(student))
		{
			throw RegistrationBlocked();
		}
		if (members.contains(student))
		{
			throw AlreadyRegistered();
		}
		insertNewMember(student);
	}

	ClosedEvent* ClosedEvent::clone() const {
		return new ClosedEvent(*this);
	}
}

#endif