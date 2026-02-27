#include "list.hpp"

List::~List()
{
    while (_head->_next != _head)
    {
        delete _head->_next;
    }

    delete _head;
}

List::Node::Node(int data_ = 0, Node* prev_ = nullptr, Node* next_ = nullptr)
: _data{data_}
, _prev{prev_}
, _next{next_}
{
    if (prev_ != nullptr)
    {
        prev_->_next = this;
    }
    if (next_ != nullptr)
    {
        next_->_prev = this;
    }
}

List::Node::~Node()
{
    _data = 0;
    _next->_prev = _prev;
    _prev->_next = _next;
    _next = nullptr;
    _prev = nullptr;
}

std::pair<int, List::Node*> List::Find(int data_) const noexcept
{
    return [&]() -> std::pair<int, List::Node*> {
        if (_head == nullptr)
        {
            return std::make_pair(-1, nullptr);
        }
        if (_head->_data == data_)
        {
            return std::make_pair(0, _head);
        }
        int pos = 1;
        for (Node* i = _head->_next; i != _head; i = i->_next)
        {
            if (i->_data == data_)
            {
                return std::make_pair(pos, i);
            }
            ++pos;
        }
        return std::make_pair(-1, nullptr);
    }();
}

void List::AddAfter(int data_, int target_) noexcept
{
    if (_head == nullptr)
    {
        _head = new Node(data_, nullptr, nullptr);
        _head->_next = _head;
        _head->_prev = _head;
        std::cout << "Success" << std::endl;
        return;
    }
    
    Node* target = Find(target_).second;

    if (!target)
    {
        std::cout << "Not found" << std::endl;
        return;
    }

    target->_next = new Node(data_, target, target->_next);

    std::cout << "Success" << std::endl;
}

void List::AddBefore(int data_, int target_) noexcept
{
    if (_head == nullptr)
    {
        std::cout << "Empty" << std::endl;
        return;
    }
    
    Node* target = Find(target_).second;

    if (!target)
    {
        std::cout << "Not found" << std::endl;
        return;
    }

    target->_prev = new Node(data_, target->_prev, target);

    if (target == _head)
    {
        _head = target->_prev;
    }

    std::cout << "Success" << std::endl;
}

int List::ForwardFind(int data_) const noexcept
{
    return Find(data_).first;
}

int List::OppositeFind(int data_) const noexcept
{
    return [&]() -> int {
        if (!_head)
        {
            return -1;
        }
        if (_head->_prev->_data == data_)
        {
            return 0;
        }
        int pos = 1;
        for (Node* i = _head->_prev->_prev; i != _head; i = i->_prev)
        {
            if (i->_data == data_)
            {
                return pos;
            }
            ++pos;
        }
        return -1;
    }();
}

void List::ForwardView() const noexcept
{
    if (!_head)
    {
        std::cout << "Empty" << std::endl;
        return;
    }

    std::cout << "[" << _head->_data;

    for (Node* i = _head->_next; i != _head; i = i->_next)
    {
        std::cout << ", " << i->_data;
    }

    std::cout << "]" << std::endl;
}

void List::OppositeView() const noexcept
{
    if (!_head)
    {
        std::cout << "Empty" << std::endl;
        return;
    }

    std::cout << "[" << _head->_prev->_data;

    for (Node* i = _head->_prev->_prev; i != _head->_prev; i = i->_prev)
    {
        std::cout << ", " << i->_data;
    }

    std::cout << "]" << std::endl;
}

void List::del(int data_) noexcept
{
    Node* target = Find(data_).second;

    if (!target)
    {
        std::cout << "Not found" << std::endl;
        return;
    }

    if (target == _head)
    {
        _head = _head->_next;
    }

    delete target;
}