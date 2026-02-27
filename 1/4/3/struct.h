#include <iostream>

using namespace std;

struct ListOfLists
{
    struct List
    {
        struct Node
        {
            int data;
            Node *next;
            Node *prev;

            Node(int data, Node *prev, Node *next) {
                this->data = data;
                this->next = next;
                this->prev = prev;
            }

            ~Node() {
                this->data = 0;
                this->next = nullptr;
                this->prev = nullptr;
            }
        };

        int size;
        Node *Head;
        List *next;
        List *prev;

        List(List *next, List *prev) {
            this->size = 0;
            this->next = next;
            this->prev = prev;
            this->Head = new Node(0, nullptr, nullptr);
        }

        ~List() {
            Node *currentNode;

            while (this->Head->next != nullptr) {
                currentNode = this->Head->next;
                this->Head->next = currentNode->next;
                
                delete currentNode;
            }

            this->Head = nullptr;

            if (this->prev) {
                this->prev->next = this->next;
            }

            if (this->next) {
                this->next->prev = this->prev;
            }

            this->size = 0;
        }

        void addElement(int data) {
            Node *currentNode = this->Head;

            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }

            currentNode->next = new List::Node(data, currentNode, nullptr);
            ++this->size;
        }

        // int deleteElement(int index) {
        //     if (index >= this->size) {
        //         return 0;
        //     }
        //     Node *currentNode = this->Head;

        //     for (int i = 0; i < index; ++i) {
        //         currentNode = currentNode->next;
        //     }

        //     currentNode->prev->next = currentNode->next;
        //     currentNode->next->prev = currentNode->prev;

        //     delete currentNode;

        //     --this->size;
        //     return 1;
        // }

        int deleteElement(int data) {
            Node *currentNode = this->Head;

            while (currentNode != nullptr && currentNode->data != data) {
                currentNode = currentNode->next;
            }

            if (currentNode == nullptr) {
                return 0;
            }

            currentNode->prev->next = currentNode->next;
            currentNode->next->prev = currentNode->prev;

            delete currentNode;

            --this->size;

            return 1;
        }

        int findElement(int data) {
            Node *currentNode = this->Head->next;
            int index = 0;

            while (currentNode != nullptr) {
                if (currentNode->data == data) {
                    return index;
                }

                currentNode = currentNode->next;
                ++index;
            }

            return -1;
        }

        void print() {
            Node *currentNode = this->Head->next;
            int index = 0;

            while (currentNode != nullptr) {
                cout << "{" << index << "}" << currentNode->data << " ";
                currentNode = currentNode->next;
                ++index;
            }
        }
        
    };

    int size;
    List *Head;

    ListOfLists() {
        this->size = 0;
        this->Head = new List(nullptr, nullptr);
    }

    ~ListOfLists() {
        List *currentList;

        while (this->Head->next != nullptr) {
            currentList = this->Head->next;
            this->Head->next = currentList;

            delete currentList;
        }

        this->Head = nullptr;

        this->size = 0;
    }

    void addList() {
        List *current = this->Head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = new List(nullptr, current);
        ++this->size;
    }

    void addElement(int list, int data) {
        if (list >= this->size) {
            cout << "Out of range" << endl;
            return;
        }

        List *currentList = this->Head->next;

        for (int i = 0; i < list; ++i) {
            currentList = currentList->next;
        }

        currentList->addElement(data);
    }

    // int deleteElement(int list, int index) {
    //     if (list >= this->size) {
    //         cout << "Out of range" << endl;
    //         return 0;
    //     }

    //     List *currentList = this->Head->next;

    //     for (int i = 0; i < list; ++i) {
    //         currentList = currentList->next;
    //     }

    //     return currentList->deleteElement(index);
    // }

    int deleteElement(int data) {
        List *currentList = this->Head->next;

        while (currentList != nullptr) {
            if (currentList->deleteElement(data)) {
                return 1;
            }

            currentList = currentList->next;
        }

        return 0;
    }

    int deleteList(int list) {
        if (list >= this->size || list < 0) {
            return 0;
        }
        
        List *currentList = this->Head->next;

        for (int i = 0; i < list; ++i) {
            currentList = currentList->next;
        }

        delete currentList;

        --this->size;

        return 1;
    }

    void findElement(int data, int *list, int *index) {
        List *currentList = this->Head->next;
        *list = -1;
        *index = -1;

        int iterListIndex = 0;

        while (currentList != nullptr) {
            *index = currentList->findElement(data);
            if (*index >= 0) {
                *list = iterListIndex;
                return;
            }

            currentList = currentList->next;
            ++iterListIndex;
        }
    }

    void print() {
        List *currentList = this->Head->next;
        int index = 0;

        while (currentList != nullptr) {
            cout << "[" << index << "]: ";
            currentList->print();
            cout << endl;

            currentList = currentList->next;
            ++index;
        }
    }
};