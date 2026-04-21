#ifndef TREE_HPP
#define TREE_HPP

struct Tree
{
    int _data = 0;
    int _count = 1;
    Tree *_left = nullptr;
    Tree *_right = nullptr;
};

int find(Tree *p_, int target_);
Tree* insertRecursion(Tree *p_, int data_);
Tree* insert(Tree *p_, int data_);
Tree* deleteNode(Tree *p_, int data_);
Tree* clean(Tree *p_);

Tree* randomFill(Tree* p_, int start_, int end_, int count);

void reverse(Tree *p_, int space = 0);
void simmetricLine(Tree *p_);

#endif