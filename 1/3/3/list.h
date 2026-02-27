#include <iostream>

using namespace std;

#define CHOICE_MAIN_ACTION "1 - checking for list emptiness\n\
2 - Checking if the list is full\n\
3 - adding an element\n\
4 - deleting an element\n\
5 - displaying the contents of the list\n\
6 - exit\n\
Choice: "

struct List
{
private:
    int size;
    int real_size;

    struct Node {
        int data;
        int next;

        Node() {
            this->data = 0;
            this->next = -1;
        }
    };

    Node *list;

    int push(int free_index, int before_real_index, int data) {
        this->list[free_index].data = data;
        this->list[free_index].next = this->list[before_real_index].next;
        this->list[before_real_index].next = free_index;
        ++this->real_size;

        return 1;
    }

    int find_free_index() {
        for (int i = 1; i < this->size + 1; ++i) {
            if (this->list[i].next == -1) {
                return i;
            }
        }

        return -1;
    }

    int find_before_real_index_by_data(int data) {
        for (int i = 0; this->list[i].next != 0; i = this->list[i].next) {
            if (this->list[this->list[i].next].data == data) {
                return i;
            }
        }

        return -1;
    }

    int find_before_real_index_by_index(int index) {
        int result = 0;

        for (int i = 0; i < index; ++i) {
            result = this->list[result].next;
        }

        return result;
    }

    // int find_list_index_by_data(int data) {
    //     int local_index = this->list[0].next;

    //     for (int i = 0; local_index != 0; ++i) {
            
    //         if (this->list[local_index].data == data) {
    //             return i;
    //         }

    //         local_index = this->list[local_index].next;
    //     }

    //     return -1;
    // }

    int find_real_index_by_data(int data) {
        for (int i = 0; this->list[i].next != -1; i = this->list[i].next) {
            if (this->list[i].data == data) {
                return i;
            }
        }

        return -1;
    }

public:

    List(int count) {
        this->size = count;
        this->real_size = 0;
        this->list = new Node[this->size + 1];
        this->list[0].next = 0;
    }

    int is_empty() {
        return !this->list[0].next;
    }

    int is_full() {
        return this->real_size == this->size;
    }

    int push_index(int index, int data) {
        if (this->is_full()) {
            cout << "Список полон" << endl;
            return 0;
        }

        if (index == 0) {
            return push_start(data);
        } else if (index == this->real_size) {
            return push_end(data);
        } else if (index < this->real_size) {
            int free_index = find_free_index();
            int before_elem_index = find_before_real_index_by_index(index);
            return push(free_index, before_elem_index, data);
        } else {
            cout << "Индекс выходит за пределы массива" << endl;
            return 0;
        }

        return 1;
    }

    int push_before(int after_element, int data) {
        int index = find_before_real_index_by_data(after_element);

        if (index == -1) {
            cout << "Элемент не найден" << endl;
            return 0;
        }

        int free_index = find_free_index();
        return push(free_index, index, data);

    }

    int push_after(int before_element, int data) {
        int index = find_real_index_by_data(before_element);

        if (index == -1) {
            cout << "Элемент не найден" << endl;
            return 0;
        }

        int free_index = find_free_index();
        return push(free_index, index, data);
    }

    int push_start(int data) {
        if (is_full()) {
            cout << "Список полон" << endl;
            return 0;
        }

        int after_index = this->list[0].next;
        int free_index = find_free_index();

        this->list[free_index].data = data;
        this->list[free_index].next = after_index;
        this->list[0].next = free_index;

        ++this->real_size;

        return 1;
    }

    int push_end(int data) {
        if (is_full()) {
            cout << "Список полон" << endl;
            return 0;
        }

        int free_index = find_free_index();
        int last_real_index = find_before_real_index_by_index(this->real_size);

        this->list[free_index].data = data;
        this->list[free_index].next = this->list[last_real_index].next;
        this->list[last_real_index].next = free_index;

        ++this->real_size;

        return 1;
    }

    int delete_index(int index) {
        if (index >= this->real_size || index < 0) {
            cout << "Индекс выходит за пределы массива" << endl;
            return 0;
        }

        int before_real_index = find_before_real_index_by_index(index);

        int temp_array_delete_index = this->list[before_real_index].next;

        this->list[before_real_index].next = this->list[this->list[before_real_index].next].next;

        this->list[temp_array_delete_index].next = -1;

        --this->real_size;

        return 1;
    }

    int delete_before(int after_element) {
        int before_before_real_index = -1;

        for (int i = 0; this->list[i].next != 0; i = this->list[i].next) {
            if (this->list[this->list[this->list[i].next].next].data == after_element) {
                before_before_real_index = i;
            }
        }

        if (before_before_real_index == -1) {
            return 0;
        }

        int temp_array_delete_index = this->list[before_before_real_index].next;

        this->list[before_before_real_index].next = this->list[this->list[before_before_real_index].next].next;

        this->list[temp_array_delete_index].next = -1;

        --this->real_size;

        return 1;
    }

    int delete_after(int before_element) {
        int before_real_index = find_real_index_by_data(before_element);

        int temp_array_delete_index = this->list[before_real_index].next;

        this->list[before_real_index].next = this->list[this->list[before_real_index].next].next;

        this->list[temp_array_delete_index].next = -1;

        --this->real_size;

        return 1;
    }

    int delete_start() {
        int temp_array_delete_index = this->list[0].next;

        this->list[0].next = this->list[this->list[0].next].next;

        this->list[temp_array_delete_index].next = -1;

        --this->real_size;

        return 1;
    }

    int delete_end() {
        return delete_index(this->real_size - 1);
    }

    int delete_data(int data) {
        int before_index = find_before_real_index_by_data(data);

        if (before_index == -1) {
            return 0;
        }

        int temp_array_delete_index = this->list[before_index].next;

        this->list[before_index].next = this->list[this->list[before_index].next].next;

        this->list[temp_array_delete_index].next = -1;

        --this->real_size;

        return 1;
    }

    void print() {
        for (int i = this->list[0].next; i > 0; i = this->list[i].next) {
            cout << this->list[i].data << " ";
        }
        cout << endl;
    }
    
};