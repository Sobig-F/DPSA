#include <iostream>

using namespace std;

struct Tree
{
public:

    struct Node
    {
        int data;
        Node *left;
        Node *right;
        int count;

        Node(int data) {
            this->data = data;
            this->count = 0;
            this->left = nullptr;
            this->right = nullptr;
        }

        ~Node() {
            if (this->left) {
                delete this->left;
            }
            if (this->right) {
                delete this->right;
            }
            this->data = 0;
            this->left = nullptr;
            this->right = nullptr;
            this->count = 0;
        }
    };

private:
    Node *Head;
    int size;
    
    void simmetric_print (Node *p, int space)
    {
        if (p->left != nullptr) {
            simmetric_print(p->left, space + 1);
        }
        
        for (int i = 0; i < space; ++i)
        {
            cout << "     ";
        }
        cout << p->data << endl;
        
        if (p->right != nullptr)
        {
            simmetric_print(p->right, space + 1);
        }
    }

    void find_p (Node *p, int data, Node *result)
    {   
        if (p->data == data)
        {
            result = p;
        }
        
        if (p->left != nullptr) {
            find_p(p->left, data, result);
        }
        
        if (p->right != nullptr)
        {
            find_p(p->right, data, result);
        }
    }

    void clean_p (Node *p)
    {
        if (p->left != nullptr)
        {
            clean_p(p->left);
            p->left = nullptr;
        }

        if (p->right != nullptr)
        {
            clean_p(p->right);
            p->right = nullptr;
        }

        delete p;
        --this->size;
    }

public:

    Tree() {
        this->Head = nullptr;
        this->size = 0;
    }

    ~Tree() {
        delete this->Head;
        this->Head = nullptr;
        this->size = 0;
    }

    Node* find (int data)
    {
        if (this->size == 0) {
            return nullptr;
        }
        Node *result = nullptr;
        find_p(this->Head, data, result);
        return result;
    }

    int get_size ()
    {
        return this->size;
    }

    void push_side(Node *node, int side, int data) { //0 - left, 1 - right
        if (side) {
            node->right = new Node(data);
        } else {
            node->left = new Node(data);
        }
    }

    void delete_node(Node *node) {
        delete node;
    }

    void simmetric()
    {
        if (this->size == 0) {
            return;
        }
        simmetric_print(this->Head, 0);
        cout << endl;
    }
};