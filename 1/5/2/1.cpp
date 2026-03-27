#include "Node.hpp"

#include <iostream>

#define MAIN "1 - random filling\n\
2 - direct bypass\n\
3 - symmetric bypass\n\
4 - symmetric bypass 2\n\
5 - reverse bypass\n\
6 - Exit\n\
Choice : "

int main (int argc, char *argv[])
{
    Tree *tree = new Tree();

    int action = 0;

    while (action != 6)
    {
        std::cout << MAIN;
        std::cin >> action;

        switch (action)
        {
        case 1: {
            int count;
            std::cout << "Enter count: ";
            std::cin >> count;
            random_filling(tree, 0, 100, count);
            break;
        }
        case 2:
            direct(tree, 0);
            break;
        case 3:
            simmetric_r(tree, 0);
            break;
        case 4:
            simmetric(tree);
            break;
        case 5:
            reverse(tree, 0);
            break;
        case 6:
            std::cout << "Exit. . .";
            break;
        default:
            break;
        }
    }
}