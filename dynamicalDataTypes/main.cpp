#include <iostream>
#include "SinglyLinkedList.hpp"
#include <vector>

int main() {

	SinglyList<int> list;

	list.push_back(10);
	list.push_back(5);
	list.push_back(7);

	std::vector<int> vector;

	for (int i = 0; i < list.size(); i++) {
		std::cout << list[i] << std::endl;
	}
	
	std::cout << "\n";
	list.pop_back();

	for (int i = 0; i < list.size(); i++) {
		std::cout << list[i] << std::endl;
	}

}