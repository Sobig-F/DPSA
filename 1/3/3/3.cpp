#include <ctime>
#include "list_sec.h"

#define CHOICE_ACTION_VARIANT(action) cout << "1 - " << action << " by index\n\
2 - " << action << " before element\n\
3 - " << action << " after element\n\
4 - " << action << " to the beginning\n\
5 - " << action << " to the end\n"

int main(int argc, char *argv[]) {
    if (argc > 1 && atoi(argv[1]) > 0)
    {
        List *list = new List(atoi(argv[1]));
        int element;
        int main_action = 0;
        int action_variant = 0;
        while (main_action != 6) {
            cout << CHOICE_MAIN_ACTION;
            cin >> main_action;
            switch (main_action) {
            case 1:
                if (list->is_empty()) {
                    cout << "Empty";
                } else {
                    cout << "Not empty";
                }
                cout << endl;
                break;
            case 2:
                if (list->is_full()) {
                    cout << "Full";
                } else {
                    cout << "Not full";
                }
                cout << endl;
                break;
            case 3: {
                CHOICE_ACTION_VARIANT("push") << "Choice : ";
                cin >> action_variant;
                cout << "Enter element : ";
                cin >> element;
                int help_element = 0;
                switch (action_variant)
                {
                case 1:
                    cout << "Enter index : ";
                    cin >> help_element;
                    list->push_index(help_element, element);
                    break;
                case 2:
                    cout << "Enter help element : ";
                    cin >> help_element;
                    list->push_before(help_element, element);
                    break;
                case 3:
                    cout << "Enter help element : ";
                    cin >> help_element;
                    list->push_after(help_element, element);
                    break;
                case 4:
                    list->push_start(element);
                    break;
                case 5:
                    list->push_end(element);
                    break;
                default:
                    break;
                }
                break;
            }
            case 4:
                CHOICE_ACTION_VARIANT("delete");
                cout << "6 - delete by data" << endl << "Choice : ";
                cin >> action_variant;
                switch (action_variant)
                {
                case 1: {
                    int index;
                    cout << "Enter index : ";
                    cin >> index;
                    list->delete_index(index);
                    break;
                }
                case 2:
                    cout << "Enter element : ";
                    cin >> element;
                    list->delete_before(element);
                    break;
                case 3:
                    cout << "Enter element : ";
                    cin >> element;
                    list->delete_after(element);
                    break;
                case 4:
                    list->delete_start();
                    break;
                case 5:
                    list->delete_end();
                    break;
                case 6:
                    cout << "Enter element : ";
                    cin >> element;
                    list->delete_data(element);
                    break;
                default:
                    break;
                }
                break;
            case 5:
                list->print();
                break;
            case 6:
                cout << "Exit" << endl;
                break;
            default:
                break;
            }
        }
    } else {
        cout << "Error count element\nExit . . .";
    }
}