#include "iostream"
#include "ctime"

using namespace std;

struct Tree
{
private:
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
            this->height = 1;
            this->count = 1;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    unsigned char p_height(Node* p)
    {
        return p?p->height:0;
    }

    int bfactor(Node* p)
    {
        return p_height(p->right)-p_height(p->left);
    }

    void fixheight(Node* p)
    {
        unsigned char hl = p_height(p->left);
        unsigned char hr = p_height(p->right);
        p->height = (hl>hr?hl:hr)+1;
    }

    Node* rotateright(Node* p)
    {
        Node* q = p->left;
        p->left = q->right;
        q->right = p;
        fixheight(p);
        fixheight(q);
        return q;
    }

    Node* rotateleft(Node* q)
    {
        Node* p = q->right;
        q->right = p->left;
        p->left = q;
        fixheight(q);
        fixheight(p);
        return p;
    }

    Node* balance(Node* p)
    {
        fixheight(p);
        if( bfactor(p)==2 )
        {
            if( bfactor(p->right) < 0 )
                p->right = rotateright(p->right);
            return rotateleft(p);
        }
        if( bfactor(p)==-2 )
        {
            if( bfactor(p->left) > 0  )
                p->left = rotateleft(p->left);
            return rotateright(p);
        }
        return p;
    }

    Node* insert(Node* p, int k)
    {
        if(p == nullptr)
        {
            return new Node(k);
        } else if( k < p->data )
        {
            p->left = insert(p->left, k);
        } else if (k > p->data)
        {
            p->right = insert(p->right, k);
        } else if (k == p->data)
        {
            p->count += 1;
        }
        
        if (k != p->data)
        {
            return balance(p);
        } else
        {
            return p;
        }
    }

    Node* head;

    
    void direct_print (Node *p)
    {
        for (int i = 0; i < p->height; ++i)
        {
            cout << "   ";
        }
        cout << p->data;
        
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
        cout << p->data << "(" << p->count << ")";
        
        if (p->right != nullptr)
        {
            simmetric_print(p->right);
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
        cout << p->data;
    }
    
    void p_find(Node *p, int data, Node *result)
    {
        if (data < p->data && p->left != nullptr)
        {
            result = p->left;
        } else if (data > p->data && p->right != nullptr)
        {
            result = p->right;
        } else if (data == p->data)
        {
            result = p;
        }
    }

    Node* findmin(Node* p)
    {
        return p->left ? findmin(p->left) : p;
    }

    Node* removemin(Node* p)
    {
        if (p->left == 0)
            return p->right;
        p->left = removemin(p->left);
        return balance(p);
    }

    Node* remove(Node* p, int k)
    {
        if (p == nullptr)
        {
            return 0;
        } else if (k < p->data)
        {
            p->left = remove(p->left, k);
        } else if ( k > p->data )
        {
            p->right = remove(p->right, k);
        } else {
            if (p->count > 1)
            {
                Node* q = p->left;
                Node* r = p->right;
                
                delete p;
                
                if(r == nullptr) 
                {
                    return q;
                }
    
                Node* min = findmin(r);
                min->right = removemin(r);
                min->left = q;
                
                return balance(min);
            } else {
                p->count -= 1;
            }
        }
        return balance(p);
    }
    
public:
    Tree ()
    {
        this->head = nullptr;
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

    // void direct ()
    // {
    //     direct_print(this->head);
    //     cout << endl;
    // }

    void simmetric()
    {
        simmetric_print(this->head);
        cout << endl;
    }

    void reverse ()
    {
        reverse_print(this->head);
        cout << endl;
    }

    void find(int data)
    {
        Node *p;
        p_find(this->head, data, p);

        if (p == nullptr)
        {
            cout << "Element was not found" << endl;
        } else {
            cout << "Element: " << p->data << "\nCount: " << p->count << endl;
        }
    }

    void add (int data)
    {
        this->head = insert(this->head, data);
    }

    void p_delete (int data)
    {
        this->head = remove(this->head, data);
    }
};

