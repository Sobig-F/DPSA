#include <iostream>

using namespace std;

struct Queue {
private:
    struct Node
    {
        char data;
        Node *next, *prev;

        Node() {
            this->next = this;
            this->prev = this;
        }
    };

    Node *top;

    ~Queue() {
        Node *current = this->top->next;
        this->top->prev->next = nullptr;
        while (current != nullptr) {
            delete[] this->top;
            this->top = current;
            current = current->next;
        }
        delete(this->top);
    }

    Node* push_node(char data, Node *list) {
        if (list != nullptr) {    
            Node *current = new Node();
            list->prev->next = current;
            current->next = list;
            current->prev = list->prev;
            list->prev = current;
        } else {
            list = new Node();
        }
        list->prev->data = data;
        return list;
    }

    Node* delete_node(Node *list) {
        if (list->next == list) {
            list->next = nullptr;
            list->prev = nullptr;
            delete[] list;
            return nullptr;
        } else {
            Node *current = list;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            list = list->next;
            current->next = nullptr;
            current->prev = nullptr;
            delete[] current;
            return list;
        }
    }

    void print(Node *list) {
        Node *current = list;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != list);
        cout << endl;
    }

public:

    Queue() {
        this->top = nullptr;
    }

    bool is_empty() {
        if (this->top == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    void push(char data) {
        this->top = this->push_node(data, this->top);
    }

    bool delete_element() {
        if (this->top != nullptr) {
            this->top = this->delete_node(this->top);
            return true;
        } else {
            // cout << "Queue is empty" << endl;
            return false;
        }
    }

    void print_queue() {
        if (!this->is_empty()) {
            this->print(this->top);
        } else { 
            cout << "Queue is empty" << endl;
        }
    }
};
