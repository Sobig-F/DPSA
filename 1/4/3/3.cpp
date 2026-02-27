#include "struct.h"

#define CHOICE_MAIN_ACTION "1 - Print\n\
2 - Find\n\
3 - Add empty list\n\
4 - Add element\n\
5 - Delete element\n\
6 - Del list\n\
7 - exit\n\
Choise: "

int main(int argc, char *argv[]) {
    ListOfLists *list = new ListOfLists();
    int element;
    int main_action = 0;
    while (main_action != 7) {
        cout << CHOICE_MAIN_ACTION;
        cin >> main_action;
        switch (main_action)
        {
        case 1:
            list->print();
            break;
        case 2: {
            cout << "Enter find element : ";
            cin >> element;
            int listIndex, elemIndex;
            list->findElement(element, &listIndex, &elemIndex);
            if (listIndex >= 0) {
                cout << "Element - {" << listIndex << "}[" << elemIndex << "]" << endl;
            } else {
                cout << "Element not found" << endl;
            }
            break;
        }
        case 3: {
            list->addList();
            break;
        }
        case 4: {
            int index;
            int element;
            cout << "Enter list index: ";
            cin >> index;
            cout << "Enter element data: ";
            cin >> element;
            list->addElement(index, element);
            break;
        }
        case 5: {
            // int listIndex, elemIndex;
            // cout << "Enter List index: ";
            // cin >> listIndex;
            // cout << "Enter element index: ";
            // cin >> elemIndex;
            // list->deleteElement(listIndex, elemIndex);

            int data;
            cout << "Enter element: ";
            cin >> data;
            if (list->deleteElement(data)) {
                cout << "Element delete" << endl;
            } else {
                cout << "Element not delete" << endl;
            }
            break;
        }
        case 6: {
            int index;
            cout << "Enter list index: ";
            cin >> index;
            if (list->deleteList(index)) {
                cout << "List delete" << endl;
            } else {
                cout << "List not delete" << endl;
            }

            break;
        }
        case 7:
            cout << "Exit..." << endl;
            break;
        default:
            break;
        }
    }
    delete list;
}