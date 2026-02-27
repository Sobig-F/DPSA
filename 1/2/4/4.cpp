#include <ctime>
#include "stack.h"

#define MIN_VALUE 1
#define MAX_VALUE 100

#define CHOICE_ACTION "1 - checking for stack emptiness\n\
2 - adding an element\n\
3 - deleting an element\n\
4 - displaying the contents of the main stack\n\
5 - output of the contents of the auxiliary stack\n\
6 - exit\n\
Choice: "

int main() {
    Stack *stack = new Stack();
    bool out = false;
    int choice, how_much, count, rand_or_man, trash_or_forever;
    double *arr = nullptr, element;
    while (!out) {
        cout << CHOICE_ACTION;
        cin >> choice;
        switch (choice) {
            case 6:
                out = true;
                break;

            case 1:
                if (stack->is_empty()) {
                    cout << "Empty" << endl;
                } else {
                    cout << "Not empty" << endl;
                }
                break;

            case 2: {
                cout << "1 - one\n2 - more\n3 - from trash\nChoice: ";
                cin >> how_much;
                
                
                switch (how_much) {

                    case 1:
                        cout << "Input element: ";
                        cin >> element;
                        stack->push(element);
                        break;

                    case 2: {
                        cout << "How many elements? : ";
                        cin >> count;
                        if (arr == nullptr) {
                            arr = new double[count];
                        } else {
                            delete[] arr;
                            arr = nullptr;
                            arr = new double[count];
                        }
                        cout << "1 - Random\n2 - manual input\nChoice: ";
                        cin >> rand_or_man;    
                        switch (rand_or_man) {

                            case 1:
                                srand(time(0));
                                for (int i = 1; i <= count; ++i) {
                                    arr[i - 1] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
                                    cout << i << " : " << arr[i - 1] << endl;;
                                }
                                stack->push(count, arr);
                                break;

                            case 2:
                                for (int i = 1; i <= count; ++i) {
                                    cout << i << " : ";
                                    cin >> arr[i - 1];
                                }
                                stack->push(count, arr);
                                break;

                            default:
                                cout << "There is no selected operation" << endl;
                                break;
                        }
                        if (arr != nullptr) {
                            delete[] arr;
                            arr = nullptr;
                        }
                        break;
                    }
                    case 3:
                        stack->push_from_trash();
                        break;

                    default:
                        cout << "There is no selected operation" << endl;
                        break;
                }


                break;
            }
            case 3:
                cout << "1 - Delete to trash\n2 - Delete forever\nChoice: ";
                cin >> trash_or_forever;
                switch (trash_or_forever)
                {
                case 1:
                    stack->delete_to_trash();
                    break;
                case 2:
                    stack->delete_forever();
                    break;
                default:
                    cout << "There is no selected operation" << endl;
                    break;
                }
                break;
            case 4:
                stack->print_main_stack();
                break;
            case 5:
                stack->print_helper_stack();
                break;
            default:
                cout << "There is no selected operation" << endl;
                break;        
        }
    }
}