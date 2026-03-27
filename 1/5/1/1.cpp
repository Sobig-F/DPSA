#include <iostream>

#include "Node.hpp"

#define MAIN "1 - random filling\n\
2 - direct bypass\n\
3 - symmetric bypass\n\
4 - reverse bypass\n\
5 - Exit\n\
Choice : "

int main (int argc, char *argv[])
{
    Tree *tree = nullptr;

    int action = 0;

    while (action != 5)
    {
        std::cout << MAIN;
        std::cin >> action;

        switch (action)
        {
        case 1: {
            int count;
            std::cout << "Enter count: ";
            std::cin >> count;
            srand(time(0));
            tree = random_filling(tree, 0, 100, count);
            break;
        }
        case 2:
            direct(tree, 0);
            break;
        case 3:
            simmetric(tree, 0);
            break;
        case 4:
            reverse(tree, 0);
            break;
        case 5:
            std::cout << "Exit. . .";
            break;
        default:
            break;
        }
    }
}