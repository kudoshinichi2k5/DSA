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
    node* pTail;
};

bool isEmpty(stack &s)
{
    if(s.pHead == NULL)     return 1;
    return 0;
}

void CreateEmptyStack(stack &s)
{
    s.pHead = NULL;
    s.pTail = NULL;
}

node* CreateNode(int x)
{
    node* p = new node;
    if(p == NULL)   exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void push(stack &l, node* p)
{
    if(l.pHead == NULL)
        l.pHead = p;
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void pop(stack &l)
{
    node *p;
    p = l.pHead;
    l.pHead = l.pHead->pNext;
    if(l.pHead == NULL)     l.pTail= NULL;
    delete p;
}

node* top(stack l)
{
    return l.pHead;
}

void decimal_to_binary(int n)
{
    stack s;
    CreateEmptyStack(s);
    if(n==0)    cout << 0;
    int dv;
    int nn = n;
    node* p;
    while(nn!=0)
    {
        dv = nn%2;
        p = CreateNode(dv);
        push(s, p);
        nn/=2;
    }
    node* tmp;
    while(s.pHead!=NULL)
    {
        tmp = top(s);
        cout << tmp->info;
        pop(s);
    }
}

int main()
{
    int n;
    cin >> n;
    decimal_to_binary(n);
    return 1;
}