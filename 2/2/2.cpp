#include <iostream>

#ifdef _WIN32
    #include <windows.h>
#endif

#include <ctime>

#include "../sorts.hpp"

#define MAIN "1 - сортировка обменом\n\
2 - сортировка выбором\n\
3 - сортировка вставками\n\
4 - быстрая сортировка\n\
5 - пирамидальная сортировка\n\
6 - сортировка Шелла\n\
7 - выход\n\
Выбор : "

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

void print_array (int *array, int count)
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << *(array + i) << " ";
    }

    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    #ifdef _WIN32
        system("chcp 65001 > nul");
        SetConsoleOutputCP(CP_UTF8);
    #endif

    int start;
    int end;
    int count;

    std::cout << "Start: ";
    std::cin >> start;

    std::cout << "End: ";
    std::cin >> end;

    std::cout << "Count: ";
    std::cin >> count;

    int action = 0;
    int *array = nullptr;

    while (action != 7)
    {
        std::cout << MAIN;
        std::cin >> action;

        if (action == 7)
        {
            break;
        }

        if (array != nullptr)
        {
            delete array;
        }
        array = random_filling(start, end, count);

        print_array(array, count);

        switch (action)
        {
        case 1:
            sorting_by_exchange(array, count);
            break;
        case 2:
            sorting_by_choice(array, count);
            break;
        case 3:
            sorting_by_inserts(array, count);
            break;
        case 4:
        {
            int comparisons = 0;
            int permutations = 0;
            fast_sort(array, count, &comparisons, &permutations);
            break;
        }
        case 5:
            piramidal_sort(array, count);
            break;
        case 6:
            shell_sort(array, count);
            break;
        }

        print_array(array, count);

        if (check_result(array, count))
        {
            std::cout << "Sort success" << std::endl;
        } else 
        {
            std::cout << "Sort failed" << std::endl;
        }
    }
}