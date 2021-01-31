#include "base_event.h"

namespace mtm {
	void BaseEvent::verifyStudent(int student) {
		if (student < 1 || student > 1234567890)
		{
			throw InvalidStudent();
		}
	}

	void BaseEvent::insertNewMember(int student) {
		if (members.getSize() == 0 || student < members.getFirst()->getValue())
		{
			members.insertStart(new int(student));
			return;
		}

		Node<int>* current = members.getFirst();
		while (current != NULL)
		{
			if (student < current->getValue())
			{
				members.insertBefore(*current, new int(student));
				return;
			}
			current = current->getNext();
		}

		members.insertLast(new int(student));
	}

	void BaseEvent::removeMember(int student) {
		Node<int>* current = members.getFirst();
		while (current != NULL)
		{
			if (student == current->getValue())
			{
				members.removeNode(*current);
				return;
			}
			current = current->getNext();
		}
	}

	void BaseEvent::printMembers(std::ostream& os) {
		Node<int>* student = members.getFirst();
		while (student)
		{
			os << student->getValue() << std::endl;
			student = student->getNext();
		}
	}

	void BaseEvent::addMembers(const List<int>& targetMembers) {
		Node<int>* current = targetMembers.getFirst();
		while (current != NULL)
		{
			insertNewMember(current->getValue());
			current = current->getNext();
		}
	}

	void BaseEvent::registerParticipant(int student) {
		verifyStudent(student);
		if (members.contains(student))
		{
			throw AlreadyRegistered();
		}

		insertNewMember(student);
	}

	void BaseEvent::unregisterParticipant(int student) {
		verifyStudent(student);
		if (!members.contains(student))
		{
			throw NotRegistered();
		}

		removeMember(student);
	}

	std::ostream& BaseEvent::printShort(std::ostream& os) {
		return os << name << " " << date << std::endl;
	}

	std::ostream& BaseEvent::printLong(std::ostream& os) {
		printShort(os);
		printMembers(os);
		return os;
	}

	bool operator<(const BaseEvent& event1, const BaseEvent& event2) {
		return (event1.date < event2.date) || (event1.date == event2.date && event1.name < event2.name);
	}

	DateWrap BaseEvent::getDate() const {
		return date;
	}

	String BaseEvent::getName() const {
		return name;
	}

	bool BaseEvent::operator==(const BaseEvent& other) const {
		return name == other.name && date == other.date;
	}
}