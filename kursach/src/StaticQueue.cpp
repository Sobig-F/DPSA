#include "StaticQueue.hpp"

namespace types
{
template <typename T>
StaticQueue<T>::StaticQueue(int capacity_){ _queue = new T*[capacity_]; }

template <typename T>
StaticQueue<T>::~StaticQueue(){ delete _queue; }

template <typename T>
bool StaticQueue<T>::push(T* elem_)
{
    if ((   _head < _tail && (_tail + 1 >= _capacity || _head == 0)) // если голова перед хвостом и ни после хвоста, ни перед головой нет места
        ||  _head > _tail && _head - _tail == 1) // если голова после хвоста и между ними нет места
    {
        return false;
    }

    if (_tail + 1 < _capacity) // если после хвоста есть место
    {
        _queue[_tail + 1] = elem_;
        ++_tail;
    } else // если после хвоста нет места, значит следующее место только в [0]
    {
        _queue[0] = elem_;
        _tail = 0;
    }

    ++_count;
    return true;
}

template <typename T>
T* StaticQueue<T>::pop()
{
    if (_tail == _head)
    {
        return nullptr;
    }

    T* elem = _queue[_tail]; // Сохранение ссылки на возвращаемый объект
    _queue[_tail] = nullptr; // Зануление ссылки элемента очереди

    if (_tail == 0)
    {
        _tail == _capacity - 1;
    } else
    {
        --_tail;    
    }
    
    --_count;
    return elem;
}

template <typename T>
int StaticQueue<T>::getCount(){ return _count; }

template <typename T>
int StaticQueue<T>::getCapacity(){ return _capacity; }
} // namespace types
