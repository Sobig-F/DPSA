#include <iostream>

#ifdef _WIN32
    #include <windows.h>
#endif

#include <ctime>
#include <math.h>

#include "../sorts.hpp"

#define MAIN "1 - карманная сортировка\n\
2 - карманная сортировка с вспомогательным массивом\n\
3 - обобщенная карманная сортировка\n\
4 - поразрядная сортировка\n\
5 - выход\n\
Выбор : "

int main()
{
    #ifdef _WIN32
        system("chcp 65001 > nul");
        SetConsoleOutputCP(CP_UTF8);
    #endif

    int action = 0;
    int *array = nullptr;
    int n, size;

    while (action != 5)
    {
        if (array != nullptr)
        {
            delete[] array;
            array = nullptr;
        }

        std::cout << MAIN;
        std::cin >> action;

        if (action == 5) { break; }

        switch (action)
        {
        case 1:
            std::cout << "Кол-во элементов: ";
            std::cin >> size;
            
            array = generate_unique_array(size);
            
            print_array(array, size);
            pocket_sorting(array, size);
            print_array(array, size);
            
            if (check_result(array, size)) { std::cout << "Успешно" << std::endl; }
            else { std::cout << "Ошибка" << std::endl; }
            
            break;
        case 2:
            std::cout << "Кол-во элементов: ";
            std::cin >> size;
            
            array = generate_unique_array(size);
            
            print_array(array, size);
            pocket_sorting_with_auxiliary_array(array, size);
            print_array(array, size);
            
            if (check_result(array, size)) { std::cout << "Успешно" << std::endl; }
            else { std::cout << "Ошибка" << std::endl; }
            
            break;
        case 3:
            std::cout << "Кол-во элементов: ";
            std::cin >> size;
            std::cout << "N = ";
            std::cin >> n;
            
            array = generate_array(n, size);
            
            print_array(array, size);
            generalized_pocket_sorting(array, n, size);
            print_array(array, size);
            
            if (check_result(array, size)) { std::cout << "Успешно" << std::endl; }
            else { std::cout << "Ошибка" << std::endl; }
            
            break;
        case 4:
        {
            int k;
            std::cout << "Кол-во элементов: ";
            std::cin >> size;
            std::cout << "K = ";
            std::cin >> k;
            
            array = generate_array(pow(10, k), size);
            
            print_array(array, size);
            bitwise_sorting(array, size, k);
            print_array(array, size);
            
            if (check_result(array, size)) { std::cout << "Успешно" << std::endl; }
            else { std::cout << "Ошибка" << std::endl; }
            
            break;
        }
        default:
            break;
        }
    }
}