#include "ctime"

template<typename Type>
Type* random_filling (int start, int end, int count)
{
    Type *result = new Type[count];

    srand(time(0));

    int determ = (end - start + 1);

    for (int i = 0; i < count; ++i)
    {
        result[i] = rand() % determ + start;
    }

    return result;
}