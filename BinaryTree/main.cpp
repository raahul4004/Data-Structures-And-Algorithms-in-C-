#include <iostream>

#include <stdio.h>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q;

public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node *x);
    Node* dequeue();

};

Queue::Queue(int size)
{
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node*[size];
}

Queue::~Queue()
{
    delete [] Q;
}

bool Queue::isEmpty()
{
    if(front == rear)
    {
        return true;
    }
    return false;
}

bool Queue::isFull()
{
    if (rear == size-1)
    {
        return true;
    }
    return false;
}

void Queue::enqueue(Node *x)
{
    if(isFull())
        cout<<"Queue Overflow"<<endl;
    else{
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue() {
    Node* x = nullptr;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}

class Tree
{
public:
    Node *root;

public:
    Tree() { root = nullptr; }
    //~Tree();
    void CreateTree();
    void Preorder(){ Preorder(root); }  // Passing Private Parameter in Constructor
    void Preorder(Node* p);
    void Postorder(){ Postorder(root); }  // Passing Private Parameter in Constructor
    void Postorder(Node* p);
    void Inorder(){ Inorder(root); }
    void Inorder(Node* p);
    void Levelorder(){ Levelorder(root); }  // Passing Private Parameter in Constructor
    void Levelorder(Node* p);
    int Height1(){ return Height1(root); }  // Passing Private Parameter in Constructor
    int Height1(Node* p);
    int Height2(Node* p);
    Node* getRoot(){ return root; }
};

void Tree::CreateTree()
{
    Node *p;
    Node *t;
    int x;

    Queue q(25);

    root = new Node;
    cout << "Enter root value :" ;
    cin >> x;
    root->data = x;
    root->rchild=root->lchild = nullptr;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p = q.dequeue();

        ///To Get value of left child and link it with the node
        cout << "Enter the value of left child "<<p->data << ":";
        cin >> x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }

        ///To get value of right child and link it with the node
        cout << "Enter the value of right child "<<p->data << ":" ;
        cin >> x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            p->rchild = t;
            t->lchild = t->rchild = nullptr;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p)
{
    if(p)
    {
        cout << p->data << ", " <<flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout << p->data << ", " <<flush;
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " <<flush;
    }
}

int Tree::Height1(Node *p)
{
    int x = 0, y = 0;
    if(p == nullptr)
        return 0;
    x = Height1(p->lchild);
    y = Height1(p->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}


///Easy method
int Tree::Height2(Node *p)
{
    if(p == NULL)
        return -1;
    return max(Height2(p->lchild), Height2(p->rchild)) + 1;

}

void Tree::Levelorder(Node *root)
{
    Node *p;
    Queue q(100);

    cout<<root->data;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p = q.dequeue();
        if(p->lchild)
        {
            cout<< p->lchild->data;
            q.enqueue(p->lchild);
        }
        if(p->rchild)
        {
            cout<< p->rchild->data;
            q.enqueue(p->rchild);
        }
    }
}


int main()
{
    Tree t;
    t.CreateTree();
    //t.Inorder();
    //t.Levelorder();
    printf("%d",t.Height2(t.root));
}
