#include "tree.h"

#define MAIN "1 - get size\n\
2 - random filling\n\
3 - direct bypass\n\
4 - symmetric bypass\n\
5 - symmetric bypass 2\n\
6 - reverse bypass\n\
7 - Exit\n\
Choice : "

int main (int argc, char *argv[])
{
    Tree *tree = new Tree();

    int action = 0;

    while (action != 7)
    {
        cout << MAIN;
        cin >> action;

        switch (action)
        {
        case 1: {
            int size = tree->get_size();
            cout << size << endl;
            break;
        }
        case 2: {
            int count;
            cout << "Enter count: ";
            cin >> count;
            tree->random_filling(0, 100, count);
            break;
        }
        case 3:
            tree->direct();
            break;
        case 4:
            tree->simmetric();
            break;
        case 5:
            tree->simmetric_r();
            break;
        case 6:
            tree->reverse();
            break;
        case 7:
            cout << "Exit. . .";
            break;
        default:
            break;
        }
    }
}