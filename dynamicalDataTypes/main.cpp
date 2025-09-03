#include <iostream>
#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include <vector>

int main() {

	DoublyList<int> list;

	list.push_back(5);
	list.push_back(2);
	list.push_back(1);
	list.push_back(8);

	list.pop_front();

	std::cout << list.size();

}