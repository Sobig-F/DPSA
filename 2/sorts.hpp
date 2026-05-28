#include <iostream>

void sorting_by_inserts (int *array, int size);
void sorting_by_choice (int *array, int size);
void sorting_by_exchange (int *array, int size);

void shell_sort (int *array, int size);
void piramidal_sort (int *array, int size);
void fast_sort (int *array, int size, int *comparisons, int *permutations, int left = 0, int right = -1, int first = 1);

void pocket_sorting(int *array, int n);
void pocket_sorting_with_auxiliary_array(int *array, int n);
void generalized_pocket_sorting(int *array, int n, int size);
void bitwise_sorting(int *array, int size, int k);

int* random_filling (int start, int end, int count);
int* generate_unique_array(int n);
int* generate_array(int n, int size);

bool check_result(int *array, int size);
void print_array (int *array, int count);