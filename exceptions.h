#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

namespace mtm {
	class Exception : public std::exception {};

	class InvalidDate : public Exception
	{
	public:
		virtual char const* what() const noexcept { return "ERROR: Invalid date!"; }
	};

	class NegativeDays : public Exception
	{
	public:
		virtual char const* what() const noexcept { return "ERROR: Negative days!"; }
	};

	class InvalidStudent : public Exception
	{
	public:
		virtual char const* what() const noexcept { return "ERROR: Invalid student!"; }
	};

	class AlreadyRegistered : public Exception
	{
	public:
		virtual char const* what() const noexcept { return "ERROR: Already registered!"; }
	};

	class RegistrationBlocked : public Exception
	{
	public:
		virtual char const* what() const noexcept { return "ERROR: Registration blocked!"; }
	};

	class NotRegistered : public Exception
	{
	public:
		virtual char const* what() const noexcept { return "ERROR: Not registered!"; }
	};

	class AlreadyInvited : public Exception
	{
	public:
		virtual char const* what() const noexcept { return "ERROR: Already invited!"; }
	};

	class NotSupported : public Exception
	{
	public:
		virtual char const* what() const noexcept { return "ERROR: Not supported!"; }
	};

	class DateMismatch : public Exception
	{
	public:
		virtual char const* what() const noexcept { return "ERROR: Date mismatch!"; }
	};

	class InvalidNumber : public Exception
	{
	public:
		virtual char const* what() const noexcept { return "ERROR: Invalid number!"; }
	};

	class InvalidInterval : public Exception
	{
	public:
		virtual char const* what() const noexcept { return "ERROR: Invalid interval!"; }
	};

	class EventAlreadyExists : public Exception
	{
	public:
		virtual char const* what() const noexcept { return "ERROR: Event already exists!"; }
	};

	class EventDoesNotExist : public Exception
	{
	public:
		virtual char const* what() const noexcept { return "ERROR: Event does not exist!"; }
	};
}

#endif