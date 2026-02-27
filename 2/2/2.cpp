#include "iostream"

#include "../sorts.h"
#include "../random_filling.h"

using namespace std;

#define MAIN "1 - сортировка обменом\n\
2 - сортировка выбором\n\
3 - сортировка вставками\n\
4 - быстрая сортировка\n\
5 - пирамидальная сортировка\n\
6 - сортировка Шелла\n\
7 - выход\n\
Выбор : "

void print_array (int *array, int count)
{
    for (int i = 0; i < count; ++i)
    {
        cout << *(array + i) << " ";
    }

    cout << endl;
}

int main(int argc, char *argv[])
{
    int start;
    int end;
    int count;

    cout << "Start: ";
    cin >> start;

    cout << "End: ";
    cin >> end;

    cout << "Count: ";
    cin >> count;

    int action = 0;
    int *array = nullptr;

    while (action != 7)
    {
        cout << MAIN;
        cin >> action;

        if (action != 7)
        {
            delete array;
            array = random_filling<int>(start, end, count);
        }

        switch (action)
        {
            case 1:
                sorting_by_exchange(array, count);
                print_array(array, count);
                break;
            case 2:
                sorting_by_choice(array, count);
                print_array(array, count);
                break;
            case 3:
                sorting_by_inserts(array, count);
                print_array(array, count);
                break;
            case 4:
                fast_sort(array, count);
                print_array(array, count);
                break;
            case 5:
                piramidal_sort(array, count);
                print_array(array, count);
                break;
            case 6:
                shell_sort(array, count);
                print_array(array, count);
                break;
            case 7:
                delete array;
                cout << "Exit . . ." << endl;
                break;
        }
    }
}