#include "Tree.hpp"

#include <iostream>

void direct(Tree *p_, int space_)
{
    if (p_ == nullptr)
    {
        return;
    }
    for (int i = 0; i < space_; ++i)
    {
        std::cout << "     ";
    }
    
    std::cout << p_->_data << std::endl;
    
    if (p_->_left != nullptr) {
        direct(p_->_left, space_ + 1);
    }
    
    if (p_->_right != nullptr)
    {
        direct(p_->_right, space_ + 1);
    }
}

void simmetric(Tree *p_, int space_)
{
    if (p_ == nullptr)
    {
        return;
    }
    if (p_->_left != nullptr) {
        simmetric(p_->_left, space_ + 1);
    }
    
    for (int i = 0; i < space_; ++i)
    {
        std::cout << "     ";
    }
    std::cout << p_->_data << std::endl;
    
    if (p_->_right != nullptr)
    {
        simmetric(p_->_right, space_ + 1);
    }
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
    std::cout << p_->_data << std::endl;
    
    if (p_->_left != nullptr)
    {
        reverse(p_->_left, space_ + 1);
    }    
}

Tree* find(Tree *p_, int data_)
{
    if (p_ == nullptr)
    {
        return nullptr;
    }

    if (p_->_data == data_)
    {
        return p_;
    }

    Tree *result = find(p_->_left, data_);
    if (result)
    {
        return result;
    }

    result = find(p_->_right, data_);
    if (result)
    {
        return result;
    }

    return nullptr;
}

Tree* insertBySide(Tree *p_, int target_, int data_, int side_)
{
    if (p_ == nullptr)
    {
        p_ = new Tree();
        p_->_data = data_;
        p_->_left = nullptr;
        p_->_right = nullptr;

        return p_;
    }

    if (side_ != 0 && side_ != 1)
    {
        return p_;
    }

    Tree *node = find(p_, target_);

    if (node == nullptr)
    {
        return p_;
    }

    if (node->_left != nullptr && node->_right != nullptr)
    {
        return p_;
    }

    if ((side_ == 0 || node->_right != nullptr) && node->_left == nullptr)
    {
        node->_left = new Tree();
        node->_left->_data = data_;
    } else if ((side_ == 1 || node->_left != nullptr) && node->_right == nullptr)
    {
        node->_right = new Tree();
        node->_right->_data = data_;
    }

    return p_;
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
