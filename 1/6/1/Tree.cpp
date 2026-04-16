#include <iostream>

#include "Tree.hpp"

int find(Tree *p_, int target_)
{
    if (p_ == nullptr)
    {
        return 0;
    }

    if (p_->_data == target_)
    {
        return p_->_count;
    }

    if (p_->_data > target_)
    {
        return find(p_->_left, target_);
    } else
    {
        return find(p_->_right, target_);
    }

    return 0;
}

Tree* insertRecursion(Tree *p_, int data_)
{
    if (p_ == nullptr)
    {
        p_ = new Tree();
        p_->_data = data_;
    } else if (p_->_data == data_)
    {
        ++p_->_count;
    } else if (p_->_data > data_)
    {
        p_->_left = insertRecursion(p_->_left, data_);
    } else
    {
        p_->_right = insertRecursion(p_->_right, data_);
    }

    return p_;
}

Tree* insert(Tree *p_, int data_)
{
    Tree *current = p_;

    while (current != nullptr)
    {
        if (current->_data == data_)
        {
            ++current->_count;
            current = nullptr;
        } else if (current->_data > data_)
        {
            if (current->_left == nullptr)
            {
                break;
            }
            current = current->_left;
        } else
        {
            if (current->_right == nullptr)
            {
                break;
            }
            current = current->_right;
        }
    }

    if (current == nullptr)
    {
        p_ = new Tree();
        p_->_data = data_;
    }

    if (current->_data > data_)
    {
        current->_left = new Tree();
        current->_left->_data = data_;
    } else
    {
        current->_right = new Tree();
        current->_right->_data = data_;
    }

    return p_;
}

Tree* deleteNode(Tree *p_, int data_)
{
    Tree *current = p_;
    Tree *current_parent = nullptr;

    while (current != nullptr && current->_data != data_)
    {
        current_parent = current;
        if (current->_data > data_)
        {
            current = current->_left;
        } else
        {
            current = current->_right;
        }
    }

    if (current == nullptr)
    {
        return p_;
    }

    if (current->_right == nullptr)
    {
        if (current_parent == nullptr)
        {
            p_ = p_->_left;
        } else if (current_parent->_left == current)
        {
            current_parent->_left = current->_left;
        } else
        {
            current_parent->_right = current->_left;
        }
        delete current;
        return p_;    
    }

    Tree *replacement = current->_right;
    Tree *replacement_parent = nullptr;

    while (replacement->_left != nullptr)
    {
        replacement_parent = replacement;
        replacement = replacement->_left;
    }

    replacement->_left = current->_left;
    if (replacement_parent != nullptr)
    {
        replacement_parent->_left = replacement->_right;
        replacement->_right = current->_right;
    }
    if (current_parent == nullptr)
    {
        p_ = replacement;
    } else if (current_parent->_left == current)
    {
        current_parent->_left = replacement;
    } else
    {
        current_parent->_right = replacement;
    }
    delete current;
    
    return p_;
}

void reverse(Tree *p_, int space_)
{
    if (p_ == nullptr)
    {
        return;
    }
    if (p_->_right != nullptr) {
        reverse(p_->_right, space_ + 1);
    }
    
    for (int i = 0; i < space_; ++i)
    {
        std::cout << "     ";
    }
    std::cout << p_->_data << "(" << p_->_count << ")" << std::endl;
    
    if (p_->_left != nullptr)
    {
        reverse(p_->_left, space_ + 1);
    }   
}

void simmetricLine(Tree *p_)
{
    if (p_ == nullptr)
    {
        return;
    }
    if (p_->_left != nullptr) {
        simmetricLine(p_->_left);
    }

    std::cout << p_->_data << "(" << p_->_count << ") ";
    
    if (p_->_right != nullptr)
    {
        simmetricLine(p_->_right);
    }
}

Tree* clean(Tree *p_)
{
    if (p_ == nullptr)
    {
        return p_;
    }

    p_->_left = clean(p_->_left);
    p_->_right = clean(p_->_right);

    delete(p_);

    return nullptr;
}