#include "../sorts.h"

void sorting_by_exchange (int *array, int size)
{
    for (int i = 0; i + 1 < size; ++i)
    {
        for (int j = 1; j < size - i; ++j)
        {
            if (array[j] < array[j - 1])
            {
                *(array + j) += *(array + j - 1);
                *(array + j - 1) = *(array + j) - *(array + j - 1);
                *(array + j) = *(array + j) - *(array + j - 1);
            }
        }
    }
}