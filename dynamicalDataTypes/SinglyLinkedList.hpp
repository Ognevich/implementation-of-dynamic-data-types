#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

template <typename T>
class SinglyList {
public:
    SinglyList();
    ~SinglyList();

    void push_back(T data);
    int size();
    bool empty();
    void clear();
    void pop_front();
    void pop_back();
    void push_front(T data);
    void insert(T data, int index);
    void removeAt(int index);

    T& operator[](const int index);


private:
    class Node {
    public:
        Node* pNext;
        T data;
        Node(T data = T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node* head;
};



template <typename T>
inline SinglyList<T>::SinglyList() {
    Size = 0;
    head = nullptr;
}

template <typename T>
inline SinglyList<T>::~SinglyList() {
    clear();
}

template<typename T>
inline void SinglyList<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node(data);
    }
    else {
        Node* current = head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    Size++;
}

template <typename T>
inline int SinglyList<T>::size() {
    return Size;
}

template<typename T>
inline T& SinglyList<T>::operator[](const int index)
{

    int tempSize = 0;
    Node * current = this->head;

    while (current != nullptr) {
        if (tempSize == index) {
            return current->data;
        }
        tempSize++;
        current = current->pNext;
    }

}

template <typename T>
inline bool SinglyList<T>::empty() {
    return true ? Size == 0 : false;
}

template <typename T>
inline void SinglyList<T>::clear() {
    while (Size)
        pop_front();

}

template <typename T>
inline void SinglyList<T>::pop_front() {
    Node* temp = head;

    head = head->pNext;

    delete temp;

    Size--;
}

template <typename T>
inline void SinglyList<T>::push_front(T data) {

    Node* head = new Node(data, this->head);
    Size++;

}

template <typename T>
inline void SinglyList<T>::insert(T data, int index) {
    if (index == 0)
    {
        push_front(data);
    }
    else {
        Node* previous = this->head;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }
        Node* newNode = new Node(data, previous->pNext);
        previous->pNext = newNode;

        Size++;
    }

}

template <typename T>
inline void SinglyList<T>::removeAt(int index) {
    if (index < 0 || index >= Size) {
        throw std::out_of_range("Index out of range");
    }

    if (index == 0) {
        pop_front();
        return;
    }

    Node* previous = this->head;
   
    for (int i = 0; i < index - 1; i++) {
        previous = previous->pNext;
    }

    Node* current = previous->pNext;   
    previous->pNext = current->pNext; 

    delete current;
    Size--;
}

template <typename T>
inline void SinglyList<T>::pop_back() {

    removeAt(Size - 1);

}

#endif
