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

void array_reverse(stack s, int a[], int n)
{
    cin >> n;
    CreateEmptyStack(s);
    int x;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        node* p = CreateNode(x);
        push(s, p);
    }
    node* temp;
    for(int i=0; i<n; i++)
    {
        temp = top(s);
        a[i] = temp->info;
        if(s.pHead != NULL)        pop(s);
    }
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
}

int main()
{
    stack s;
    int a[100], n;
    array_reverse(s,a,n);
    return 1;
}