#ifndef STRING_H
#define STRING_H

#include <iostream>

using std::ostream;

namespace mtm {

	class String
	{
	public:
		String(const char* str = "");
		String(const String& str);
		~String();
		int size() const;
		String& operator=(const String&);
		const char* getData() const;

		friend ostream& operator<<(ostream&, const String&);
		friend bool operator==(const String&, const String&);
		friend bool operator<(const String&, const String&);

	private:
		int length;
		char* data;

		static char* allocate_and_copy(const char* data, int size);
		static char* copy_string(char* target, const char* source);
	};

	bool operator!=(const String& str1, const String& str2);
	bool operator<=(const String& str1, const String& str2);
	bool operator>(const String& str1, const String& str2);
	bool operator>=(const String& str1, const String& str2);
}

#endif