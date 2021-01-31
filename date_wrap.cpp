#include "date_wrap.h"

namespace mtm {
	DateWrap::DateWrap(const int day, const int month, const int year)
	{
		date = dateCreate(day, month, year);
		if (date == NULL)
		{
			throw InvalidDate();
		}
	}

	DateWrap::DateWrap(const DateWrap& datewrap)
	{
		date = dateCopy(datewrap.date);
	}

	DateWrap::~DateWrap()
	{
		dateDestroy(date);
	}

	int DateWrap::day() const {
		int day, month, year;
		dateGet(date, &day, &month, &year);
		return day;
	}

	int DateWrap::month() const {
		int day, month, year;
		dateGet(date, &day, &month, &year);
		return month;
	}

	int DateWrap::year() const {
		int day, month, year;
		dateGet(date, &day, &month, &year);
		return year;
	}

	ostream& operator<<(ostream& os, const DateWrap& datewrap) {
		return os << datewrap.day() << '/' << datewrap.month() << '/' << datewrap.year();
	}

	bool operator==(const DateWrap& date1, const DateWrap& date2) {
		return dateCompare(date1.date, date2.date) == 0;
	}

	bool operator<(const DateWrap& date1, const DateWrap& date2) {
		return dateCompare(date1.date, date2.date) < 0;
	}

	bool operator!=(const DateWrap& date1, const DateWrap& date2) {
		return !(date1 == date2);
	}

	bool operator<=(const DateWrap& date1, const DateWrap& date2) {
		return date1 == date2 || date1 < date2;
	}

	bool operator>(const DateWrap& date1, const DateWrap& date2) {
		return date2 < date1;
	}

	bool operator>=(const DateWrap& date1, const DateWrap& date2) {
		return !(date1 < date2);
	}

	DateWrap DateWrap::operator++(int) {
		DateWrap temp(*this);
		dateTick(this->date);
		return temp;
	}

	DateWrap& DateWrap::operator+=(int days) {
		if (days < 0)
		{
			throw NegativeDays();
		}

		while (days > 0)
		{
			(*this)++;
			days--;
		}

		return *this;
	}

	DateWrap& DateWrap::operator=(const DateWrap& datewrap) {
		if (this == &datewrap)
		{
			return *this;
		}

		dateDestroy(date);
		date = dateCopy(datewrap.date);
		return *this;
	}

	DateWrap operator+(const DateWrap& datewrap, int days) {
		if (days < 0)
		{
			throw NegativeDays();
		}
		return DateWrap(datewrap) += days;
	}

	DateWrap operator+(int days, const DateWrap& datewrap) {
		return operator+(datewrap, days);
	}
}