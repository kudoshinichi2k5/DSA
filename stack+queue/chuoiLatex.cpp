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

bool Func(stack s, char st[])
{
    gets(st);
    CreateEmptyStack(s);
    for(int i=0; i<strlen(st); i++)
    {
        if(st[i]=='(')
            push(s, CreateNode('('));
        if(st[i]==')')
        {
            if(isEmpty(s)==1)
            {
                return 0;
            }
            else
                pop(s);
        }
    }
    for(int i=0; i<strlen(st); i++)
    {
        if(st[i]=='[')
            push(s, CreateNode('['));
        if(st[i]==']')
        {
            if(isEmpty(s)==1)
            {
                return 0;
            }
            else
                pop(s);
        }
    }
    for(int i=0; i<strlen(st); i++)
    {
        if(st[i]=='{')
            push(s, CreateNode('{'));
        if(st[i]=='}')
        {
            if(isEmpty(s)==1)
            {
                return 0;
            }
            else
                pop(s);
        }
    }
    if(isEmpty(s)==1)   return 1;
    return 0;
}

char st[100000];
int main()
{
    stack s;
    cout << Func(s, st);
    return 0;
}