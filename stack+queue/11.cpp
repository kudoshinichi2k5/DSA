#include<iostream>
#include<string.h>
using namespace std;

struct node
{
    char info;
    node* pNext;
};

struct stack
{
    node* pHead;
};

bool isEmpty(stack &s)
{
    if(s.pHead == NULL)     return 1;
    return 0;
}

void CreateEmptyStack(stack &s)
{
    s.pHead = NULL;
}

node* CreateNode(char x)
{
    node* p = new node;
    if(p == NULL)   exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

//addHead
void push(stack &s, node* p)
{
    if(s.pHead == NULL)
        s.pHead = p;
    else{
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

//RemoveHead
void pop(stack &s)
{
    node* p;
    if(s.pHead == NULL)     return;
    else{
        p = s.pHead;
        s.pHead = p->pNext;
        delete p;
    }
}

node* top(stack s)
{
    return s.pHead;
}

void Func(stack s, char st[])
{
    gets(st);
}

int main()
{
    stack s;
    return 0;
}