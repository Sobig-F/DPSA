#include <iostream>

#include "Tree.hpp"

#define MENU "\n1 - find\n\
2 - insert recursion\n\
3 - insert\n\
4 - delete node\n\
5 - reverse\n\
6 - simmetric line\n\
7 - randomFill\n\
0 - exit\n"

int main()
{
    Tree *tree = nullptr;
    int action = 1;

    while (action)
    {
        std::cout << MENU"Choice: ";
        std::cin >> action;

        switch (action)
        {
        case 1:
        {
            int target;
            std::cout << "Target: ";
            std::cin >> target;
            std::cout << find(tree, target) << std::endl;
            break;
        }
        case 2:
        {
            int data;
            std::cout << "Data: ";
            std::cin >> data;
            tree = insertRecursion(tree, data);
            break;
        }
        case 3:
        {
            int data;
            std::cout << "Data: ";
            std::cin >> data;
            tree = insert(tree, data);
            break;
        }
        case 4:
        {
            int target;
            std::cout << "Target: ";
            std::cin >> target;
            tree = deleteNode(tree, target);
            break;
        }
        case 5:
        {
            reverse(tree);
            break;
        }
        case 6:
        {
            simmetricLine(tree);
            break;
        }
        case 7:
        {
            int start, end, count;
            std::cout << "Start: ";
            std::cin >> start;
            std::cout << "End: ";
            std::cin >> end;
            std::cout << "Count: ";
            std::cin >> count;
            tree = randomFill(tree, start, end, count);
            break;
        }
            
        default:
            break;
        }
    }

    clean(tree);

    return 0;
}