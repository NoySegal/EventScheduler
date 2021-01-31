#include "string.h"

namespace mtm {

	char* String::allocate_and_copy(const char* str, int size) {
		return copy_string(new char[size + 1], str);
	}

	char* String::copy_string(char* target, const char* source)
	{
		if (target == NULL || source == NULL)
		{
			return NULL;
		}
		int i;
		for (i = 0; source[i] != '\0'; i++)
		{
			target[i] = source[i];
		}

		target[i] = '\0';

		return target;
	}

	String::String(const char* str) {
		length = strlen(str);
		data = allocate_and_copy(str, length);
	}

	String::String(const String& str) :
		length(str.size()),
		data(allocate_and_copy(str.data, str.length)) {
	}

	String::~String() {
		delete[] data;
	}

	int String::size() const {
		return length;
	}

	String& String::operator=(const String& str) {
		if (this == &str)
		{
			return *this;
		}
		delete[] data;
		data = allocate_and_copy(str.data, str.length);
		length = str.length;
		return *this;
	}

	bool operator==(const String& str1, const String& str2) {
		return strcmp(str1.data, str2.data) == 0;
	}

	ostream& operator<<(ostream& os, const String& str) {
		return os << str.data;
	}

	bool operator<(const String& str1, const String& str2) {
		return strcmp(str1.data, str2.data) < 0;
	}

	bool operator!=(const String& str1, const String& str2) {
		return !(str1 == str2);
	}

	bool operator<=(const String& str1, const String& str2) {
		return !(str2 < str1);
	}

	bool operator>(const String& str1, const String& str2) {
		return str2 < str1;
	}

	bool operator>=(const String& str1, const String& str2) {
		return str2 <= str1;
	}

	const char* String::getData() const {
		return data;
	}
}