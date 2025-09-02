#include <iostream>
#include "SinglyLinkedList.hpp"
#include <vector>

int main() {

	SinglyList<int> list;

	list.push_back(10);
	list.push_back(5);
	list.push_back(5);

	std::vector<int> vector;

	std::cout << list[2] << "\n";

	bool isEmpty = list.empty();

	std::cout << isEmpty << "\n";


	vector.push_back(2);
	vector.push_back(2);
	vector.push_back(3);

	for (auto& el : vector) {
		std::cout << el << "\n";
	}


	vector.clear();

	for (auto& el : vector) {
		std::cout << el << "\n";
	}




}