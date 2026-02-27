#include <iostream>

using namespace std;

#define CHOICE_MAIN_ACTION "1 - checking for list emptiness\n\
2 - adding an element\n\
3 - deleting an element\n\
4 - displaying the contents of the list\n\
5 - displaying the contents of the trash\n\
6 - exit\n\
Choice: "

#define CHOICE_ACTION_VARIANT(action) cout << "1 - " << action << " by index\n\
2 - " << action << " to the beginning\n\
3 - " << action << " to the end\n"

struct List
{
private:
    
    struct Node
    {
        int data;
        Node *next;

        Node() {
            this->data = 0;
            this->next = nullptr;
        }

        Node(int data, Node *next) {
            this->data = data;
            this->next = next;
        }

        ~Node() {
            this->data = 0;
            this->next = nullptr;
        }
    };

    Node *list;
    Node *trash;

    int size;

    void push_trash(Node *elem) {
        elem->next = this->trash->next;
        this->trash->next = elem;
    }
    
public:

    List() {
        this->size = 0;
        this->list = new Node(0, nullptr);
        this->trash = new Node(0, nullptr);
    }

    ~List() {
        Node *current;

        current = this->list;
        while (current) {
            current = current->next;
            delete this->list;
            this->list = current;
        }

        current = this->trash;
        while (current) {
            current = current->next;
            delete this->trash;
            this->trash = current;
        }

        this->list = nullptr;
        this->trash = nullptr;
        this->size = 0;
    }

    int is_empty() {
        return this->size == 0;
    }

    void push_start(int data) {
        if (is_empty()) {
            this->list->next = new Node(data, nullptr);
        } else {
            this->list->next = new Node(data, this->list);
        }

        ++this->size;
    }

    void push_end(int data) {
        if (is_empty()) {
            push_start(data);
            return;
        }

        Node *current = this->list;

        while (current->next) {
            current = current->next;
        }

        current->next = new Node(data, nullptr);

        ++this->size;
    }

    void push_index(int data, int index) {
        if (index == 0) {
            push_start(data);
            return;
        } else if (index == this->size) {
            push_end(data);
            return;
        } else if (index > this->size) {
            return;
        }

        Node *current = this->list->next;

        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        current->next = new Node(data, current->next);

        ++this->size;
    }

    void push_before(int data, int after) {
        if (this->list->next->data == after) {
            push_start(data);
            return;
        }
        
        Node *current = this->list->next;
        
        while (current->next && current->next->data != after) {
            current = current->next;
        }

        if (!current->next) {
            return;
        }

        current->next = new Node(data, current->next);

        ++this->size;
    }

    void push_after(int data, int before) {
        if (is_empty()) {
            push_start(data);
        }
        
        Node *current = this->list->next;

        while (current && current->data != before) {
            current = current->next;
        }

        if (!current) {
            return;
        }

        current->next = new Node(data, current->next);

        ++this->size;
    }

    void delete_elem(int data) {
        if (is_empty()) {
            return;
        }
        
        Node *current = this->list->next;
        Node *before;

        if (current->data == data) {
            delete_start();
            return;
        }

        while (current && current->data != data) {
            before = current;
            current = current->next;
        }

        if (!current) {
            return;
        }

        before->next = current->next;
        push_trash(current);

        --this->size;
    }

    void delete_index(int index) {
        if (is_empty()) {
            return;
        }

        if (index == 0) {
            delete_start();
            return;
        } else if (index == this->size - 1) {
            delete_end();
            return;
        }

        Node *current = this->list->next;
        Node *before; 

        for (int i = 0; i < index; ++i) {
            before = current;
            current = current->next;
        }

        if (!current) {
            return;
        }

        before->next = current->next;
        push_trash(current);

        --this->size;
    }

    void delete_start() {
        if (is_empty()) {
            return;
        }

        Node *current = this->list->next;

        this->list->next = this->list->next->next;

        push_trash(current);

        --this->size;
    }

    void delete_end() {
        if (is_empty()) {
            return;
        }

        Node *current = this->list->next;
        Node *before;

        while (current->next) {
            before = current;
            current = current->next;
        }

        before->next = nullptr;
        push_trash(current);

        --this->size;
    }

    void delete_before(int data) {
        if (is_empty()) {
            return;
        }

        Node *current = this->list->next;
        Node *before = current;

        while (current->next && current->next->data != data) {
            before = current;
            current = current->next;
        }

        if (!current->next) {
            return;
        } else if (this->list->next == current) {
            delete_start();
            return;
        }

        before->next = current->next;
        push_trash(current);

        --this->size;
    }

    void delete_after(int data) {
        if (is_empty()) {
            return;
        }
        
        Node *current = this->list->next->next;
        Node *before = this->list->next;

        while (current && before->data != data) {
            before = current;
            current = current->next;
        }

        if (!current) {
            return;
        }

        before->next = current->next;
        push_trash(current);

        --this->size;
    }

    void print_list() {
        Node *current = this->list->next;

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void print_trash() {
        Node *current = this->trash->next;

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};