#include <string>  
#include <iostream> 
#include <sstream> 
#include "date_wrap.h"
#include "exceptions.h"
#include "test_utilities.h"
using mtm::DateWrap;
using namespace std;

#define NUMBER_TESTS 10

template <class T> void print(const T& x) { cout << x << endl; }

static string datewrapToString(DateWrap date) {
	stringstream buffer;
	buffer << date;
	return buffer.str();
}

bool testBasic() {
	bool result = true;
	
	DateWrap date1(1, 2, 3);
	DateWrap date2(4, 5, 6);
	DateWrap date3(date1);
	DateWrap date4(10, 2, 3);
	DateWrap date5(5, 5, 6);

	// test constructor
	ASSERT_TEST(datewrapToString(date1) == "1/2/3", destroy);
	ASSERT_TEST(datewrapToString(date2) == "4/5/6", destroy);

	// test copy constructor
	ASSERT_TEST(datewrapToString(date3) == "1/2/3", destroy);

	// test ==
	ASSERT_TEST(date3 == date1, destroy);
	ASSERT_TEST(date1 == date3, destroy);
	ASSERT_TEST((date1 == date2) == false, destroy);

	// test !=
	ASSERT_TEST((date3 != date1) == false, destroy);
	ASSERT_TEST(date1 != date2, destroy);

	// test day(), month(), year()
	ASSERT_TEST(date2.day() == 4, destroy);
	ASSERT_TEST(date2.month() == 5, destroy);
	ASSERT_TEST(date2.year() == 6, destroy);

	// test <
	ASSERT_TEST((date3 < date1) == false, destroy);
	ASSERT_TEST(date1 < date2, destroy);
	ASSERT_TEST((date2 < date1) == false, destroy);

	// test <=
	ASSERT_TEST(date3 <= date1, destroy);
	ASSERT_TEST(date1 <= date2, destroy);
	ASSERT_TEST((date2 <= date1) == false, destroy);

	// test >
	ASSERT_TEST((date3 > date1) == false, destroy);
	ASSERT_TEST(date2 > date1, destroy);
	ASSERT_TEST((date1 > date2) == false, destroy);

	// test >=
	ASSERT_TEST(date3 >= date1, destroy);
	ASSERT_TEST(date2 >= date1, destroy);
	ASSERT_TEST((date1 >= date2) == false, destroy);

	// test ++
	date1++;
	ASSERT_TEST(datewrapToString(date1) == "2/2/3", destroy);
	ASSERT_TEST(date1 != date3, destroy);
	ASSERT_TEST(date1 > date3, destroy);
	ASSERT_TEST(date5 > date2++, destroy); // check ++ returns old value
	ASSERT_TEST(date5 == date2, destroy); // check that ++ actually increased

	// test +=
	date1 += 14;
	ASSERT_TEST(datewrapToString(date1) == "16/2/3", destroy);
	ASSERT_TEST(date1 > date4, destroy);

	// test +
	ASSERT_TEST(datewrapToString(date3 + 10) == "11/2/3", destroy);
	ASSERT_TEST(date3 + 15 == date1, destroy);
	ASSERT_TEST(datewrapToString(11 + date3) == "12/2/3", destroy);
	ASSERT_TEST(15 + date3 == date1, destroy);
	
	destroy:
	return result;
}

bool testInvalidDateException() {
	bool result = true;

	try
	{
		DateWrap date1(-1, 2, 3);
	}
	catch (const mtm::InvalidDate& e)
	{
		ASSERT_TEST(e.what() == "ERROR: Invalid date!", destroy);
	}

	destroy:
	return result;
}

bool testNegativeDaysOperatorPlusEqualsException() {
	bool result = true;

	try
	{
		DateWrap date1(1, 2, 3);
		date1 += -7;
	}
	catch (const mtm::NegativeDays& e)
	{
		ASSERT_TEST(e.what() == "ERROR: Negative days!", destroy);
	}

destroy:
	return result;
}

bool testNegativeDaysOperatorPlusException() {
	bool result = true;

	DateWrap date1(1, 2, 3);
	DateWrap date2(3, 4, 5);

	try
	{
		date2 = date1 + -7;
	}
	catch (const mtm::NegativeDays& e)
	{
		ASSERT_TEST(e.what() == "ERROR: Negative days!", destroy);
	}

	try
	{
		date2 = -7 + date1;
	}
	catch (const mtm::NegativeDays& e)
	{
		ASSERT_TEST(e.what() == "ERROR: Negative days!", destroy);
	}

destroy:
	return result;
}

bool testProvidedPartA() {
	bool result = true;

	print("***VISUAL ASSERTION***");

	DateWrap date(30, 11, 2020);
	print(date);
	print(date + 4);
	print(3 + date);
	date++;
	print(date);
	date += 7;
	print(date);
	print(date > DateWrap(29, 11, 2020));
	print(date <= DateWrap(29, 11, 2020));
	print(date == DateWrap(30, 11, 2020));
	print(date == DateWrap(8, 12, 2020));
	try {
		date += (-3);
	}
	catch (mtm::NegativeDays) {
		print("NegativeDays");
	}
	try {
		date = date + (-3);
	}
	catch (mtm::NegativeDays) {
		print("NegativeDays");
	}
	return result;
}

