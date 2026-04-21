#include "Tree.hpp"

#include <iostream>
#include "ctime"

void direct(Tree *p, int space)
{
    if (p == nullptr)
    {
        return;
    }
    for (int i = 0; i < space; ++i)
    {
        std::cout << "     ";
    }
    
    std::cout << p->data << std::endl;
    
    if (p->left != nullptr) {
        direct(p->left, space + 1);
    }
    
    if (p->right != nullptr)
    {
        direct(p->right, space + 1);
    }
}

void simmetric(Tree *p, int space)
{
    if (p == nullptr)
    {
        return;
    }
    if (p->left != nullptr) {
        simmetric(p->left, space + 1);
    }
    
    for (int i = 0; i < space; ++i)
    {
        std::cout << "     ";
    }
    std::cout << p->data << std::endl;
    
    if (p->right != nullptr)
    {
        simmetric(p->right, space + 1);
    }
}

void reverse(Tree *p, int space)
{
    if (p == nullptr)
    {
        return;
    }
    if (p->right != nullptr) {
        reverse(p->right, space + 1);
    }
    
    for (int i = 0; i < space; ++i)
    {
        std::cout << "     ";
    }
    std::cout << p->data  << std::endl;
    
    if (p->left != nullptr)
    {
        reverse(p->left, space + 1);
    }    
}

Tree* random_filling(Tree* tree, int start, int end, int count)
{
    if (count == 0)
    {
        return nullptr;
    }
    int Nl = (int)(count / 2);
    int Nr = count - Nl - 1;
    tree = new Tree();
    int determ = (end - start + 1);
    tree->data = rand() % determ + start;
    tree->left = random_filling(tree->left, start, end, Nl);
    tree->right = random_filling(tree->right, start, end, Nr);
    return tree;
}