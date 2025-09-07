#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include <iostream>
#include <exception>

template <typename T>
class SortedArray
{
private:
    size_t capacity;
    size_t _size;
    T *array;

public:
    SortedArray(size_t capacity);
    ~SortedArray();
    SortedArray(const SortedArray &other);
    SortedArray& operator=(const SortedArray &other);

    SortedArray& operator+(const SortedArray& other);
    SortedArray operator-(const SortedArray& other) const;
    T operator[](size_t index) const;

    void push(T value);
    void erase(size_t index);
    size_t size() const;
    T at(size_t index) const;
    void print() const;
};

// ================= Реализации =================

template <typename T>
SortedArray<T>::SortedArray(size_t capacity)
{
    this->capacity = capacity;
    _size = 0;
    array = new T[capacity];
}

template <typename T>
SortedArray<T>::~SortedArray()
{
    delete[] array;
}

template <typename T>
SortedArray<T>::SortedArray(const SortedArray &other)
{
    capacity = other.capacity;
    _size = other._size;
    array = new T[capacity];
    for (size_t i = 0; i < _size; i++)
        array[i] = other.array[i];
}

template <typename T>
SortedArray<T>& SortedArray<T>::operator=(const SortedArray &other)
{
    if (this == &other)
        return *this;

    delete[] array;
    capacity = other.capacity;
    _size = other._size;
    array = new T[capacity];
    for (size_t i = 0; i < _size; i++)
        array[i] = other.array[i];

    return *this;
}

template <typename T>
SortedArray<T>& SortedArray<T>::operator+(const SortedArray& other)
{
    size_t new_size = _size + other._size;
    if (new_size > capacity)
        throw std::out_of_range("Concatenation error! Size limit!");

    T* new_array = new T[new_size];
    for (size_t i = 0; i < _size; i++)
        new_array[i] = array[i];
    for (size_t j = 0; j < other._size; j++)
        new_array[_size + j] = other.array[j];

    delete[] array;
    array = new_array;
    _size = new_size;

    return *this;
}

template <typename T>
SortedArray<T> SortedArray<T>::operator-(const SortedArray& other) const
{
    SortedArray<T> result(capacity);

    for (size_t i = 0; i < _size; i++)
    {
        bool found = false;
        for (size_t j = 0; j < other._size; j++)
        {
            if (array[i] == other.array[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
            result.push(array[i]);
    }

    return result;
}

template <typename T>
T SortedArray<T>::operator[](size_t index) const
{
    return array[index];
}

template <typename T>
void SortedArray<T>::push(T value)
{
    if (_size >= capacity)
        throw std::out_of_range("Array is full");

    if (_size == 0)
    {
        array[0] = value;
        _size++;
        return;
    }

    size_t pos = 0;
    while (pos < _size && array[pos] < value)
        pos++;

    for (size_t i = _size; i > pos; i--)
        array[i] = array[i - 1];

    array[pos] = value;
    _size++;
}

template <typename T>
void SortedArray<T>::erase(size_t index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");

    for (size_t i = index; i < _size - 1; i++)
        array[i] = array[i + 1];

    _size--;
}

template <typename T>
size_t SortedArray<T>::size() const
{
    return _size;
}

template <typename T>
T SortedArray<T>::at(size_t index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");

    return array[index];
}

template <typename T>
void SortedArray<T>::print() const
{
    std::cout << '[';
    for (size_t i = 0; i < _size; i++) 
    {
        std::cout << array[i];
        if(i != _size - 1) 
            std::cout << ", ";
    }
    std::cout << "]\n";
}

#endif