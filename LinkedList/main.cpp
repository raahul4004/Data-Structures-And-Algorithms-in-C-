#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;
public:
    LinkedList(){first = NULL;}
    LinkedList(int A[],int n);
    //~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();

};

LinkedList::LinkedList(int A[], int n)
{
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

}

void LinkedList::Display()
{
    Node *t;
    t = first;
    while(t!=NULL)
    {
        std::cout << t->data << " ";
        t = t->next;

    }
}


int main()
{
    int A[] = {1,2,3,4,5};
    LinkedList x(A,5);
    x.Display();
    return 0;
}
