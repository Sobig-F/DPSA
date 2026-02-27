#include <iostream>

using namespace std;

struct Stack {
private:
    struct Node {
        double data;
        Node *next;

        Node() {
            this->next = nullptr;
        }
    };

    Node *top;
    Node *basket_top;

    ~Stack() {
        Node *current = this->top->next;
        while (current != nullptr) {
            delete[] this->top;
            this->top = current;
            current = current->next;
        }
        delete(this->top);

        current = this->basket_top->next;
        while (current != nullptr) {
            delete(this->basket_top);
            this->basket_top = current;
            current = current->next;
        }
        delete[] this->basket_top;
    }

    Node* push_node(double data, Node *list) {
        if (list != nullptr) {    
            Node *current = new Node();
            current->next = list;
            list = current;
        } else {
            list = new Node();
            // list->next = nullptr;
        }
        list->data = data;
        return list;
    }

    Node* delete_node(Node *list) {
        if (list->next == nullptr) {
            delete[] list;
            return nullptr;
        } else {
            Node *current = list;
            list = list->next;
            delete(current);
            return list;
        }
    }

    void print_stack(Node *list) {
        Node *current = list;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

public:

    Stack() {
        this->top = nullptr;
        this->basket_top = nullptr;
    }

    bool is_empty() {
        if (this->top == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    void push(double data) {
        this->top = this->push_node(data, this->top);
    }

    void push(int count, double arr[]) {
        for (int i = 0; i < count; ++i) {
            this->top = this->push_node(arr[i], this->top);
        }
    }

    void push_from_trash() {
        if (this->top == nullptr) {
            this->top = this->basket_top;
            this->basket_top = this->basket_top->next;
            this->top->next = nullptr;
        } else {
            Node *current = this->basket_top->next;
            this->basket_top->next = this->top;
            this->top = this->basket_top;
            this->basket_top = current;
        }
    }

    void delete_forever() {
        if (this->top != nullptr) {
            this->top = this->delete_node(this->top);
        } else {
            cout << "Trash is empty" << endl;
        }
    }

    void delete_to_trash() {
        if (this->basket_top == nullptr) {
            this->basket_top = this->top;
            this->top = this->top->next;
            this->basket_top->next = nullptr;
        } else {
            Node *current = this->top->next;
            this->top->next = this->basket_top;
            this->basket_top = this->top;
            this->top = current;
        }
    }

    void print_main_stack() {
        print_stack(this->top);
    }

    void print_helper_stack() {
        print_stack(this->basket_top);
    }
};
