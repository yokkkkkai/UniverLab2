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
    SortedArray(size_t capacity)
    {
        this->capacity = capacity;
        _size = 0;
        array = new T[capacity];
    }

    ~SortedArray()
    {
        delete[] array;
    }

    SortedArray(const SortedArray &other)
    {
        capacity = other.capacity;
        _size = other._size;
        array = new T[capacity];
        for (size_t i = 0; i < _size; i++)
            array[i] = other.array[i];
    }

    SortedArray& operator=(const SortedArray &other)
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

    SortedArray& operator+(const SortedArray& other) 
    {
        size_t new_size = size + other.size;
        if(new_size > capacity)
        {
            throw std::out_of_range("Concatenation error! Size limit!");
        }

        T *ptr = new T[new_size]

    }

    void push(T value)
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

    void erase(size_t index)
    {
        if (index >= _size)
            throw std::out_of_range("Index out of range");

        for (size_t i = index; i < _size - 1; i++)
            array[i] = array[i + 1];

        _size--;
    }

    size_t size() const
    {
        return _size;
    }

    T operator[](size_t index) const
    {
        return array[index];
    }

    T at(size_t index) const
    {
        if (index >= _size)
            throw std::out_of_range("Index out of range");

        return array[index];
    }

    void print() const
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
};

#endif