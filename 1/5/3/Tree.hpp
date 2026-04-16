#ifndef TREE_HPP
#define TREE_HPP

struct Tree
{
    int _data = 0;
    Tree *_left = nullptr;
    Tree *_right = nullptr;
};

void direct(Tree *p_, int space_ = 0);
void simmetric(Tree *p_, int space_ = 0);
void reverse(Tree *p_, int space_ = 0);

Tree* find(Tree *p_, int data_);
Tree* insertBySide(Tree *p_, int target_, int data_, int side_); //0 - left, 1 - right
Tree* clean(Tree *p_);

#endif