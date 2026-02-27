#include "iostream"
#include "ctime"

using namespace std;

struct Tree
{
private:
    int size;

    struct Node
    {
        int data;
        int count;
        Node *left;
        Node *right;

        Node (int data)
        {
            this->data = data;
            this->count = 0;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    Node *head;

    void direct_print (Node *p, int space)
    {
        for (int i = 0; i < space; ++i)
        {
            cout << "     ";
        }
        cout << p->data << endl;
        
        if (p->left != nullptr) {
            direct_print(p->left, space + 1);
        }
        
        if (p->right != nullptr)
        {
            direct_print(p->right, space + 1);
        }
    }
    
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
    
    void reverse_print (Node *p, int space)
    {
        if (p->right != nullptr) {
            reverse_print(p->right, space + 1);
        }
        
        for (int i = 0; i < space; ++i)
        {
            cout << "     ";
        }
        cout << p->data  << endl;
        
        if (p->left != nullptr)
        {
            reverse_print(p->left, space + 1);
        }
        
    }

    Node* insert (Node *p, int data)
    {
        if (p == nullptr)
        {
            return new Node(data);
        }

        int l_count = p->left == nullptr ? 0 : p->left->count;
        int r_count = p->right == nullptr ? 0 : p->right->count;

        p->count += 1;
        if (l_count - r_count < 1)
        {
            p->left = insert(p->left, data);
        } else {
            p->right = insert(p->right, data);
        }

        return p;
    }

public:
    Tree ()
    {
        this->head = nullptr;
        this->size = 0;
    }

    int get_size ()
    {
        return this->size;
    }

    void add (int data)
    {
        this->head = insert(this->head, data);
        this->size += 1;
    }

    void random_filling (int start, int end, int count)
    {
        srand(time(0));

        int determ = (end - start + 1);

        for (int i = 0; i < count; ++i)
        {
            this->add(rand() % determ + start);
        }
    }

    void direct ()
    {
        if (!this->size) {
            return;
        }
        direct_print(this->head, 0);
        cout << endl;
    }

    void simmetric()
    {
        if (!this->size) {
            return;
        }
        simmetric_print(this->head, 0);
        cout << endl;
    }

    void reverse ()
    {
        if (!this->size) {
            return;
        }
        reverse_print(this->head, 0);
        cout << endl;
    }
};