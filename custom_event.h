#ifndef CUSTOM_EVENT_H
#define CUSTOM_EVENT_H

#include "base_event.h"

namespace mtm {
	template <class CanRegister>
	class CustomEvent : public BaseEvent
	{
	public:
		CustomEvent(const DateWrap eventDate, const char* eventName, CanRegister predicate) :
			BaseEvent(eventDate, eventName),
			canRegister(predicate) {}
		CustomEvent(const CustomEvent& event) :
			BaseEvent(event),
			canRegister(event.canRegister) {}
		~CustomEvent() {}

		void registerParticipant(int student) override;
		CustomEvent<CanRegister>* clone() const override;

		CanRegister canRegister;
	};

	template <class CanRegister>
	void CustomEvent<CanRegister>::registerParticipant(int student) {
		verifyStudent(student);
		if (canRegister(student) == false)
		{
			throw RegistrationBlocked();
		}
		if (members.contains(student))
		{
			throw AlreadyRegistered();
		}
		insertNewMember(student);
	}

	template <class CanRegister>
	CustomEvent<CanRegister>* CustomEvent<CanRegister>::clone() const {
		return new CustomEvent(*this);
	}
}

#endif