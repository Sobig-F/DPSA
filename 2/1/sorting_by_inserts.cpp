#include "../sorts.h"

void sorting_by_inserts (int *array, int size)
{
    for (int i = 0; i + 1 < size; ++i)
    {
        if (*(array + i) < *(array + i + 1))
        {
            for (int j = i; j >= 0; --j)
            {
                *(array + j) += *(array + j + 1);
                *(array + j + 1) = *(array + j) - *(array + j + 1);
                *(array + j) = *(array + j) - *(array + j + 1);
            }
        }
    }
}