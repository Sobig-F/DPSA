#ifndef TREE_HPP
#define TREE_HPP

struct Tree
{
    int data;
    int size;
    Tree* left;
    Tree* right;
};

void direct(Tree *p, int space);
void simmetric_r(Tree *p, int space);
void simmetric(Tree *p);
void reverse(Tree *p, int space);
Tree* random_filling(Tree* tree, int start, int end, int count);

Tree* clean(Tree *p_);

#endif