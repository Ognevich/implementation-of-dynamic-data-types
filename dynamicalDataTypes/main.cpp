#include <iostream>
#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include <vector>

int main() {

	DoublyList<int> list;

	list.push_back(5);
	list.push_back(2);
	list.push_back(1);
	list.push_front(111);
	list.push_back(8);
	list.insert(10000, 4);

	for (int i = 0; i < list.size(); i++) {
		std::cout << list[i] << "\n";
	}

}