#include <iostream>
#include <vector>
#include <exception>

using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;

// PART A

class BadInput : public std::exception
{
public:
	virtual char const* what() const noexcept { return "ERROR: Bad input!"; }
};

template <class T>
std::vector<T> slice(std::vector<T> vec, int start, int step, int stop) {
	if (start < 0 || start >= (int) vec.size() || stop < 0 || stop >(int) vec.size() || step <= 0)
	{
		throw BadInput();
	}

	int push_index = start;
	vector<T> newVector;

	for (auto it = vec.begin(); it != vec.end(); ++it) {
		int index = std::distance(vec.begin(), it);
		if (index >= start && index < stop && index == push_index)
		{
			newVector.push_back(*it);
			push_index += step;
		}
	}
	return newVector;
}

template <class T>
void print(std::vector<T> vec) {
	for (auto ptr : vec)
	{
		cout << ptr << " ";
	}
	cout << endl;
}

//int main() {
//	// this syntax initializes a vector with values a,b,c,d,e
//	std::vector<char> vec1{ 'a', 'b', 'c', 'd', 'e' };
//	print(vec1);
//	// returns vector with values a,c
//	std::vector<char> vec_sliced1 = slice(vec1, 0, 2, 4);
//	print(vec_sliced1);
//	// returns vector with values b,c,d,e
//	std::vector<char> vec_sliced2 = slice(vec1, 1, 1, 5);
//	print(vec_sliced2);
//	return 0;
//}

// PART B

class A {
public:
	~A() {
		values.clear();
	}

	std::vector<shared_ptr<int>> values;
	void add(int x) { values.push_back(std::make_shared<int>(x)); }
};
int main() {
	A a, sliced;
	a.add(0); a.add(1); a.add(2); a.add(3); a.add(4); a.add(5);
	sliced.values = slice(a.values, 1, 1, 4);
	*(sliced.values[0]) = 800;
	std::cout << *(a.values[1]) << std::endl;
	return 0;
}