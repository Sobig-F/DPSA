#include "tree.h"

#define MAIN "1 - прямой обход\n\
2 - симметричный обход\n\
3 - обраный обход\n\
4 - выход\n\
Выбор : "

int main (int argc, char *argv[])
{
    Tree *tree = new Tree();
    if (argc > 0)
    {

        int start = atoi(argv[1]);
        int end = atoi(argv[2]);
        int count = atoi(argv[3]);
    
        tree->random_filling(start, end, count);
    }
    int action = 0;
    while (action != 4)
    {
        cout << MAIN;
        cin >> action;

        switch (action)
        {
        // case 1:
        //     tree->direct();
        //     break;
        // case 2:
        //     tree->simmetric();
        //     break;
        case 1: {
            int element;
            cout << "Enter data: ";
            cin >> element;
            tree->find(element);
            break;
        }
        case 2: {
            int element;
            cout << "Enter data: ";
            cin >> element;
            tree->add(element);
        }
        case 3:
            tree->reverse();
            break;
        case 4:
            tree->simmetric();
            break;
        case 5: {
            int element;
            cout << "Enter data: ";
            cin >> element;
            tree->p_delete(element);
        }
        case 6:
            cout << "Exit. . .";
            break;
        default:
            break;
        }
    }
}