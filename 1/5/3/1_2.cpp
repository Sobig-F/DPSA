#include "sec_tree.h"

#define MAIN "1 - get size\n\
2 - symmetric bypass\n\
3 - find\n\
4 - insert by side\n\
5 - clear tree\n\
6 - Exit\n\
Choice : "

int main(int argc, char *argv[]) {
    Tree *tree = new Tree();

    int action = 0;

    while (action != 10)
    {
        cout << MAIN;
        cin >> action;

        switch (action)
        {
            case 1: {
                cout << tree->get_size() << endl;
                break;
            }
            case 2: {
                tree->simmetric();
                break;
            }
            case 3: {
                int element;
                cout << "Enter element : ";
                cin >> element;
                Tree::Node *result = tree->find(element);
                if (result == nullptr)
                {
                    cout << result->data << endl;
                } else {
                    cout << "Not found" << endl;
                }
                break;
            }
            case 4: {
                int parent;
                cout << "Enter parent: ";
                cin >> parent;
                Tree::Node *parentNode = tree->find(parent);
                if (parent) {
                    int element;
                    int side;
                    cout << "Change side:" << endl;
                    if (parentNode->left) {
                        cout << "0 - left" << endl;
                    }
                    if (parentNode->right) {
                        cout << "1 - right" << endl;
                    }
                    cin >> side;
                    if ((side && parentNode->right == nullptr) || (!side && parentNode->left == nullptr)) {
                        cout << "Incorrect" << endl;
                        break;
                    }
                    cout << "Enter data: ";
                    cin >> element;
                    tree->push_side(parentNode, side, element);
                } else {
                    cout << "Full" << endl;
                }
            }
            case 5: {
                int element;
                cout << "Enter node: ";
                cin >> element;
                Tree::Node *node = tree->find(element);
                if (node == nullptr) {
                    cout << "Not found" << endl;
                    break;
                }
                tree->delete_node(node);
            }
        }
    }
}