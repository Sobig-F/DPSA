#include "tree.h"

#define MAIN "1 - get size\n\
2 - random filling\n\
3 - direct bypass\n\
4 - symmetric bypass\n\
5 - symmetric bypass 2\n\
6 - reverse bypass\n\
7 - find\n\
8 - insert by side\n\
9 - clear tree\n\
10 - Exit\n\
Choice : "

int main (int argc, char *argv[])
{
    Tree *tree = new Tree();

    int action = 0;

    while (action != 10)
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
        case 7: {
            int element;
            cout << "Enter element : ";
            cin >> element;
            Node *result = tree->find(element);
            if (result == nullptr)
            {
                cout << result->data << endl;
            } else {
                cout << "Not found" << endl;
            }
            break;
        }
        case 8: {
            int element;
            int data;
            int side;
            cout << "Enter element: ";
            cin >> element;
            cout << "Enter side (0 - left, 1 - right): ";
            cin >> side;
            cout << "Enter data: ";
            cin >> data;
            int result = tree->push_side(element, side, data);
            if (result)
            {
                tree->simmetric();
            } else {
                cout << "Element not found" << endl;
            }
        }
        case 9:
            tree->clean();
            break;
        case 10:
            cout << "Exit. . .";
            break;
        default:
            break;
        }
    }
}