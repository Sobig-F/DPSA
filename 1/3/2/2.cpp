#include <ctime>
#include "list.h"

// #define INT

#define CHOICE_ACTION "1 - checking for queue emptiness\n\
2 - Checking if the queue is full\n\
3 - adding an element\n\
4 - deleting an element\n\
5 - displaying the contents of the queue\n\
6 - find\n\
7 - exit\n\
Choice: "


int main(int argc, char *argv[]) {
    int action = 0;
    if (argc > 1 && atoi(argv[1]) > 0)
    {
        #ifdef INT
        List<int> *queue = new List<int>(atoi(argv[1]));
        int element;
        #else
        List<string> *queue = new List<string>(atoi(argv[1]));
        string element;
        #endif
        while (action != 7) {
            cout << CHOICE_ACTION;

            if (!(cin >> action)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number from 1 to 7." << endl;
                continue;
            }

            switch (action)
            {
            case 1:
                if (queue->is_empty()) {
                    cout << "Empty";
                } else {
                    cout << "Not empty";
                }
                cout << endl;
                break;
            case 2:
                if (queue->is_full()) {
                    cout << "Full";
                } else {
                    cout << "Not full";
                }
                cout << endl;
                break;
            case 3:
                if (!queue->is_full()) {
                    #ifdef INT
                    cout << "Input element: ";
                    #else
                    cout << "Input string: ";
                    #endif
                    cin >> element;
                    if (queue->push(element)) {
                        #ifdef INT
                        cout << "The element has been added" << endl;
                        #else
                        cout << "The string has been added" << endl;
                        #endif
                    }
                } else {
                    cout << "Queue is full" << endl;
                }
                break;
            case 4:
                if (!queue->is_empty()) {
                    cout << "Enter the item you would like to delete : ";
                    cin >> element;
                    if (queue->del(element)) {
                        #ifdef INT
                        cout << "The element has been deleted" << endl;
                        #else
                        cout << "The string has been deleted" << endl;
                        #endif
                    }
                } else {
                    cout << "Queue is empty" << endl;
                }
                break;
            case 5:
                queue->print_queue();
                break;
            case 6: {
                #ifdef INT
                cout << "Input element: ";
                #else
                cout << "Input string: ";
                #endif
                cin >> element;
                if (queue->find_d(element))
                {
                    cout << "Element found\n";
                } else {
                    cout << "Element not found\n";
                }
                break;
            }
            case 7:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Unknown command" << endl;
                break;
            }
        }
    } else {
        cout << "Error count element\nExit . . ." << endl;
    }
}