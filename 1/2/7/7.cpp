#include "queue.h"
#include <ctime>

#define ADDED 3
#define DELETED 3

#define MIN_VALUE 65
#define MAX_VALUE 90

#define RANDOM(a, b) rand() % (b - a + 1) + a

#define AUTO false

inline void delay(clock_t sec) { 
    clock_t start_time = clock(); 
    clock_t end_time = sec + start_time; 
    while(clock() < end_time); 
}


int main(int argc, char* argv[]) {
    char symbol;
    char action = '\n';
    int count;
    bool del;
    Queue *queue = new Queue();
    while (action != 'q') {
        srand(time(0));
        del = RANDOM(0, 1);
        srand(time(0));
        if (del) {
            count = RANDOM(1, DELETED);
        } else {
            count = RANDOM(1, ADDED);
        }
        if (del) { 
            if (!AUTO) {
                cout << "Deleting " << count << " elements" << endl;
            }
            for (int i = 0; i < count; ++i) {
                if (queue->delete_element() && !AUTO) {
                    cout << i + 1 << ") delete +" << endl;
                } else if (!AUTO) {
                    cout << i + 1 << ") not delete -" << endl;
                }
            }
        } else {
            srand(time(0));
            symbol = RANDOM(MIN_VALUE, MAX_VALUE);
            if (!AUTO) {
                cout << "Adding " << count << " elements '" << symbol << "'" << endl;
            }
            for (int i = 0; i < count; ++i) {
                queue->push(symbol);
            }
        }
        queue->print_queue();
        if (AUTO) {
            delay(1000);
        } else {
            cin >> action;
        }
        cout << endl;
    };
}