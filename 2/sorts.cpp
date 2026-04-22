#include "sorts.hpp"

#include <iostream>

void sorting_by_choice (int *array, int size)
{
    int comparisons = 0;
    int permutations = 0;

    int min_index = 0;
    for (int i = 0; i + 1 < size; ++i)
    {
        min_index = i;
        for (int j = i + 1; j < size; ++j)
        {
            ++comparisons;
            if (*(array + j) < *(array + min_index))
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            ++permutations;
            *(array + min_index) += *(array + i);
            *(array + i) = *(array + min_index) - *(array + i);
            *(array + min_index) -= *(array + i);
        }
    }

    std::cout << "Сравнения: " << comparisons << std::endl;
    std::cout << "Перестановки: " << permutations << std::endl;
}

void sorting_by_exchange (int *array, int size)
{
    int comparisons = 0;
    int permutations = 0;

    for (int i = 0; i + 1 < size; ++i)
    {
        for (int j = 0; j + i + 1 < size; ++j)
        {
            ++comparisons;
            if (*(array + j) > *(array + j + 1))
            {
                ++permutations;
                *(array + j) += *(array + j + 1);
                *(array + j + 1) = *(array + j) - *(array + j + 1);
                *(array + j) = *(array + j) - *(array + j + 1);
            }
        }
    }

    std::cout << "Сравнения: " << comparisons << std::endl;
    std::cout << "Перестановки: " << permutations << std::endl;
}

void sorting_by_inserts (int *array, int size)
{
    int comparisons = 0;
    int permutations = 0;

    for (int i = 0; i + 1 < size; ++i)
    {
        ++comparisons;
        if (*(array + i) > *(array + i + 1))
        {
            for (int j = i + 1; j > 0 && *(array + j - 1) > *(array + j); --j)
            {
                ++permutations;
                *(array + j) += *(array + j - 1);
                *(array + j - 1) = *(array + j) - *(array + j - 1);
                *(array + j) = *(array + j) - *(array + j - 1);
            }
        }
    }

    std::cout << "Сравнения: " << comparisons << std::endl;
    std::cout << "Перестановки: " << permutations << std::endl;
}

void fast_sort (int *array, int size, int left, int right)
{
    if (right == -1)
    {
        right = size - 1;
    }

    if (left >= right) return;

    int pivot = *(array + left + (right - left) / 2);
    int left_index = left;
    int right_index = right;

    while (left_index <= right_index) {
        while (*(array + left_index) < pivot) { ++left_index; }

        while (*(array + right_index) > pivot) { --right_index; }

        if (left_index <= right_index) {
            int tmp = *(array + left_index);
            *(array + left_index) = *(array + right_index);
            *(array + right_index) = tmp;
            ++left_index;
            --right_index;
        }
    }

    fast_sort(array, size, left, right_index);
    fast_sort(array, size, left_index, right);
}

std::pair<int, int> siftDown(int* array, int size, int root) {
    int largest = 0;
    int left = 0;
    int right = 0;
    int tmp = 0;

    int comparisons = 0;
    int permutations = 0;

    while (1) {
        largest = root;
        left  = 2 * root + 1;
        right = 2 * root + 2;

        if (left < size && *(array + left) > *(array + largest)) { largest = left; }
            
        if (right < size && *(array + right) > *(array + largest)) { largest = right; }
        
        comparisons += 2;

        if (largest == root) { break; };

        ++permutations;
        tmp = *(array + root);
        *(array + root) = *(array + largest);
        *(array + largest) = tmp;

        root = largest;
    }

    return std::make_pair(comparisons, permutations);
}

void piramidal_sort (int *array, int size)
{
    int comparisons = 0;
    int permutations = 0;

    std::pair<int, int> temp;

    if (size <= 1) { return; }

    for (int i = size / 2 - 1; i >= 0; --i)
    {
        temp = siftDown(array, size, i);
        comparisons += temp.first;
        permutations += temp.second;
    }

    for (int i = size - 1; i > 0; --i)
    {
        int tmp = *array;
        *array = *(array + i);
        *(array + i) = tmp;

        temp = siftDown(array, i, 0);
        comparisons += temp.first;
        permutations += temp.second;
    }

    std::cout << "Сравнения: " << comparisons << std::endl;
    std::cout << "Перестановки: " << permutations << std::endl;
}

void shell_sort (int *array, int size)
{
    int comparisons = 0;
    int permutations = 0;

    int start_gap = size / 10 + (size % 10 == 0 ? 0 : 1);
    int step = start_gap / 4 > 0 ? start_gap / 4 : 1;

    for (int gap = start_gap; true; gap = gap - step > 1 ? gap - step : 1)
    {
        for (int i = 0; i + gap < size; i += gap)
        {
            ++comparisons;
            if (*(array + i) > *(array + i + gap))
            {
                for (int j = i + gap; j > 0 && *(array + j - gap) > *(array + j); j -= gap)
                {
                    ++permutations;
                    *(array + j) += *(array + j - gap);
                    *(array + j - gap) = *(array + j) - *(array + j - gap);
                    *(array + j) = *(array + j) - *(array + j - gap);
                }
            }
        }
        if (gap == 1)
        {
            break;
        }
    }

    std::cout << "Сравнения: " << comparisons << std::endl;
    std::cout << "Перестановки: " << permutations << std::endl;
}