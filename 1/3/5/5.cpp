#include <ctime>
#include "list.h"

#define REPORT(error_number) cout << REPORT_LIST[error_number] << endl;

const string REPORT_LIST[] = {"The element has been added",
"The element has been deleted",
"Index out of range",
"The element was not added",
"The element was not deleted",
"The list is empty",
"This is the first element",
"This is the last element",
"The element was not found",
};

int main(int argc, char *argv[]) {
    List *list = new List();
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
        case 2: {
            CHOICE_ACTION_VARIANT("push") << "4 - add before element\n5 - add after element\n" << "Choice : ";
            cin >> action_variant;
            cout << "Enter element : ";
            cin >> element;
            int help_element = NAN;
            switch (action_variant)
            {
            case 1:
                cout << "Enter index : ";
                cin >> help_element;
                list->push_index(element, help_element);
                break;
            case 2:
                cout << "Enter help element : ";
                cin >> help_element;
                list->push_before(element, help_element);
                break;
            case 3:
                cout << "Enter help element : ";
                cin >> help_element;
                list->push_after(element, help_element);
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
        case 3:
            CHOICE_ACTION_VARIANT("delete");
            cout << "4 - delete by data" << endl << "Choice : ";
            cin >> action_variant;
            switch (action_variant) {
            case 1: {
                int index;
                cout << "Enter index : ";
                cin >> index;
                list->delete_index(index);
                break;
            }
            // case 2:
            //     cout << "Enter element : ";
            //     cin >> element;
            //     list->delete_before(element);
            //     break;
            // case 3:
            //     cout << "Enter element : ";
            //     cin >> element;
            //     list->delete_after(element);
            //     break;
            case 2:
                list->delete_start();
                break;
            case 3:
                list->delete_end();
                break;
            case 4:
                cout << "Enter element : ";
                cin >> element;
                list->delete_elem(element);
                break;
            default:
                break;
            }
            break;
        case 4:
            list->print_list();
            break;
        case 5:
            list->print_trash();
            break;
        case 6:
            cout << "Exit" << endl;
            break;
        default:
            break;
        }
    }
    delete list;
}