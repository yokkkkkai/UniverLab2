#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <exception>

/*
operator>>, operator<< +
operator+ +, operator-
replace +
sort 
*/

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
    ~DoubleList();

    void push_back(T value);
    void push_front(T value);
    size_t size() const;
    void find_and_erase(const T& value);
    T at(size_t index) const;
    void print() const;
    void clear();
    void replace(T old_value, T new_value);
    bool contains(T value) const;
    void sort();

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const DoubleList<U>& obj);

    template <typename U>
    friend std::istream& operator>>(std::istream& in, DoubleList<U>& obj);

    DoubleList<T> operator+(const DoubleList<T>& other) const;
    DoubleList<T> operator-(const DoubleList<T>& other) const;
};

template <typename T>
Node<T>::Node(T value) : data(value), next(nullptr), prev(nullptr) {}

template <typename T>
DoubleList<T>::DoubleList() : head(nullptr), tail(nullptr), _size(0) {}

template <typename T>
DoubleList<T>::~DoubleList() {
    clear();
}

template <typename T>
void DoubleList<T>::push_back(T value) {
    Node<T>* node = new Node<T>(value);
    if (tail == nullptr) {
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
    if (head == nullptr) {
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

template <typename T>
void DoubleList<T>::clear() {
    if(head == nullptr) {
        return;
    }

    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next_node = current->next;
        delete current;                    
        current = next_node;
    }
    head = nullptr;
    tail = nullptr;
    _size = 0;
}

template <typename T>
void DoubleList<T>::replace(T old_value, T new_value) {
    if(_size == 0) {
        throw std::out_of_range("List is empty!");
    }

    Node<T>* current = head;
    while(current != nullptr) {
        if(current->data == old_value) {
            current->data = new_value;
            return;
        }

        current = current->next;
    }

    throw std::out_of_range("Element not found!");
}

template <typename T>
bool DoubleList<T>::contains(T value) const{
    if(_size == 0) {
        throw std::out_of_range("List is empty!");
    }

    Node<T>* current = head;
    while(current != nullptr) {
        if(current->data == value) 
            return true;
        
        current = current->next;
    }

    return false;
}

template <typename T>
void DoubleList<T>::sort() {
    if (_size < 2) return;

    bool swapped;
    do {
        swapped = false;
        Node<T>* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->data > current->next->data) {
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;

                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

template <typename U>
std::ostream& operator<<(std::ostream& out, const DoubleList<U>& obj) {
    Node<U>* current = obj.head;
    out << "{";
    while(current != nullptr) {
        out << current->data;

        if(current->next != nullptr)
            out << ", ";

        current = current -> next;
    }

    out << "}" << std::endl;
    return out;
}

template <typename U>
std::istream& operator>>(std::istream& in, DoubleList<U>& obj) {
    obj.clear();
    int count = 0;
    U el = 0;
    std::cout << "Enter count of elements: ";
    in >> count;
    for(int i = 0; i < count; i++) {
        in >> el;
        obj.push_back(el);
    }

    obj._size = count;

    return in;
}

template <typename T>
DoubleList<T> DoubleList<T>::operator+(const DoubleList<T>& other) const{
    DoubleList<T> result;
    for(int i = 0; i < this->_size; i++) {
        result.push_back(this->at(i));
    }
    for(int i = 0; i < other._size; i++) {
        result.push_back(other.at(i));
    }

    return result;
}

template <typename T>
DoubleList<T> DoubleList<T>::operator-(const DoubleList<T>& other) const {
    DoubleList<T> result;

    for(size_t i = 0; i < this->size(); i++) {
        T value = this->at(i);
        if(!other.contains(value)) {
            result.push_back(value);
        }
    }

    for(size_t j = 0; j < other.size(); j++) {
        T value = other.at(j);
        if(!this->contains(value)) {
            result.push_back(value);
        }
    }

    return result;
}

#endif