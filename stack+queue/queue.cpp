#include <iostream>
using namespace std;
#include <string.h>

struct node {
    char info;
    node* pNext;
};

struct  queue{
    node* pHead;
    node* pTail;
};

struct stack
{
    node* pHead;
    node* pTail;
};

//Khởi tạo ds rỗng
void CreateEmptyQueue(queue &q)
{
    q.pHead = q.pTail = NULL;
}

void CreateEmptyStack(stack &s)
{
    s.pHead = s.pTail = NULL;
}

node* CreateNode(char x)
{
    node* p =new node;
    p->info=x;
    p->pNext=NULL;
    return p;
}

// add tail
void EnQueue(queue &q,node* p)      
{
    if(q.pHead==NULL)
        q.pHead=q.pTail=p;
    else
    {
        q.pTail->pNext=p;
        q.pTail=p;
    }
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

//xoa dau
void pop(stack &s)
{
    node *p;
    p = s.pHead;
    s.pHead = s.pHead->pNext;
    if(s.pHead == NULL)     s.pTail= NULL;
    delete p;
}

void DeQueue(queue &q) {
    node *p;
    p = q.pHead;
    q.pHead = q.pHead->pNext;
    if(q.pHead == NULL)     q.pTail= NULL;
    delete p;
}

node* top(stack l)
{
    return l.pHead;
}

node* top(queue q)
{
    return q.pHead;
}

void CreateQueue(queue &q)
{
    string st;
    getline(cin, st);
    if(st.length()==0)
    {
        cout << "EMPTY";
        return;
    }
    stack s;
    CreateEmptyQueue(q);
    CreateEmptyStack(s);
    for(int i=0; i<st.length(); i++)
    {
        if(st[i]>='A' && st[i]<='Z')  st[i]+=32;
        EnQueue(q, CreateNode(st[i]));
        push(s, CreateNode(st[i]));
    }
    char s1, s2;
    node* p1;
    node* p2;
    for(int i=0; i<st.length(); i++)
    {
        p1 = top(q);
        p2 = top(s);
        s1 = p1->info;
        s2 = p2->info;
        if(s1!=s2)
        {
            cout << "FALSE";
            return;
        }  
        pop(s);
        DeQueue(q);
    }
    cout << "TRUE";
}

int main() {
    queue q;
    CreateQueue(q);
    return 0;
}