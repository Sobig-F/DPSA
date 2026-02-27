#include <iostream>
#include <string>

// #define NAN 0.0 / 0.0

using namespace std;

template <typename type>
struct List {
private:
    int size;
    int real_size;
    int head;
    int tail;
    type *queue;
    type null_example;

    ~List() {
        delete this->queue;
        this->queue = nullptr;
    }

    int find(type data) {
        int local_tail = this->tail;
        if (this->head > this->tail) {
            local_tail += (int)this->size;
        }
        for (int i = this->head; i <= local_tail; ++i) {
            if (this->queue[i % (int)this->size] >= data || this->queue[i % (int)this->size] == this->null_example) {
                return i % (int)this->size;
            }
        }
        return this->size - 1;
    }
    
    bool the_head_is_closer(int index) {
        int local_head = this->head;
        int local_tail = this->head > this->tail ? (int)this->size + this->tail : this->tail;
        int local_index = this->head > this->tail ? (int)this->size + index : index;

        if (abs(local_head - local_index) < abs(local_tail - local_index)) {
            return true;
        } else {
            return false;
        }
    }

    void paste(int index, type data) {
        int i;
        if (!this->the_head_is_closer(index)) {
            i = (this->tail + 1) % (int)this->size;
            while (i != index) {
                if (i < 0) {
                    i = this->size - 1;
                }
                if (i == 0) {
                    this->queue[i] = this->queue[(int)this->size - 1];
                } else {
                    this->queue[i] = this->queue[i - 1];
                }
                --i;
            }
            this->tail = (this->tail + 1) % (int)this->size;
        } else {
            cout << "head closer" << endl;
            if (this->head == 0) {
                i = (int)this->size - 1;
            } else {
                i = this->head - 1;
            }
            --index;
            if (index == -1) {
                index = (int)this->size - 1;
            }
            while (i % (int)this->size != index) {
                this->queue[i % (int)this->size] = this->queue[(i + 1) % (int)this->size];
                ++i;
            }
            --this->head;
            if (this->head == -1) {
                this->head = (int)this->size - 1;
            }
        }
        this->queue[index] = data;
    }

    void substitution(int index) {
        int i = index;
        if (!this->the_head_is_closer(index)) {
            while (i % (int)this->size != this->tail) {
                this->queue[i % this->size] = this->queue[(i + 1) % (int)this->size];
                ++i;
            }
            this->queue[this->tail] = NAN;
            if (this->tail == 0) {
                this->tail = (int)this->size - 1;
            } else {
                --this->tail;
            }
        } else {
            while (i != this->head) {
                if (i < 0) {
                    i = this->size - 1;
                }
                if (i == 0) {
                    this->queue[i] = this->queue[this->size - 1];
                } else {
                    this->queue[i] = this->queue[i - 1];
                }
                --i;
            }
            this->queue[this->head] = NAN;
            this->head = (this->head + 1) % this->size;
        }
    }
    
public:
    List(int size) {
        this->size = size;
        this->real_size = 0;
        this->head = 0;
        this->tail = 0;
        this->queue = new type[size];
        for (int i = 0; i < this->size; ++i) {
            if (sizeof(this->queue[0]) == sizeof(int)) {
                this->null_example = NAN;
            } else {
                this->null_example = NAN;
            }
            this->queue[i] = this->null_example;
        }
        cout << endl;
    }

    bool is_empty() {
        if (size < 1) {
            cout << "Create queue error" << endl;
            return false;
        } else if (this->real_size == 0) {
            return true;
        } else {
            return false;
        }
    }

    bool is_full() {
        if (this->size < 1) {
            cout << "Create queue error" << endl;
            return false;
        } else if (this->real_size == this->size) {
            return true;
        } else {
            return false;
        }
    }

    bool push(type data) {
        if (size > 0) {
            if (this->is_full()) {
                cout << "Queue is full" << endl;
                return false;
            } else if (this->real_size == 0) {
                this->queue[this->head] = data;
            } else if (this->queue[this->head] >= data) {
                --this->head;
                if (this->head == -1) {
                    this->head = (int)this->size - 1;
                }
                this->queue[this->head] = data;
            } else if (this->queue[this->tail] <= data) {
                this->tail = (this->tail + 1) % (int)this->size;
                this->queue[this->tail] = data;
            } else {
                int index = this->find(data);
                this->paste(index, data);
            }
            ++this->real_size;
            return true;
        } else {
            cout << "Create queue error" << endl;
        }
        return false;
    }

    bool del(type data) {
        if (size > 0) {
            if (this->is_empty()) {
                cout << "Queue is empty" << endl;
            } else {
                int index = this->find(data);
                if (index == this->tail + 1 && !this->is_full()) {
                    cout << "The element could not be found" << endl;
                } else {
                    this->substitution(index);
                    --this->real_size;
                    if (this->real_size == 0) {
                        this->head = 0;
                        this->tail = 0;
                    }
                    return true;
                }
            }
        } else{
            cout << "Create queue error" << endl;
        }
        return false;
    }

    void print_queue() {
        if (this->is_empty()) {
            cout << "Queue is empty";
        } else {
            for (int i = this->head; i < this->head + (int)this->real_size; ++i) {
                cout << this->queue[i % (int)this->size] << " ";
            }
        }
        cout << endl;
    }

    bool find_d (type data)
    {
        int local_tail = this->tail;
        if (this->head > this->tail) {
            local_tail += (int)this->size;
        }
        for (int i = this->head; i <= local_tail; ++i) {
            if (this->queue[i % (int)this->size] == data) {
                return true;
            }
        }
        return false;
    }
};
