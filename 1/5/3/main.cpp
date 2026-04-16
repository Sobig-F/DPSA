#include <iostream>

#include "Tree.hpp"

#define MENU "1 - find\n\
2 - insert\n\
3 - clean\n\
4 - reverse\n\
5 - direct\n\
6 - simmetric\n\
0 - exit\n"

int main()
{
    int action = 1;
    Tree *tree = nullptr;
    while (action)
    {
        std::cout << MENU"Choice: ";
        std::cin >> action;

        switch (action)
        {
        case 1:
        {
            int data;
            std::cout << "Target: ";
            std::cin >> data;
            Tree *result = find(tree, data);
            if (result)
            {
                std::cout << "FOUND" << std::endl;
            } else
            {
                std::cout << "NOT FOUND" << std::endl;
            }
            break;
        }
        case 2:
        {
            int target, data, side;
            std::cout << "Target: ";
            std::cin >> target;
            std::cout << "Data: ";
            std::cin >> data;
            std::cout << "Side (0 - left, 1 - right): ";
            std::cin >> side;
            tree = insertBySide(tree, target, data, side);
            break;
        }
        case 3:
            tree = clean(tree);
            break;
        case 4:
            reverse(tree);
            break;
        case 5:
            direct(tree);
            break;
        case 6:
            simmetric(tree);
            break;
        default:
            break;
        }
    }

    tree = clean(tree);

    return 0;
}