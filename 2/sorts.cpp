#include "sorts.hpp"

#include <iostream>
#include <math.h>

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
            permutations += 3;
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
                permutations += 3;
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

    int temp = 0;

    for (int i = 0; i + 1 < size; ++i)
    {
        ++comparisons;
        if (*(array + i) > *(array + i + 1))
        {
            ++permutations;
            temp = *(array + i + 1);
            int j = i;
            while (j >= 0 && *(array + j) > temp)
            {
                ++comparisons;
                ++permutations;
                *(array + j + 1) = *(array + j);
                --j;
            }
            ++permutations;
            *(array + j + 1) = temp;
        }
    }

    std::cout << "Сравнения: " << comparisons << std::endl;
    std::cout << "Перестановки: " << permutations << std::endl;
}

void fast_sort (int *array, int size, int *comparisons, int *permutations, int left, int right, int first)
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

        ++(*comparisons);
        if (left_index <= right_index) {
            *permutations += 3;
            int tmp = *(array + left_index);
            *(array + left_index) = *(array + right_index);
            *(array + right_index) = tmp;
            ++left_index;
            --right_index;
        }
    }

    fast_sort(array, size, comparisons, permutations, left, right_index, 0);
    fast_sort(array, size, comparisons, permutations, left_index, right, 0);

    if (first)
    {
        std::cout << "Сравнения: " << *comparisons << std::endl;
        std::cout << "Перестановки: " << *permutations << std::endl;
    }
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

        permutations += 3;
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
        comparisons += 3;
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

    int temp = 0;

    int start_gap = size / 10 + (size % 10 == 0 ? 0 : 1);
    int step = start_gap / 4 > 0 ? start_gap / 4 : 1;

    for (int gap = start_gap; true; gap = gap - step > 1 ? gap - step : 1)
    {
        for (int i = 0; i + 1 < size; i += gap)
        {
            ++comparisons;
            if (*(array + i) > *(array + i + 1))
            {
                ++permutations;
                temp = *(array + i + 1);
                int j = i;
                while (j >= 0 && *(array + j) > temp)
                {
                    ++comparisons;
                    ++permutations;
                    *(array + j + 1) = *(array + j);
                    --j;
                }
                ++permutations;
                *(array + j + 1) = temp;
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

void pocket_sorting(int *array, int n)
{
    int comparisons = 0;
    int permutations = 0;

    for (int index = 0; index < n; ++index)
    {
        ++comparisons;
        if (*(array + index) != index + 1)
        {
            permutations += 3;
            int temp = *(array + *(array + index) - 1);
            *(array + *(array + index) - 1) = *(array + index);
            *(array + index) = temp;
            
            --index;
        }
    }

    std::cout << "Сравнения: " << comparisons << std::endl;
    std::cout << "Перестановки: " << permutations << std::endl;
}

void pocket_sorting_with_auxiliary_array(int *array, int n)
{
    int comparisons = 0;
    int permutations = n * 2;

    int *auxiliary_array = new int[n];

    for (int i = 0; i < n; ++i)
    {
        *(auxiliary_array + *(array + i) - 1) = *(array + i);
    }

    for (int i = 0; i < n; ++i)
    {
        *(array + i) = *(auxiliary_array + i);
    }

    std::cout << "Сравнения: " << comparisons << std::endl;
    std::cout << "Перестановки: " << permutations << std::endl;
}

void generalized_pocket_sorting(int *array, int n, int size)
{
    int comparisons = 0;
    int permutations = n * 2;

    struct Node
    {
        int index;
        Node* next;
        Node(int index_) : index(index_), next(nullptr) {}
        ~Node()
        {
            if (next != nullptr)
            {
                delete next;
            }
            next = nullptr;
        }
    };

    struct Pocket
    {
        Node* list;
        Node* tail;
        Pocket() : list(nullptr), tail(nullptr) {}
        ~Pocket()
        {
            if (list != nullptr)
            {
                delete list;
                list = nullptr;
                tail = nullptr;
            }
        }
    };
    
    Pocket* pocket = new Pocket[n];
    
    for (int i = 0; i < size; ++i)
    {
        if (pocket[*(array + i) - 1].list == nullptr)
        {
            pocket[*(array + i) - 1].list = new Node(i);
            pocket[*(array + i) - 1].tail = pocket[*(array + i) - 1].list;
        } else
        {
            pocket[*(array + i) - 1].tail->next = new Node(i);
            pocket[*(array + i) - 1].tail = pocket[*(array + i) - 1].tail->next;
        }
    }

    int* result = new int[size];
    int index = 0;

    for (int i = 0; i < n; ++i)
    {
        if (pocket[i].list != nullptr)
        {
            for (Node* current = pocket[i].list; current != nullptr; current = current->next)
            {
                *(result + index) = *(array + current->index);
                ++index;
            }
        }
    }

    delete[] pocket;

    for (int i = 0; i < size; ++i)
    {
        *(array + i) = *(result + i);
    }

    std::cout << "Сравнения: " << comparisons << std::endl;
    std::cout << "Перестановки: " << permutations << std::endl;
}

void bitwise_sorting(int *array, int size, int k)
{
    int comparisons = 0;
    int permutations = size * 2 * k;

    struct Node
    {
        int data;
        Node* next;
        Node(int data_) : data(data_), next(nullptr) {}
        ~Node()
        {
            if (next != nullptr)
            {
                delete next;
                next = nullptr;
            }
        }
    };

    struct Pocket
    {
        Node* list;
        Node* tail;
        Pocket() : list(nullptr), tail(nullptr) {}
        ~Pocket()
        {
            if (list != nullptr)
            {
                delete list;
                list = nullptr;
                tail = nullptr;
            }
        }
    };

    Pocket* pocket = new Pocket[10];
    int figure;

    for (int i = 1; i <= k; ++i)
    {
        for (int index = 0; index < size; ++index)
        {
            figure = (*(array + index) % (int)pow(10, i)) / (i == 1 ? 1 : (pow(10, i - 1)));

            if (pocket[figure].list == nullptr)
            {
                pocket[figure].list = new Node(*(array + index));
                pocket[figure].tail = pocket[figure].list;
            } else
            {
                pocket[figure].tail->next = new Node(*(array + index));
                pocket[figure].tail = pocket[figure].tail->next;
            }
        }

        int index = 0;

        for (int j = 0; j < 10; ++j)
        {
            if (pocket[j].list != nullptr)
            {
                for (Node* current = pocket[j].list; current != nullptr; current = current->next)
                {
                    *(array + index) = current->data;
                    ++index;
                }
            }
            delete pocket[j].list;
            pocket[j].list = nullptr;
            pocket[j].tail = nullptr;
        }
    }

    std::cout << "Сравнения: " << comparisons << std::endl;
    std::cout << "Перестановки: " << permutations << std::endl;
}

bool check_result(int *array, int size)
{
    for (int i = 0; i + 1 < size; ++i)
    {
        if (*(array + i) > *(array + i + 1))
        {
            return false;
        }
    }

    return true;
}

void print_array (int *array, int count)
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << *(array + i) << " ";
    }

    std::cout << std::endl;
}

int* generate_unique_array(int n)
{
    int* array = new int[n];

    for (int i = 0; i < n; ++i)
    {
        *(array + i) = i + 1;
    }

    srand(time(0));

    for (int i = 0; i < n; ++i)
    {
        int j = rand() % n;

        if (i != j)
        {
            *(array + i) += *(array + j);
            *(array + j) = *(array + i) - *(array + j);
            *(array + i) -= *(array + j);
        }
    }

    return array;
}

int* generate_array(int n, int size)
{
    int* array = new int[size];

    srand(time(0));

    for (int i = 0; i < size; ++i)
    {
        *(array + i) = rand() % n + 1;
    }

    return array;
}

int* random_filling (int start, int end, int count)
{
    int *result = new int[count];

    srand(time(0));

    int determ = (end - start + 1);

    for (int i = 0; i < count; ++i)
    {
        result[i] = rand() % determ + start;
    }

    return result;
}