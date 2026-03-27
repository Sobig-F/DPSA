#include "Node.hpp"

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

void simmetric_r(Tree *p, int space)
{
    if (p == nullptr)
    {
        return;
    }
    if (p->left != nullptr) {
        simmetric_r(p->left, space + 1);
    }
    
    for (int i = 0; i < space; ++i)
    {
        std::cout << "     ";
    }
    std::cout << p->data << std::endl;
    
    if (p->right != nullptr)
    {
        simmetric_r(p->right, space + 1);
    }
}

void simmetric(Tree *p)
{
    struct Stack
    {
        Tree* data;
        Stack* prev;
        int level; // добавляем уровень для отступов
    };
    
    Stack* stack = nullptr;
    Tree* current = p;
    Stack* curr_stack;
    int level = 0;
    
    while (current != nullptr || stack != nullptr)
    {
        while (current != nullptr)
        {
            curr_stack = new Stack();
            curr_stack->data = current;
            curr_stack->prev = stack;
            curr_stack->level = level;
            stack = curr_stack;
            
            level++;
            current = current->left;
        }
        
        if (stack != nullptr)
        {
            current = stack->data;
            
            // Вывод с отступами
            for (int i = 0; i < stack->level; ++i)
            {
                std::cout << "     ";
            }
            std::cout << current->data << std::endl;
            
            current = current->right;
            level = stack->level + 1;
            
            curr_stack = stack;
            stack = stack->prev;
            delete curr_stack;
        }
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