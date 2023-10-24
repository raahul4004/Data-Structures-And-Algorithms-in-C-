#include <iostream>

using namespace std;

class Node{
public:
    Node* lchild;
    int data;
    int height;
    Node* rchild;
};

class AVLtree{
public:

    Node* root = nullptr;
    int NodeHeight(Node *p)
    {
        int hl, hr;
        hl = p && p->lchild?p->lchild->height:0;
        hr = p && p->rchild?p->rchild->height:0;

        return hl>hr?hl+1:hr+1;

    }
    int balanceFactor(Node *p){
        int hl, hr;
        hl = p && p->lchild?p->lchild->height:0;
        hr = p && p->rchild?p->rchild->height:0;

        return hl - hr;
    }

    Node* LLRotation(Node *p)
    {
        Node *pl = p->lchild;
        Node *plr = pl->rchild;

        pl->rchild = p;
        p->lchild = plr;
        p->height = NodeHeight(p);
        pl -> height = NodeHeight(pl);

        if(root == p)
            root = pl;
        return pl;


    }


    Node* Insert(Node *p, int key){

        Node* t;
        if(p == nullptr)
        {
            t = new Node;
            t->data = key;
            t->height = 1;
            t->lchild = t->rchild = nullptr;
            return t;
        }
        if(key < p->data)
            p->lchild = Insert(p->lchild, key);
        else if(key > p-> data)
            p->rchild = Insert(p->rchild, key);

        p->height = NodeHeight(p);
        if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1)
            return LLRotation(p);
//        if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1)
//            return LRRotation(p);

        return p;
    }
    void Inorder(Node *p) {
        if (p){
            Inorder(p->lchild);
            cout << p->data << ", " << flush;
            Inorder(p->rchild);
        }
    }
    void Inorder(){ Inorder(root); }
};

int main()
{
    AVLtree tll;
    tll.root = tll.Insert(tll.root, 30);
    tll.root = tll.Insert(tll.root, 20);
    tll.root = tll.Insert(tll.root, 10);
    tll.Inorder();
    return 0;
}
