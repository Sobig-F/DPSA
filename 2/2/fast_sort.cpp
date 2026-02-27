#include "../sorts.h"
#include <iostream>

using namespace std;

// Функция разделения массива (Hoare partition)
int partition(int* arr, int low, int high) {
    int pivot = arr[high]; // Опорный элемент
    int i = low - 1;       // Индекс меньшего элемента

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {   // Если элемент меньше pivot
            i++;
            swap(arr[i], arr[j]); // Меняем местами
        }
    }
    swap(arr[i + 1], arr[high]); // Ставим pivot на место
    return i + 1;
}

// Рекурсивная функция быстрой сортировки
void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Разделение массива

        quickSort(arr, low, pi - 1);  // Сортируем левую часть
        quickSort(arr, pi + 1, high); // Сортируем правую часть
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // Определяем размер массива

    quickSort(arr, 0, n - 1); // Запускаем сортировку

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}