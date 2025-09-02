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
    while (head != nullptr) {
        Node* temp = head;
        head = head->pNext;
        delete temp;
    }
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
    if (this->head == nullptr) {
        return;
    }
}

#endif
