#include <iostream>

void sorting_by_inserts (int *array, int size);
void sorting_by_choice (int *array, int size);
void sorting_by_exchange (int *array, int size);

void shell_sort (int *array, int size);
void piramidal_sort (int *array, int size);
void fast_sort (int *array, int size, int *comparisons, int *permutations, int left = 0, int right = -1, int first = 1);

bool check_result(int *array, int size);