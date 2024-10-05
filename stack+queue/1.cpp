#include<iostream>
using namespace std;

struct node
{
    int info;
    node* pNext;
};

struct stack
{
    node* pHead;
};

int isEmpty(stack &s)
{
    if(s.pHead == NULL) return 1;
    return 0;
}

//giong AddHead trong dslk
void push(stack &l, node* p)
{
    if(l.pHead == NULL)
        l.pHead = p;
    else
        //
}

//giong RemoveHead trong dslk
bool pop(stack &l)
{
    node *p;
    if(l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = l.pHead->pNext;
        if(l.pHead == NULL)     l.pTail= NULL;
        delete p;
        return 1;   //da xoa phan tu
    }
    return 0;       //list rong ko coo phan tu de xoa
}

node* top(stack s)
{
    return s.pHead;
}

int main()
{
    return 1;
}