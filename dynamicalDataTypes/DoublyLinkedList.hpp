#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP
#include <stdexcept>

template <typename T>
class DoublyList {
public:
	DoublyList();
	~DoublyList();

	void push_back(const T value);
	int size();
	bool empty();
	void pop_front();

private:
	class Node {
	public:
		T data;
		Node* pPrev;
		Node* pNext;

		Node(T data = T(), Node* pPrev = nullptr, Node* pNext = nullptr) {

			this->data = data;
			this->pPrev = pPrev;
			this->pNext = pNext;

		}
	};

	int Size;
	Node* head;
	Node* tail;

};

template<typename T>
inline DoublyList<T>::DoublyList()
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
inline DoublyList<T>::~DoublyList()
{
}

template <typename T>
inline void DoublyList<T>::push_back(const T value) {

	if (head == nullptr) {
		head = new Node(value);
		tail = head;
	}
	else {
		Node* newNode = new Node(value, tail, nullptr);

		tail->pNext = newNode;
		tail = newNode;
	}
	Size++;
}

template <typename T>
inline int DoublyList<T>::size() {
	return Size;
}

template <typename T>
inline bool DoublyList<T>::empty() {
	return true ? Size == 0 : false;
}

template <typename T>
inline void DoublyList<T>::pop_front() {
	if (head == nullptr) {
		throw std::runtime_error("List is empty, cannot pop_front");
	}

	Node* temp = head;
	head = head->pNext;

	if (head != nullptr) {
		head->pPrev = nullptr;
	}
	else {
		tail = nullptr;
	}

	delete temp;
	Size--;
}
#endif


