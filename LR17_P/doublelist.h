#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <exception>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T value);
};

template <typename T>
class DoubleList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t _size;

public:
    DoubleList();

    void push_back(T value);
    void push_front(T value);
    size_t size() const;
    void find_and_erase(const T& value);
    T at(size_t index) const;
    void print() const;
};

template <typename T>
Node<T>::Node(T value) : data(value), next(nullptr), prev(nullptr) {}

template <typename T>
DoubleList<T>::DoubleList() : head(nullptr), tail(nullptr), _size(0) {}

template <typename T>
void DoubleList<T>::push_back(T value) {
    Node<T>* node = new Node<T>(value);
    if (!tail) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    _size++;
}

template <typename T>
void DoubleList<T>::push_front(T value) {
    Node<T>* node = new Node<T>(value);
    if (!head) {
        head = tail = node;
    } else {
        head->prev = node;
        node->next = head;
        head = node;
    }
    _size++;
}

template <typename T>
size_t DoubleList<T>::size() const {
    return _size;
}

template <typename T>
void DoubleList<T>::find_and_erase(const T& value) {
    if (_size == 0) {
        throw std::out_of_range("List is empty");
    }

    Node<T>* current = head;

    while (current != nullptr) {
        if (current->data == value) {
            if (current->prev)
                current->prev->next = current->next;
            else
                head = current->next;

            if (current->next)
                current->next->prev = current->prev;
            else
                tail = current->prev;

            delete current;
            _size--;
            return;
        }
        current = current->next;
    }

    throw std::out_of_range("Element not found");
}

template <typename T>
T DoubleList<T>::at(size_t index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of range!");
    }

    Node<T>* current = head;
    size_t cnt = 0;
    while (cnt != index) {
        current = current->next;
        cnt++;
    }

    return current->data;
}

template <typename T>
void DoubleList<T>::print() const {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


#endif
