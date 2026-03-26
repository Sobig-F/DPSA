#include "List.hpp"

#include <iostream>

void Print(Node* list_)
{
    Node* base = list_;
    Node* nested = nullptr;

    std::cout << "[" << std::endl;
    while (base != nullptr)
    {
        std::cout << "[(" << base->_data << ")";
        nested = base->_list;
        while (nested != nullptr)
        {
            std::cout << ", " << nested->_data;
            nested = nested->_next;
        }
        std::cout << "]";
        
        base = base->_next;

        if (base != nullptr)
        {
            std::cout << ",";
        }
        std::cout << std::endl;
    }
    std::cout << "]" << std::endl;
}

bool Exist(Node* list_, int data_)
{
    Node* base = list_;
    Node* nested = nullptr;
    bool result = false;

    while (base != nullptr && !result)
    {
        nested = base->_list;
        while (nested != nullptr)
        {
            if (nested->_data == data_)
            {
                result = true;
                break;
            }

            nested = nested->_next;
        }

        base = base->_next;
    }

    return result;
}

Node* PushListBefore(Node* list_, int target_, int data_)
{
    if (list_ == nullptr)
    {
        return list_;
    }

    Node* base = list_;

    while (base != nullptr)
    {
        if (base->_data != target_)
        {
            base = base->_next;
            continue;
        }

        Node* element = new Node();
        element->_data = data_;
        element->_prev = base->_prev;
        element->_next = base;
        element->_list = nullptr;

        if (base->_prev != nullptr)
        {
            base->_prev->_next = element;
        }
        base->_prev = element;

        if (base == list_)
        {
            return element;
        }

        break;
    }

    return list_;
}

Node* PushListAfter(Node* list_, int target_, int data_)
{
    if (list_ == nullptr)
    {
        list_ = new Node();
        list_->_data = data_;
        list_->_prev = nullptr;
        list_->_next = nullptr;
        list_->_list = nullptr;

        return list_;
    }

    Node* base = list_;

    while (base != nullptr)
    {
        if (base->_data != target_)
        {
            base = base->_next;
            continue;
        }

        Node* element = new Node();
        element->_data = data_;
        element->_prev = base;
        element->_next = base->_next;
        element->_list = nullptr;

        if (base->_next)
        {
            base->_next->_prev = element;
        }
        base->_next = element;

        break;
    }

    return list_;
}

void PushElemBefore(Node* list_, int head_, int target_, int data_)
{
    if (list_ == nullptr)
    {
        return;
    }

    Node* base = list_;
    Node* nested = nullptr;

    while (base != nullptr)
    {
        // std::cout << base->_data << std::endl;
        if (base->_data != head_)
        {
            base = base->_next;
            continue;
        }
        
        nested = base->_list;
        
        while (nested != nullptr)
        {
            // std::cout << nested->_data << std::endl;
            if (nested->_data != target_)
            {
                nested = nested->_next;
                continue;
            }

            Node* element = new Node();
            element->_data = data_;
            element->_prev = nested->_prev;
            element->_next = nested;
            element->_list = nullptr;

            if (nested->_prev != nullptr)
            {
                nested->_prev->_next = element;
            } else
            {
                base->_list = element;
            }
            nested->_prev = element;

            return;
        }

        return;
    }
}

void PushElemAfter(Node* list_, int head_, int target_, int data_)
{
    if (list_ == nullptr)
    {
        return;
    }

    Node* base = list_;
    Node* nested;

    while (base != nullptr)
    {
        if (base->_data != head_)
        {
            base = base->_next;
            continue;
        }

        if (base->_list == nullptr)
        {
            Node* element = new Node();
            element->_data = data_;
            element->_prev = nullptr;
            element->_next = nullptr;
            element->_list = nullptr;

            base->_list = element;

            break;
        }

        nested = base->_list;

        while (nested != nullptr)
        {
            if (nested->_data != target_)
            {
                nested = nested->_next;
                continue;
            }

            Node* element = new Node();
            element->_data = data_;
            element->_prev = nested;
            element->_next = nested->_next;
            element->_list = nullptr;

            if (nested->_next != nullptr)
            {
                nested->_next->_prev = element;
            }
            nested->_next = element;

            return;
        }
    }
}

Node* DeleteList(Node* list_, int target_)
{
    if (list_ == nullptr)
    {
        return list_;
    }

    Node* base = list_;

    while (base != nullptr)
    {
        if (base->_data != target_)
        {
            base = base->_next;
            continue;
        }

        Node* temp = nullptr;

        if (base->_list != nullptr)
        {
            while (base->_list != nullptr)
            {
                temp = base->_list->_next;
                delete base->_list;
                base->_list = temp;
            }
        }

        if (base == list_)
        {
            temp = nullptr;
            if (list_->_next != nullptr)
            {
                temp = list_->_next;
                temp->_prev = nullptr;
            }
            delete list_;
            return temp;
        }

        base->_prev->_next = base->_next;
        if (base->_next != nullptr)
        {
            base->_next->_prev = base->_prev;
        }

        delete base;
        break;
    }

    return list_;
}

void DeleteElem(Node* list_, int head_, int target_)
{
    Node* base = list_;
    Node* nested = nullptr;

    while (base != nullptr)
    {
        if (base->_data != head_)
        {
            base = base->_next;
            continue;
        }

        nested = base->_list;

        while (nested != nullptr)
        {
            if (nested->_data != target_)
            {
                nested = nested->_next;
                continue;
            }

            if (nested == base->_list)
            {
                base->_list = nested->_next;
                delete nested;
                return;
            }

            nested->_prev->_next = nested->_next;
            if (nested->_next != nullptr)
            {
                nested->_next->_prev = nested->_prev;
            }

            delete nested;
            return;
        }
    }
}