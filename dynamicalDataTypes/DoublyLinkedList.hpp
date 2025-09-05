#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP
#include <stdexcept>

template <typename T>
class DoublyList {
public:
	DoublyList();
	~DoublyList();

	void push_back(const T value);
	void push_front(const T value);
	int size();
	bool empty();
	void pop_front();
	void pop_back();
	void clear();
	void insert(T value, int index);
	void removeAt(int index);

	T& operator[](const int index);


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
	clear();
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

template <typename T>
inline T& DoublyList<T>::operator[](const int index) {
	if (index < 0 || index >= Size) {
		throw std::out_of_range("Index out of range");
	}

	int tempSize = 0;
	Node* current = this->head;

	while (current != nullptr) {
		if (tempSize == index) {
			return current->data;
		}
		tempSize++;
		current = current->pNext;
	}
	throw std::out_of_range("Index not found");
}

template <typename T>
inline void DoublyList<T>::pop_back() {
	if (Size == 0) {
		throw std::runtime_error("List is empty, cannot pop_back");
	}

	if (Size == 1) {
		pop_front();
		return;
	}

	Node* deleteElem = tail;
	tail = tail->pPrev;
	tail->pNext = nullptr;

	delete deleteElem;
	Size--;
}

template <typename T>
inline void DoublyList<T>::push_front(const T value) {
	if (head == nullptr)
	{
		push_back(value);
		return;
	}

	Node* newNode = new Node(value, nullptr, head);
	head->pPrev = newNode;
	head = newNode;


	Size++;
}

template <typename T>
inline void DoublyList<T>::insert(T value, int index) {
	if (index < 0 || index > Size) {
		throw std::out_of_range("Index out of range");
	}

	if (index == 0) {
		push_front(value);
		return;
	}

	if (index == Size) {
		push_back(value);
		return;
	}

	int center = Size / 2;

	if (index <= center) {
		Node* current = head;
		for (int i = 0; i < index; i++) {
			current = current->pNext;
		}

		Node* newNode = new Node(value, current->pPrev, current);
		current->pPrev->pNext = newNode;
		current->pPrev = newNode;
	}
	else {
		Node* current = tail;
		for (int i = Size - 1; i > index; i--) {
			current = current->pPrev;
		}

		Node* newNode = new Node(value, current->pPrev, current);
		current->pPrev->pNext = newNode;
		current->pPrev = newNode;
	}

	Size++;
}

template <typename T>
inline void DoublyList<T>::removeAt(int index) {
	if (index < 0 || index >= Size) {
		throw std::out_of_range("Index out of range");
	}

	if (index == 0) {
		pop_front();
		return;
	}
	if (index == Size - 1) {
		pop_back();
		return;
	}

	int center = Size / 2;

	Node* deleteElem = nullptr;

	if (index <= center) {
		deleteElem = head;
		for (int i = 0; i < index; i++) {
			deleteElem = deleteElem->pNext;
		}
	}
	else {
		deleteElem = tail;
		for (int i = Size - 1; i > index; i--) {
			deleteElem = deleteElem->pPrev;
		}
	}
	deleteElem->pPrev->pNext = deleteElem->pNext;
	deleteElem->pNext->pPrev = deleteElem->pPrev;

	delete deleteElem;
	Size--;
}

template <typename T>
inline void DoublyList<T>::clear() {

	while (Size)
		pop_front();
}
#endif


