#include<iostream>
using namespace std;

struct DNode
{
    int info;
    DNode* pNext;
    DNode* pPrev;
};

struct DList
{
    DNode* pHead;
    DNode* pTail;
};

void Menu();
void CreateDList(DList &);
void CreateEmptyDList(DList &);
void AddTail(DList &, int);
void AddHead(DList &, int);
DNode* CreateDNode(int);
void PrintDList(DList);
void AddAfter(DList &, int, int);
void AddBefore(DList &, int, int);

int main()
{
    int choice, x, y;
    DList l;
    CreateEmptyDList(l);
    Menu();
    while(1)
    {
        //system("cls");
        cout << "\n\t\tPLEASE SELECT YOUR CHOICE: ";    cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter your positive intergers until you enter -1 to finish: ";
                CreateDList(l);
                break;
            case 2:
                cout << "Your current DList: ";
                PrintDList(l);
                break;
            case 3:
                cout << "Enter a number: ";     cin >> x;
                AddHead(l, x);
                break;
            case 4:
                cout << "Enter a number: ";     cin >> x;
                AddTail(l, x);
                break;
            case 5:
                cout << "Enter two numbers: ";  cin >> x >> y;
                AddAfter(l, x, y);
                break;
            case 6:
                cout << "Enter two numbers: ";  cin >> x >> y;
                AddBefore(l, x, y);
                break;
            case 20:
                cout << "GOOD BYE";
                return 0;
            
        }   
        //system("pause");    
    }
    return 0;
}

void Menu()
{
    cout << "MENU:";
    cout << "\n1. Create a DList";
    cout << "\n2. Print the DList";
    cout << "\n3. Insert a value at the front";
    cout << "\n4. Insert a value at the end";
    cout << "\n5. Insert a value after a given value (only for the first value found)";
    cout << "\n6. Insert a value before a given value (only for the first value found)";
    cout << "\n7. Insert a value after a given value (for all the same values)";
    cout << "\n8. Insert a value before a given value (for all the same values)";
    cout << "\n20. Exit";
}

void CreateEmptyDList(DList &l)
{
    l.pHead = l.pTail = NULL;
}

void CreateDList(DList &l)
{
    int x;
    while(1)
    {
        cin >> x;
        if(x == -1)     break;
        AddTail(l, x);
    }
}

void AddTail(DList &l, int x)
{
    DNode* p = CreateDNode(x);
    if(l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        p->pPrev = l.pTail;
        l.pTail = p;
    }
}

void AddHead(DList &l, int x)
{
    DNode* p = CreateDNode(x);
    if(l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        p->pNext = l.pHead;
        l.pHead->pPrev = p;
        l.pHead = p;
    }
}

DNode* CreateDNode(int x)
{
    DNode* p = new DNode();
    if(p == NULL)   exit(1);
    p->info = x;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}

void PrintDList(DList l)
{
    if(l.pHead == NULL)
        cout << "List is empty";
    else
    {
        while(l.pHead != NULL)
        {
            cout << l.pHead->info << " ";
            l.pHead = l.pHead->pNext;
        }
    }   
}

void AddAfter(DList &l, int x, int y)
{
    DNode* p = l.pHead;
    while(p!=NULL && p->info!=x)
    {
        p=p->pNext;
    }
    if(p == NULL)
        cout << "\nCan't find the value " << x;
    else
    {
        DNode* newDNode = CreateDNode(y);
        if(p->pNext == NULL)
        {
            p->pNext = newDNode;
            newDNode->pPrev = p;
            l.pTail = newDNode; 
        }
        else
        {
            newDNode->pNext = p->pNext;
            newDNode->pPrev = p;
            p->pNext->pPrev = newDNode;
            p->pNext = newDNode;
        }
    }
}

void AddBefore(DList &l, int x, int y)
{
    DNode* p = l.pHead;
    while(p!=NULL && p->info!=x)
    {
        p=p->pNext;
    }
    if(p == NULL)
        cout << "\nCan't find the value " << x;
    else
    {
        DNode* newDNode = CreateDNode(y);
        if(l.pHead == p)
        {
            newDNode->pNext = p;
            p->pPrev = newDNode;
            l.pHead = newDNode;
        }
        else
        {
            newDNode->pNext = p;
            newDNode->pPrev = p->pPrev;
            p->pPrev->pNext = newDNode;
            p->pPrev = newDNode;
        }
    }
}