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

node* CreateNode(char x)
{
    node* p = new node;
    if(p == NULL)   exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void push(stack &s, node* p)
{
    if(s.pHead == NULL)
        s.pHead = p;
    else
    {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

void pop(stack &s)
{
    node *p;
    p = s.pHead;
    s.pHead = s.pHead->pNext;
    if(s.pHead == NULL)     s.pTail= NULL;
    delete p;
}

node* top(stack s)
{
    return s.pHead;
}

void BracketMatching(stack s, char st[])
{
    gets(st);
    CreateEmptyStack(s);
    for(int i=0; i<strlen(st); i++)
    {
        if(st[i] == '(')
            push(s, CreateNode('('));
        if(st[i] == ')')
        {
            if(isEmpty(s)==1)
            {
                cout << "false";
                return;
            }   
            else{
                pop(s);
            }
        }
    }
    if(isEmpty(s) == 1)     cout << "true";
    else                    cout << "false";
}

int main()
{
    stack s;
    char st[100];
    BracketMatching(s,st);
    return 1;
}