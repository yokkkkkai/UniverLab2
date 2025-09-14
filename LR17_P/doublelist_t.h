#include <exception>
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T value) : data(value), head(nullptr), tail(nullptr) {}
};

template <typename T>
class DoubleList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
public:
    DoubleList(T value) {
        Node<T> node = new Node<T>(value);
        head = tail = node;
    }


    void push_back(T value) {
        Node<T>* node = new Node(value);
        if(!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }   
        size++;
    }


    void push_front(T value) {
        Node<T>* node = new Node(value);
        if(!head) {
            head = tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }
        size++;
    }

    size_t size() {
        return size;
    }

    template <typename T>
    void find_and_erase(const T& value) {
        if (size == 0) {
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
                size--;
                return;
            }
            current = current->next;
        }

        throw std::out_of_range("Element not found");
    }

    T at(size_t index) {
        if(index >= size) {
            throw std::out_of_range("Index out of range!");
        }

        Node<T>* current = head;
        size_t cnt = 0;
        while(cnt != index) {
            current = current->next;
            cnt++;
        }

        return current->data;
    }
};