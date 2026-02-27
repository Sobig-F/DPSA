#include "../sorts.h"

void sorting_by_choice (int *array, int size)
{
    int min;
    for (int i = 0; i + 1 < size; ++i)
    {
        min = i;

        for (int j = i + 1; j < size; ++i)
        {
            if (*(array + j) < *(array + min))
            {
                min = j;
            }
        }

        if (*(array + i) != *(array + min))
        {
            *(array + i) += *(array + min);
            *(array + min) = *(array + i) - *(array + min);
            *(array + i) = *(array + i) - *(array + min);
        }
    }
}

void piramidal_sort (int *array, int size)
{

}