bool testBooleanOperators()
{
	bool result = true;
	DateWrap d1(1, 1, 2000);
	DateWrap d2(1, 1, 2000);
	DateWrap d3(2, 1, 2000);
	ASSERT_TEST(d3 > d1, destroy);
	ASSERT_TEST(d1 >= d2, destroy);
	ASSERT_TEST(d1 <= d2, destroy);
	ASSERT_TEST(d1 == d2, destroy);
	ASSERT_TEST(d1 < d3, destroy);
	ASSERT_TEST(d1 != d3, destroy);

	destroy:
	return result;
}

bool testArithmeticOperators() {
	bool result = true;
	DateWrap d1(1, 1, 2000);
	DateWrap d2(1, 1, 2000);
	DateWrap d3(2, 1, 2000);
	DateWrap d4(30, 2, 3);
	d1 += 1;
	ASSERT_TEST(d1 == d3, destroy);
	d4 += 1;
	ASSERT_TEST(d4.day() == 1, destroy);
	d1++;
	ASSERT_TEST(d4.month() == 3, destroy);
	ASSERT_TEST(d1.year() == 2000, destroy);

	destroy:
	return result;
}

bool testDateWrapCreateDestroy_CreaterYan() {
	bool result = true;
	int day = 11, day2 = 25, month = 1, month2 = 8, year = 2021, year2 = 1990;
	DateWrap date(day, month, year);
	DateWrap date2(date);
	DateWrap date3(day2, month2, year2);
	DateWrap date4(1, 1, 20);
	DateWrap date5(1, 1, 20);

	ASSERT_TEST(date.day() == day, destroy);
	ASSERT_TEST(date.month() == month, destroy);
	ASSERT_TEST(date.year() == year, destroy);

	ASSERT_TEST(date2.day() == day, destroy);
	ASSERT_TEST(date2.month() == month, destroy);
	ASSERT_TEST(date2.year() == year, destroy);

	date2 = date3;
	ASSERT_TEST(date2.day() == day2, destroy);
	ASSERT_TEST(date2.month() == month2, destroy);
	ASSERT_TEST(date2.year() == year2, destroy);

	ASSERT_TEST(date5++ == date4, destroy);

destroy:
	return result;
}

bool testDateComparison_CreatorYan() {
	bool result = true;
	DateWrap date1(20, 12, 2020);
	DateWrap date2(30, 2, 2021);

	ASSERT_TEST(date1 == date1, destroy);
	ASSERT_TEST(date1 != date2, destroy);

	ASSERT_TEST(date1 < date2, destroy);
	ASSERT_TEST(date1 <= date2, destroy);
	ASSERT_TEST(date2 > date1, destroy);
	ASSERT_TEST(date2 >= date1, destroy);

	ASSERT_TEST(!(date1 == date2), destroy);
	ASSERT_TEST(!(date1 == date2), destroy);

	ASSERT_TEST(!(date1 >= date2), destroy);
	ASSERT_TEST(!(date1 > date2), destroy);
	ASSERT_TEST(!(date2 <= date1), destroy);
	ASSERT_TEST(!(date2 < date1), destroy);

destroy:
	return result;
}

bool testDateIncrement_CreatorYan() {
	bool result = true, passed = true;
	int day = 30, month = 12, year = 2010;
	DateWrap date(day, month, year);
	DateWrap date2(day, month, year);
	date++;
	ASSERT_TEST(date.day() == 1, destroy);
	ASSERT_TEST(date.month() == 1, destroy);
	ASSERT_TEST(date.year() == 2011, destroy);

		try {
		passed = false;
		date += -3;
	}
	catch (mtm::NegativeDays&) {
		passed = true;
	}
	ASSERT_TEST(passed, destroy);

	date += 3;

	date2 = date + 10;
	ASSERT_TEST(date.day() == 4, destroy);
	ASSERT_TEST(date.month() == 1, destroy);
	ASSERT_TEST(date.year() == 2011, destroy);

	ASSERT_TEST(date2.day() == 14, destroy);
	ASSERT_TEST(date2.month() == 1, destroy);
	ASSERT_TEST(date2.year() == 2011, destroy);

	date2 = 30 + date;
	ASSERT_TEST(date2.day() == 4, destroy);
	ASSERT_TEST(date2.month() == 2, destroy);
	ASSERT_TEST(date2.year() == 2011, destroy);
destroy:
	return result;
}

bool (*tests[]) (void) = {
		testBasic,
		testInvalidDateException,
		testNegativeDaysOperatorPlusEqualsException,
		testNegativeDaysOperatorPlusException,
		testProvidedPartA,
		testBooleanOperators,
		testArithmeticOperators,
		testDateWrapCreateDestroy_CreaterYan,
		testDateComparison_CreatorYan,
		testDateIncrement_CreatorYan
};

const char* testNames[] = {
        "testBasic",
		"testInvalidDateException",
		"testNegativeDaysOperatorPlusEqualsException",
		"testNegativeDaysOperatorPlusException",
        "testProvidedPartA",
		"testBooleanOperators",
		"testArithmeticOperators",
		"testDateWrapCreateDestroy_CreaterYan",
		"testDateComparison_CreatorYan",
		"testDateIncrement_CreatorYan"
};

int main() {

	cout << "Welcome to DateWrap tests!" << endl;

	for (int test_idx = 0; test_idx < NUMBER_TESTS; test_idx++) {
		print("---------------------");
        RUN_TEST(tests[test_idx], testNames[test_idx]);
    }

    return 0;
}