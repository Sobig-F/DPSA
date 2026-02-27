#include "iostream"
#include "ctime"
#include <stack>

using namespace std;

struct Node
{
    int data;
    int count;
    int height;
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

struct Tree
{
private:
    int size;

    Node *head;

    void direct_print (Node *p)
    {
        for (int i = 0; i < p->height; ++i)
        {
            cout << "   ";
        }
        cout << p->data << endl;
        
        if (p->left != nullptr) {
            direct_print(p->left);
        }
        
        if (p->right != nullptr)
        {
            direct_print(p->right);
        }
    }
    
    void simmetric_print (Node *p)
    {
        if (p->left != nullptr) {
            simmetric_print(p->left);
        }
        
        for (int i = 0; i < p->height; ++i)
        {
            cout << "   ";
        }
        cout << p->data << endl;
        // cout << p->data << "(" << p->count << ")" << endl;
        
        if (p->right != nullptr)
        {
            simmetric_print(p->right);
        }
    }

    void simmetric_print_r (Node *p)
    {
        Node *current = p;
        stack<const Node*> stack;
        while (current != nullptr || !stack.empty())
        {
            while (current != nullptr)
            {
                stack.push(current);
                current = current->left;
            }
            
            for (int i = 0; i < stack.top()->height; ++i)
            {
                cout << "   ";
            }
            cout << stack.top()->data << endl;

            current = stack.top()->right;
            stack.pop();
        }
    }
    
    void reverse_print (Node *p)
    {
        if (p->right != nullptr) {
            reverse_print(p->right);
        }
        
        if (p->left != nullptr)
        {
            reverse_print(p->left);
        }
        
        for (int i = 0; i < p->height; ++i)
        {
            cout << "   ";
        }
        cout << p->data  << endl;
    }

    Node* insert (Node *p, int data, int height)
    {
        if (p == nullptr)
        {
            return new Node(data);
        }

        int l_count = p->left == nullptr ? -1 : p->left->count;
        int r_count = p->right == nullptr ? 0 : p->right->count;

        p->count += 1;
        if (l_count - r_count != 0)
        {
            p->left = insert(p->left, data);
        } else {
            p->right = insert(p->right, data);
        }

        return p;
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
        this->head = insert(this->head, data, 0);
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
        direct_print(this->head);
        cout << endl;
    }

    void simmetric()
    {
        simmetric_print(this->head);
        cout << endl;
    }

    void simmetric_r()
    {
        simmetric_print_r(this->head);
        cout << endl;
    }

    void reverse ()
    {
        reverse_print(this->head);
        cout << endl;
    }

    Node* find (int data)
    {
        Node *result = nullptr;
        find_p(this->head, data, result);
        return result;
    }

    int push_side (int element, int side, int data)
    {
        Node *current = nullptr;
        find_p(this->head, element, current);

        if (current != nullptr)
        {
            Node *r = new Node(data, current->height + 1);
            if (!side)
            {
                r->left = current->left;
                current->left = r;
            } else {
                r->right = current->right;
                current->right = r;
            }

            Node *p = r;
            stack<const Node*> stack;
            while (p != nullptr || !stack.empty())
            {
                while (p != nullptr)
                {
                    stack.push(p);
                    if (p->left != nullptr)
                    {
                        p->left->height = p->height + 1;
                    }
                    p = p->left;
                }
                
                for (int i = 0; i < stack.top()->height; ++i)
                {
                    cout << "   ";
                }
                cout << stack.top()->data << endl;

                p = stack.top()->right;
                p->height = stack.top()->height;
                stack.pop();
            }
            
        } else {
            return 0;
        }

        return 1;
    }

    void clean ()
    {
        if (this->head != nullptr)
        {
            clean_p(this->head);
            this->head = nullptr;
        }
    }
};