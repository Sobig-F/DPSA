#include <ctime>
#include "queue.h"



#define CHOICE_ACTION "1 - checking for queue emptiness\n\
2 - Checking if the queue is full\n\
3 - adding an element\n\
4 - deleting an element\n\
5 - displaying the contents of the queue\n\
6 - exit\n\
Choice: "


int main() {
    Queue *queue = new Queue(5);
    int action = 0, element = 0;
    while (action != 6) {
        cout << CHOICE_ACTION;
        cin >> action;
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
                cout << "Input element: ";
                cin >> element;
                queue->push(element);
                cout << "The element has been added" << endl;
            } else {
                cout << "Queue is full" << endl;
            }
            break;
        case 4:
            if (!queue->is_empty()) {
                queue->del();
                cout << "The element has been deleted" << endl;
            } else {
                cout << "Queue is empty" << endl;
            }
            break;
        case 5:
            queue->print_queue();
            break;
        case 6:
            cout << "Exit" << endl;
            break;
        default:
            break;
        }
    }
}