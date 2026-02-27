#include <iostream>
#include <memory.h>

using namespace std;

struct Queue {
private:
    size_t size;
    size_t real_size;
    int head;
    int tail;
    int *queue;

    ~Queue() {
        delete this->queue;
        this->queue = nullptr;
    }
    
public:
    Queue(int size) {
        this->size = size;
        this->head = 0;
        this->tail = 0;
        this->real_size = 0;
        this->queue = new int[size];
        memset(this->queue, 0, sizeof(int) * size);
    }

    bool is_empty() {
        if (this->size < 1) {
            cout << "Create queue error" << endl;
            return false;
        } else if (this->real_size == 0) {
            return true;
        } else {
            return false;
        }
    }

    bool is_full() {
        if (size < 1) {
            cout << "Create queue error" << endl;
            return false;
        } else if (this->real_size == this->size) {
            return true;
        } else {
            return false;
        }
    }

    void push(int data) {
        if (size > 0) {
            if (is_full()) {
                cout << "Queue is full" << endl;
            } else {
                this->queue[tail] = data;
                this->tail = (this->tail + 1) % (int)this->size;
                ++this->real_size;
            }
        } else {
            cout << "Create queue error" << endl;
        }
    }

    void del() {
        if (size > 0) {
            if (this->is_empty()) {
                cout << "Queue is empty" << endl;
            } else {
                this->queue[this->head] = 0;
                this->head = (this->head + 1) % (int)this->size;
                --this->real_size;
            }
        } else{
            cout << "Create queue error" << endl;
        }
    }

    void print_queue() {
        if (this->is_empty()) {
            cout << "Queue is empty";
        } else {
            int i = this->head;
            do {
                cout << this->queue[i % (int)this->size] << " ";
                ++i;
            } while (i % (int)this->size != this->tail);
        }
        cout << endl;
    }
};
