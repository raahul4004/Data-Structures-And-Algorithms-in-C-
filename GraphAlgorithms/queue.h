#ifndef queue
#define queue

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class Queue
{
    Node *front = nullptr;
    Node *rear = nullptr;

public:
    void enqueue(int x)
    {
        Node *t;
        t = new Node;
        if(t == nullptr)
        {
            cout<<"Queue is full"<<endl;
        }
        else
        {
            t->data = x;
            t->next = nullptr;

            if(front == nullptr)
                front = rear = t;
            else
            {
                rear->next = t;
                rear = t;
            }
        }
    }

    int dequeue()
    {
        int x = -1;
        if(front == nullptr)
        {
            cout<<"Class is empty"<<endl;
        }
        else{
            Node *t = front;
            x = t->data;
            front = front->next;
            delete(t);
        }
        return x;
    }

    bool isEmpty()
    {
        if(front == nullptr)
            return true;
        return false;
    }
};

#endif //queue
