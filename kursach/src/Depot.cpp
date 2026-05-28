#include "Depot.hpp"

Depot::~Depot()
{
    for (int i = 0; i < _count; ++i)
    {
        if (_queue[(_head + i) % _capacity] != nullptr)
        {
            delete _queue[(_head + i) % _capacity];
        }
    }
    _number = -1;
    _capacity = 0;
    delete[] _queue;
    _head = 0;
    _tail = 0;
    _count = 0;

}

int Depot::getNumber() const { return _number; }

int Depot::getCapacity() const { return _capacity; }

int Depot::getCount() const { return _count; }

int Depot::getHead() const { return _head; }

const Train* const* Depot::getQueue() const { return _queue; }

bool Depot::addTrain(Train* elem_)
{
    if ((   _head < _tail && (_tail + 1 >= _capacity && _head == 0)) // если голова перед хвостом и ни после хвоста, ни перед головой нет места
        ||  _head > _tail && _head - _tail == 1) // если голова после хвоста и между ними нет места
    {
        return false;
    }

    if (_count != 0 && _tail + 1 < _capacity) // если после хвоста есть место и уже есть поезда
    {
        _queue[_tail + 1] = elem_;
        ++_tail;
    } else // если после хвоста нет места или нет ни одного поезда, значит следующее место только в [0]
    {
        _queue[0] = elem_;
        _tail = 0;
    }

    ++_count;
    return true;
}

Train* Depot::popTrain() 
{
    if (_count == 0)
    {
        return nullptr;
    }

    Train* result = _queue[_head];
    _queue[_head] = nullptr; // Зануление ссылки элемента очереди
    --_count;

    if (_count == 0)
    {
        return result;
    }

    if (_head + 1 == _capacity)
    {
        _head = 0;
    } else
    {
        ++_head;
    }
    
    return result;
}

const Train* Depot::checkTrain() const
{
    if (_count == 0) { return nullptr; };

    return _queue[_head];
}

Train* Depot::findTrain(std::string reg_num_)
{
    for (int i = 0; i < _count; ++i)
    {
        if (_queue[(_head + i) % _capacity]->getRegNum() == reg_num_)
        {
            return _queue[(_head + i) % _capacity];
        }
    }

    return nullptr;
}

void Depot::show(int tab_count_)
{
    for (int i = 0; i < tab_count_; ++i)
    {
        std::cout << '\t';
    }
    std::cout << "Number: " << _number << ":" << std::endl;

    if (_count == 0)
    {
        for (int i = 0; i < tab_count_ + 1; ++i)
        {
            std::cout << '\t';
        }
        std::cout << "Empty" << std::endl;
        return;
    }
    
    for (int i = 0; i < _count; ++i)
    {
        _queue[(_head + i) % _capacity]->show(tab_count_ + 1);
    }
    std::cout << std::endl;
}