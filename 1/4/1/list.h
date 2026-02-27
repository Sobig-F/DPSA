#include <iostream>

using namespace std;

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

    List() {
        this->size = 0;
        this->Head = new Node(-1, nullptr, nullptr);
        this->Head->next = this->Head;
        this->Head->prev = this->Head;
    }

    ~List() {
        if (Head == nullptr) return;
        
        Head->prev->next = nullptr;
        Head->prev = nullptr;
        
        Node* current = Head;
        
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        
        Head = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return this->size == 0;
    }

    int addElementAfter(int data, int before) {
        if (!this->size) {
            this->Head->next = new Node(data, this->Head, this->Head);
            this->Head->prev = this->Head->next;
            ++this->size;
            return 1;
        }

        Node *currentNode = this->Head->next;

        while (currentNode != this->Head && currentNode->data != before) {
            currentNode = currentNode->next;
        }
        
        if (currentNode == this->Head) {
            return 0;
        }

        currentNode->next = new Node(data, currentNode, currentNode->next);
        currentNode->next->next->prev = currentNode->next;

        ++this->size;

        return 1;
    }

    int addElementBefore(int data, int after) {
        if (!this->size) {
            return 0;
        }

        Node *currentNode = this->Head->next;

        while (currentNode != this->Head && currentNode->data != after) {
            currentNode = currentNode->next;
        }

        if (currentNode == this->Head) {
            return 0;
        }

        currentNode->prev = new Node(data, currentNode->prev, currentNode);
        currentNode->prev->prev->next = currentNode->prev;

        ++this->size;

        return 1;
    }

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

    int findElementStart(int data) {
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

    int findElementEnd(int data) {
        Node *currentNode = this->Head->prev;
        int index = 0;
        
        while (currentNode != nullptr) {
            if (currentNode->data == data) {
                return index;
            }

            currentNode = currentNode->prev;
            ++index;
        }

        return -1;
    }

    void printStart() {
        Node *currentNode = this->Head->next;

        while (currentNode != this->Head) {
            cout << currentNode->data << " ";

            currentNode = currentNode->next;
        }

        cout << endl;
    }

    void printEnd() {
        Node *currentNode = this->Head->prev;

        while (currentNode != this->Head) {
            cout << currentNode->data << " ";

            currentNode = currentNode->prev;
        }

        cout << endl;
    }
    
};