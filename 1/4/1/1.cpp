#include <ctime>
#include "list.h"

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

int main(int argc, char *argv[]) {
    List *list = new List();
    int element;
    int main_action = 0;
    while (main_action != 9) {
        cout << CHOICE_MAIN_ACTION;
        cin >> main_action;
        switch (main_action)
        {
        case 1: {
            int before_element = 0;

            cout << "Enter before element : ";
            cin >> before_element;

            cout << "Enter push element : ";
            cin >> element;

            if (list->addElementAfter(element, before_element)) {
                cout << "Add" << endl;
            } else {
                cout << "Not add" << endl;
            }

            break;
        }
        case 2: {
            int after_element = 0;

            cout << "Enter after element : ";
            cin >> after_element;

            cout << "Enter push element : ";
            cin >> element;

            if (list->addElementBefore(element, after_element)) {
                cout << "Add" << endl;
            } else {
                cout << "Not add" << endl;
            }

            break;
        }
        case 3: {
            cout << "Enter delete element : ";
            cin >> element;

            if (list->deleteElement(element)) {
                cout << "Delete" << endl;
            } else {
                cout << "Not delete" << endl;
            }

            break;
        }
        case 4: {
            cout << "Enter find element : ";
            cin >> element;

            if (int result = list->findElementStart(element)) {
                cout << "Index - " << result << endl;
            } else {
                cout << "Not found";
            }

            break;
        }
        case 5: {
            cout << "Enter find element : ";
            cin >> element;

            if (int result = list->findElementEnd(element)) {
                cout << "Index - " << result << endl;
            } else {
                cout << "Not found";
            }

            break;
        }
        case 6:
            list->printStart();
            break;
        case 7:
            list->printEnd();
            break;
        case 8:
            if (list->isEmpty()) {
                cout << "Empty" << endl;
            } else {
                cout << "Not empty" << endl;
            }
            
            break;
        case 9:
            cout << "Exit..." << endl;
            break;
        default:
            break;
        }
    }
    delete list;
}