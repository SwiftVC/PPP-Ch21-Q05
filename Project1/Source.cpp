/*
*	Author:	CS
*	Date:	2022_03_17	YYYY_MM_DD
*
*	Section 1: Both count and countif are implemented in a way that std::list<>::end() and std::vector<>::end() need not be called
*	as in STL fashion where the final iterator is passed to the argument.
*	
*	Lesson reminder: Iterators in the C++ standard library are not convertible to bool as to keep them lightweight.
* 
*	Section 2: find is implemented and tested in STL fashion with the above lesson applied in handling the function.
*/

#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename It, typename T>
int my_count(It begin, It end, T val) {
	int cnt{ 0 };
	while (begin != end) {
		if (val == *begin)
			++cnt;
		++begin;
	}
	return cnt;
}


template <typename It, typename Pred>
int my_count_if(It begin, It end, Pred p) {
	int cnt{ 0 };
	while (begin != end) {
		if (p(*begin))
			++cnt;
		++begin;
	}
	return cnt;
}

template <typename It, typename T>
It my_find(It begin, It end, T val) {
	while (begin != end) {
		if (val == *begin)
			return begin;
		++begin;
	}
	return begin;
}

int main() {

	std::cout << "Section 1: Both count and countif are implemented in a way that std::list<>::end() and std::vector<>::end() need not be called but may be passed as an argument:\n";
	std::vector<int> vect{ 5,50,5,100,5 };
	std::list<std::string> list{ "alpha", "bravo", "alpha", "alpha", "zulu" };
	
	auto end_ptr_for_vect = vect.begin() + vect.size();

	auto end_ptr_for_list = list.begin();
	for (int i = 0; i < list.size(); i++) ++end_ptr_for_list;
	

	std::cout << "The count_if should return three of int(5) in vect :\n";
	std::cout << my_count_if(vect.begin(), end_ptr_for_vect, [](int a) { return a == 5; }) << std::endl;
	std::cout << "The count_if should return three of std::string(\"alpha\") in list : \n";
	std::cout << my_count_if(list.begin(), end_ptr_for_list, [](std::string a) { return a == "alpha"; }) << std::endl;

	std::cout << "The count should return three of int(5) in vect :\n";
	std::cout << my_count(vect.begin(), end_ptr_for_vect, 5) << std::endl;
	std::cout << "The count should return three of std::string(\"alpha\") in list : \n";
	std::cout << my_count(list.begin(), end_ptr_for_list, "alpha") << std::endl;

	std::cout << std::endl;

	std::cout << "Section 2: find is tested on either list with the iterator printed:\n";
	std::cout << "Perform find(..) on vect for int(5):\n";
	std::cout << *my_find(vect.begin(), end_ptr_for_vect, 5) << std::endl;
	std::cout << "Perform find(..) on list for std::string(\"alpha\"):\n";
	std::cout << *my_find(list.begin(), end_ptr_for_list, "alpha") << std::endl;
	std::cout << "Perform find(..) on list for non existant std::string(\"red\"):\n";
	if (my_find(list.begin(), end_ptr_for_list, "red") != list.end())
		std::cout << *my_find(list.begin(), end_ptr_for_list, "red") << std::endl;
	else
		std::cout << "Iterator checked to be invalid.\n";


	return 0;
}