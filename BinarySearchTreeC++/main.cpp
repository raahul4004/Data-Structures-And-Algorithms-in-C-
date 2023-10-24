#include <iostream>
using namespace std;

class BstNode
{
public:
    BstNode *left;
    int data;
    BstNode *right;
};

class BST
{
public:
    BstNode *root = NULL;

public:
        void Insert(int key)
        {
            BstNode *t, *p, *r;
            t = root;

            if(root == nullptr)
            {
                p = new BstNode;
                p -> data = key;
                p->left = p->right = nullptr;
                root = p;
            }

            while(t!=nullptr)
            {
                r = t;
                if(key < t->data){
                    t = t->left;
                }
                else if(key > t->data){
                    t = t->right;
                }
                else{
                    return;
                }
            }
            p = new BstNode;
            p -> data = key;
            p->left = p->right = nullptr;

            if(p->data < r->data)
                r->left = p;
            else if(p->data > r->data)
                r->right = p;
        }


};


void Inorder(BstNode *p)
{
    if(p)
    {
        Inorder(p->left);
        printf("%d ",p->data);
        Inorder(p->right);
    }
}



int main()
{

    BST t;
    t.Insert(10);
    t.Insert(20);
    t.Insert(30);
    t.Insert(40);
    t.Insert(50);
    Inorder(t.root);
    return 0;
}
