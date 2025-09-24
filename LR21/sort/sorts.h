#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <list>
#include <iterator>
#include "person.h"

struct Metrics {
    size_t comparisons = 0;
    size_t swaps = 0;
    size_t passes = 0;
};

bool compareByName(const Person& a, const Person& b);
bool compareByAge(const Person& a, const Person& b);

template <class Iterator, class Compare>
void merge(Iterator begin, Iterator mid, Iterator end, Metrics& metrics, Compare cmp) {
    typedef typename std::iterator_traits<Iterator>::value_type ValueType;

    std::list<ValueType> temp;
    Iterator left = begin;
    Iterator right = mid;

    while (left != mid && right != end) {
        metrics.comparisons++;
        if (cmp(*right, *left)) {
            temp.push_back(*right);
            ++right;
        } else {
            temp.push_back(*left);
            ++left;
        }
    }

    while (left != mid) { temp.push_back(*left); ++left; }
    while (right != end) { temp.push_back(*right); ++right; }

    std::copy(temp.begin(), temp.end(), begin);
    metrics.passes++;
}

template <class Iterator, class Compare>
void mergeSort(Iterator begin, Iterator end, Metrics& metrics, Compare cmp) {
    size_t len = std::distance(begin, end);
    if (len <= 1) return;

    Iterator mid = begin;
    std::advance(mid, len / 2);

    mergeSort(begin, mid, metrics, cmp);
    mergeSort(mid, end, metrics, cmp);
    merge(begin, mid, end, metrics, cmp);
}

template <class Iterator, class Compare>
void bubbleSort(Iterator begin, Iterator end, Metrics& metrics, Compare cmp) {
    bool swapped;
    do {
        swapped = false;
        metrics.passes++;
        for (Iterator it = begin; it != end; ++it) {
            Iterator next = it; ++next;
            if (next == end) break;

            metrics.comparisons++;
            if (cmp(*next, *it)) {
                std::iter_swap(it, next);
                metrics.swaps++;
                swapped = true;
            }
        }
    } while (swapped);
}

template <class Iterator, class Compare>
void insertionSort(Iterator begin, Iterator end, Metrics& metrics, Compare cmp) {
    typedef typename std::iterator_traits<Iterator>::value_type ValueType;

    for (Iterator it = begin; it != end; ++it) {
        ValueType key = *it;
        Iterator j = it;

        while (j != begin) {
            Iterator prev = std::prev(j);
            metrics.comparisons++;
            if (cmp(key, *prev)) {
                *j = *prev;
                metrics.swaps++;
                --j;
            } else {
                break;
            }
        }
        *j = key;
        metrics.passes++;
    }
}

#endif // SORTS_H