#include "list.hpp"

#define CHOICE_MAIN_ACTION "1 - push after\n\
2 - push before\n\
3 - delete\n\
4 - find by start\n\
5 - find by end\n\
6 - print by start\n\
7 - print by end\n\
8 - is empty\n\
9 - exit\n\
Choise: "

int main()
{
    List list;
    int element;
    int main_action = 0;
    while (main_action != 9) {
        std::cout << CHOICE_MAIN_ACTION;
        std::cin >> main_action;
        switch (main_action)
        {
        case 1: {
            int before_element = 0;

            std::cout << "Enter before element : ";
            std::cin >> before_element;

            std::cout << "Enter push element : ";
            std::cin >> element;

            list.AddAfter(element, before_element);

            break;
        }
        case 2: {
            int after_element = 0;

            std::cout << "Enter after element : ";
            std::cin >> after_element;

            std::cout << "Enter push element : ";
            std::cin >> element;

            list.AddBefore(element, after_element);

            break;
        }
        case 3: {
            std::cout << "Enter delete element : ";
            std::cin >> element;

            list.del(element);

            break;
        }
        case 4: {
            std::cout << "Enter find element : ";
            std::cin >> element;
            int result = list.ForwardFind(element);
            if (result >= 0) {
                std::cout << "Index - " << result << std::endl;
            } else {
                std::cout << "Not found" << std::endl;
            }

            break;
        }
        case 5: {
            std::cout << "Enter find element : ";
            std::cin >> element;
            int result = list.OppositeFind(element);
            if (result >= 0) {
                std::cout << "Index - " << result << std::endl;
            } else {
                std::cout << "Not found" << std::endl;
            }

            break;
        }
        case 6:
            list.ForwardView();
            break;
        case 7:
            list.OppositeView();
            break;
        case 8:
            if (list.Empty()) {
                std::cout << "Empty" << std::endl;
            } else {
                std::cout << "Not empty" << std::endl;
            }
            
            break;
        case 9:
            std::cout << "Exit..." << std::endl;
            break;
        default:
            break;
        }
    }
}