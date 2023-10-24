#include <iostream>
#define SIZE 10

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class HashTable
{
public:
    Node** HT;

    HashTable()
    {
        HT = new Node*[10];
        for(int i = 0; i<10; i++)
        {
            HT[i] = nullptr;
        }
    }

    int hash(int key)
    {
        return key%10;
    }

    void Insert(int key){
        int hId = hash(key);
        Node* t = new Node;
        t -> data = key;
        t ->next = nullptr;

        /// Case 1: No nodes in the linked list
        if(HT[hId] == nullptr)
        {
            HT[hId] = t;
        }
        else{
            Node* p = HT[hId];
            Node* q = HT[hId];
            ///Traverse to find insert position
            while(p != nullptr && p->data < key)
            {
                q = p;
                p = p->next;
            }
            /// Case: insert position is first
            if(q == HT[hId]){
                t->next = HT[hId];
                HT[hId] = t;
            }
            else{
                t->next = q->next;
                q->next = t;
            }
        }
    }

    int Search(int key)
    {
        int hId = hash(key);
        Node *p = HT[hId];
        int i = 0;

        while(p != nullptr)
        {
            if(p->data == key)
            {
                cout<<hId<<",";
                return i;
            }
            p = p->next;
            i++;
        }
        return -1;
    }
};

int hashf(int key)
{
    return key%SIZE;
}
int probe(int H[], int key)
{
    int index = hashf(key);
    int i = 0;
    while(H[index+i]%SIZE!=0)
        i++;
    return (index+i)%SIZE;
}

void Insert(int H[], int key)
{
    int index = hashf(key);
    if(H[index]!=0)
        index = probe(H, key);
    H[index] = key;
}

int Search(int H[], int key)
{
    int index = hashf(key);
    int i = 0;
    while(H[(index+i)%SIZE]!=key)
        i++;
    return (index+i)%SIZE;
}

int main()
{
//    int A[] = {16,12,25,30,25,39,6,122,5,68,75};
//    int n = sizeof(A)/sizeof(A[0]);
//    HashTable H;
//    for(int i = 0; i<n; i++)
//    {
//        H.Insert(A[i]);
//    }
//    cout << "Successful Search" <<endl;
//    int key = 16;
//    int value = H.Search(key);
//    cout << "Key: "<<key <<", Value: "<<H.Search(key)<<endl;
//    key = 95;
//	value = H.Search(key);
//	cout << "Key: " << key << ", Value: " << value << endl;

    int HT[10] = {0};
    Insert(HT,12);
    Insert(HT,43);
    Insert(HT,48);
    Insert(HT,52);
    for(int i = 0;i<10;i++){cout<<HT[i]<<" ";}


    return 0;
}
