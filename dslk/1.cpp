#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;

struct node {
	int info;
	node* pNext;
};
typedef struct node NODE;

struct List{
	NODE* pHead;
	NODE* pTail;
};
typedef struct List LIST;

//khoi tao danh sach lien ket rong
void CreateEmptyList(LIST &l)
{
    l.pHead = l.pTail = NULL;
}

//tao 1 phan tu moi, ham tra ve dia chi phan tu moi tao
NODE* CreateNode(int x)
{
    NODE* p = new NODE;
    if(p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

//them phan tu vao danh sach
void AddHead(LIST &l, NODE* p)
{
    if(l.pHead == NULL)
        l.pHead = l.pTail = p;
    else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void AddTail(LIST &l, NODE* p)
{
    if(l.pHead == NULL)
        l.pHead = l.pTail = p;
    else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void AddAfterQ(LIST &l, NODE* p, NODE* Q)
{
    if(Q != NULL)
    {
        p->pNext = Q->pNext;
        Q->pNext = p;
        if(l.pTail == Q)
            l.pTail = p;
    }
    else
        AddHead(l, p);
}

//tim phan tu trong dslk don
NODE* SearchNode(LIST l, int x)
{
    // NODE* p = l.pHead;
    // while(p != NULL && p->info != x)
    //     p = p->pNext;
    // return p;
    for(NODE* p = l.pHead; p!=NULL; p=p->pNext)
    {
        if(p->info == x)    return p;
    }
    return NULL;
}

//huy phan tu trong dlsk don
bool RemoveHead(LIST &l, int &x)
{
    NODE* p;
    if(l.pHead != NULL)
    {
        x = l.pHead->info;      //giu gia tri sau khi xoa de sd neu can
        p = l.pHead;
        l.pHead = l.pHead->pNext;
        if(l.pHead == NULL)
            l.pTail = NULL;
        delete p;
        return 1;   //xoa thanh cong
    }
    return 0;       //list rong ko co phan tu de xoa
}

bool RemoveAfterQ(LIST &l, int &x, NODE* Q)
{
    NODE* p;
    if(Q != NULL)
    {
        p = Q->pNext;
        if(p!=NULL)
        {
            if(l.pTail == p)    //neu node xoa la node cuoi cung
                l.pTail = Q;    //cap nhat lai pTail
            x = p->info;
            Q->pNext = p->pNext;
            delete p;
            return 1;
        }
    }
    return 0;
}

bool RemoveX(LIST &l, int x)
{
    NODE* Q;
    NODE* p;
    Q = NULL;
    p = l.pHead;
    while(p!=NULL && p->info!=x)
    {
        Q = p;
        p = p->pNext;
    }
    if(p == NULL)       return 0;
    if(Q != NULL)       return RemoveAfterQ(l, x, Q);
    else                return RemoveHead(l, x);
}

//duyet danh sach
void PrintList(LIST l)
{
    if(l.pHead == NULL)
        cout << "DSLK don rong";
    else{
        NODE* p;
        for(p=l.pHead; p!=NULL; p=p->pNext)
        {
            cout << p->info << " ";
        }
    }
}

void RemoveList(LIST &l)
{
    NODE* p;
    while(l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = p->pNext;
        delete p;
    }
    l.pTail = NULL;
}

// void CreateList(List &l)
// {
//     int n;
//     cin >> n;
//     l.head = l.tail = NULL;
//     for(int i=0; i<n; i++)
//     {
//         ps a;
//         cin >> a.ts >> a.ms;
//         RutGon(a);
//         node* p = CreateNode(a);
//         AddTail(l,p);
//     }
// }

// void PrintList(List l)
// {
//     for(node* p = l.head; p!=NULL; p=p->next)
//         cout << p->info.ts << "/" << p->info.ms << "\n";
// }

int main() {
    List L;
    CreateEmptyList(L);
    AddTail(L, CreateNode(5));      // them node co khoa bang 5 vao danh sach
    cout << "HI";
    return 0;
}
