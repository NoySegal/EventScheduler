//#include <iostream> 
//#include "exceptions.h"
//#include "test_utilities.h"
//#include "linked_list.h"
//#include "event_container.h"
//using mtm::List;
//using namespace std;
//
//#define NUMBER_TESTS 1
//
//template <class T> void print(const T& x) { cout << x << endl; }
//
//bool testBasic() {
//	bool result = true;
//
//	List<int> list;
//	mtm::Node<int>* current;
//
//	int* one = new int(1);
//	int* two = new int(2);
//	int* three = new int(3);
//	int* four = new int(4);
//	int* five = new int(5);
//
//	int* one_last = new int(1);
//
//	list.insertStart(one);
//
//	// test getValue // 1
//	current = list.getFirst();
//	ASSERT_TEST(current->getValue() == 1, destroy);
//	ASSERT_TEST(list.getSize() == 1, destroy);
//
//	// test contains
//	ASSERT_TEST(list.contains(1) == true, destroy);
//	ASSERT_TEST(list.contains(2) == false, destroy);
//
//	// test insertAfter // 1 -> 2
//	list.insertAfter(*current, two);
//	ASSERT_TEST(current->getValue() == 1, destroy);
//	ASSERT_TEST(list.contains(1) == true, destroy);
//	ASSERT_TEST(list.contains(2) == true, destroy);
//	current = current->getNext();
//	ASSERT_TEST(current->getValue() == 2, destroy);
//	ASSERT_TEST(list.getSize() == 2, destroy);
//
//	// test insertStart // 3 -> 1 -> 2
//	list.insertStart(three);
//	ASSERT_TEST(list.getFirst()->getValue() == 3, destroy);
//	ASSERT_TEST(list.getSize() == 3, destroy);
//
//	// test getPrevious and remove // 3 -> 2
//	ASSERT_TEST(list.getFirst()->getNext()->getValue() == list.getPrev(*current)->getValue(), destroy);
//	list.removeNode(*list.getPrev(*current));
//	ASSERT_TEST(list.contains(1) == false, destroy);
//	current = list.getFirst();
//	ASSERT_TEST(current->getValue() == 3, destroy);
//	ASSERT_TEST(current->getNext()->getValue() == 2, destroy);
//	ASSERT_TEST(current->getNext()->getNext() == NULL, destroy);
//	ASSERT_TEST(list.getSize() == 2, destroy);
//
//	// test insertAfter // 3 -> 4 -> 2
//	list.insertAfter(*current, four);
//	ASSERT_TEST(list.contains(1) == false, destroy);
//	ASSERT_TEST(list.contains(2) == true, destroy);
//	ASSERT_TEST(list.contains(3) == true, destroy);
//	ASSERT_TEST(list.contains(4) == true, destroy);
//	current = list.getFirst();
//	ASSERT_TEST(current->getValue() == 3, destroy);
//	current = list.getNext(*current);
//	ASSERT_TEST(current->getValue() == 4, destroy);
//	current = current->getNext();
//	ASSERT_TEST(current->getValue() == 2, destroy);
//	ASSERT_TEST(list.getSize() == 3, destroy);
//
//	// test insertBefore // 3 -> 4 -> 5 -> 2
//	list.insertBefore(*current, five);
//	ASSERT_TEST(list.contains(5) == true, destroy);
//	ASSERT_TEST(current->getPrev()->getValue() == 5, destroy);
//	ASSERT_TEST(current->getPrev()->getPrev()->getValue() == 4, destroy);
//	ASSERT_TEST(list.getSize() == 4, destroy);
//
//	// test insertLast // 3 -> 4 -> 5 -> 2 -> 1
//	list.insertLast(one_last);
//	ASSERT_TEST(list.contains(1) == true, destroy);
//	current = current->getNext();
//	ASSERT_TEST(current->getValue() == 1, destroy);
//	ASSERT_TEST(list.getSize() == 5, destroy);
//
//
//destroy:
//	return result;
//}
//
//bool (*tests[]) (void) = {
//		testBasic
//};
//
//const char* testNames[] = {
//		"testBasic"
//};
//
//int main() {
//
//	cout << "Welcome to LinkedList tests!" << endl;
//
//	for (int test_idx = 0; test_idx < NUMBER_TESTS; test_idx++) {
//		print("---------------------");
//		RUN_TEST(tests[test_idx], testNames[test_idx]);
//	}
//
//	return 0;
//}