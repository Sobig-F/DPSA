#include "../sorts.h"

void shell_sort (int *array, int size)
{
    for (int k = 7; k > 0; k -= 2)
    {
        for (int i = 0; (size > k) && (i + k < size); ++k)
        {
            if (*(array + i) < *(array + i + k))
            {
                for (int j = i; j >= 0; j -= k)
                {
                    *(array + j) += *(array + j + k);
                    *(array + j + k) = *(array + j) - *(array + j + k);
                    *(array + j) = *(array + j) - *(array + j + k);
                }
            }
        }
    }
}