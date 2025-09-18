#include <vector>
#include <iterator>
#include <algorithm>

template <class Iterator>
void merge(Iterator begin, Iterator mid, Iterator end)
{
    typedef typename std::iterator_traits<Iterator>::value_type ValueType;

    Iterator left = begin;
    Iterator right = mid;

    std::vector<ValueType> temp;
    temp.reserve(std::distance(begin, end));

    while (left != mid && right != end)
    {
        if (*right < *left)
        {
            temp.push_back(*right);
            ++right;
        }
        else
        {
            temp.push_back(*left);
            ++left;
        }
    }

    while (left != mid)
    {
        temp.push_back(*left);
        ++left;
    }
    while (right != end)
    {
        temp.push_back(*right);
        ++right;
    }

    std::copy(temp.begin(), temp.end(), begin);
}

template <class Iterator>
void mergeSort(Iterator begin, Iterator end)
{
    size_t distance = std::distance(begin, end);
    if (distance <= 1) return;

    Iterator mid = begin;
    std::advance(mid, distance / 2);

    mergeSort(begin, mid);
    mergeSort(mid, end);

    merge(begin, mid, end);
}
