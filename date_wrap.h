#ifndef DATE_WRAP_H
#define DATE_WRAP_H

#include <iostream>
#include "exceptions.h"

extern "C" {
#include "date.h"
}

using std::ostream;

namespace mtm {
	class DateWrap
	{
	public:
		DateWrap(const int day, const int month, const int year);
		DateWrap(const DateWrap& datewrap);
		~DateWrap();
		int day() const;
		int month() const;
		int year() const;

		friend ostream& operator<<(ostream&, const DateWrap&);
		friend bool operator==(const DateWrap&, const DateWrap&);
		friend bool operator<(const DateWrap&, const DateWrap&);

		DateWrap operator++(int);

		DateWrap& operator+=(int days);
		DateWrap& operator=(const DateWrap&);

	private:
		Date date;
	};

	bool operator!=(const DateWrap& date1, const DateWrap& date2);
	bool operator<=(const DateWrap& date1, const DateWrap& date2);
	bool operator>(const DateWrap& date1, const DateWrap& date2);
	bool operator>=(const DateWrap& date1, const DateWrap& date2);
	DateWrap operator+(const DateWrap& datewrap, int);
	DateWrap operator+(int, const DateWrap& datewrap);
}

#endif