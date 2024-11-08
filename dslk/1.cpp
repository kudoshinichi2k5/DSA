#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;

struct node {
	int info;
	node* pNext;
};
//typedef struct node NODE;

struct List{
	node* pHead;
	node* pTail;
};
//typedef struct List LIST;

//Khởi tạo danh sách liên kết đơn rỗng
void CreateEmptyList(List &l)
{
    l.pHead = l.pTail = NULL;
}

//tạo 1 phần tử mới, hàm trả về địa chỉ của phần tử mới tạo
node* CreateNode(int x)
{
    node* p = new node;
    if(p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

//Thêm phần tử vào danh sách: lưu ý khi thêm có làm cho pHead, pTail thay đổi

//Thêm đầu
void AddHead(List &l, node* p)
{
    if(l.pHead == NULL)
        l.pHead = l.pTail = p;
    else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

//Thêm cuối
void AddTail(List &l, node* p)
{
    if(l.pHead == NULL)
        l.pHead = l.pTail = p;
    else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

//Thêm vào sau 1 node Q
void AddAfterQ(List &l, node* p, node* Q)
{
    if(Q != NULL)
    {
        p->pNext = Q->pNext;
        Q->pNext = p;
        if(l.pTail == Q)
            l.pTail = p;
    }
    else        // danh sách đang rỗng
        AddHead(l, p);
}

//tim phan tu trong dslk don, hàm trả về địa chỉ ptu được tìm thấy, nếu ko trả về NULL
node* SearchNode(List l, int x)
{
    node* p = l.pHead;
    while(p != NULL && p->info != x)
        p = p->pNext;
    return p;
    // for(NODE* p = l.pHead; p!=NULL; p=p->pNext)
    // {
    //     if(p->info == x)    return p;
    // }
    // return NULL;
}

//huy phan tu trong dlsk don: phải cô lập phần tử trước khi hủy
//Hủy ở đầu
bool RemoveHead(List &l, int &x)
{
    node* p;
    if(l.pHead != NULL)
    {
        x = l.pHead->info;      //giữ giá trị sau khi xóa để sd nếu cần
        p = l.pHead;
        l.pHead = l.pHead->pNext;
        if(l.pHead == NULL)
            l.pTail = NULL;
        delete p;
        return 1;   //xoa thanh cong
    }
    return 0;       //list rong ko co phan tu de xoa
}

bool RemoveAfterQ(List &l, int &x, node* Q)
{
    node* p;
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

bool RemoveX(List &l, int &x)
{
    node* Q;
    node* p;
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
void PrintList(List l)
{
    if(l.pHead == NULL)
        cout << "DSLK don rong";
    else{
        node* p;
        cout << "List: ";
        for(p=l.pHead; p!=NULL; p=p->pNext)
        {
            cout << p->info << " ";
        }
    }
}

void RemoveList(List &l)
{
    node* p;
    while(l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = p->pNext;
        delete p;
    }
    l.pTail = NULL;
}



void CreateList(List &l)
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    CreateEmptyList(l);
    int x;
    cout << "Nhap danh sach: ";
    for(int i=0; i<n; i++)
    {
        cin >> x;
        node* p = CreateNode(x);
        AddTail(l,p);
    }
}

void SelectionSort(List &l)
{
    node *p, *q, *min;
    for(p = l.pHead; p!=l.pTail; p=p->pNext)
    {
        min = p;
        for(q = p->pNext; q != NULL; q = q->pNext)
        {
            if(q->info < min->info)     min = q;     
        }
        swap(min->info, p->info);
    }
}

void QuickSort(int a[], int left, int right)
{
    int middle = (left+right)/2;
    int i = left, j = right;
    int key = a[middle];
    while(i <= j)
    {
        while(a[i] < key)  i++;
        while(a[j] > key)  j--;
        if(i<=j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(left < j)    QuickSort(a, left, j);
    if(i < right)   QuickSort(a, i, right); 
}

void QuickSort(List &l)
{
    node *p, *X;
    List l1, l2;
    if(l.pHead == l.pTail)      return;     // da co thu tu roi
    CreateEmptyList(l1);
    CreateEmptyList(l2);
    X = l.pHead;
    l.pHead = X->pNext;
    while(l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = p->pNext;
        p->pNext = NULL;     // tach ra
        if(p->info <= X->info)
            AddHead(l1, p);
        else
            AddHead(l2, p);
        QuickSort(l1);      // sap xep l1
        QuickSort(l2);      // sap xep l2
        // Noi l1, l2, x vao l
        if(l1.pHead != NULL)
        {
            l.pHead = l1.pHead;
            l1.pTail->pNext = X;
        }
        else
            l.pHead = X;
        X->pNext = l2.pHead;
        if(l2.pHead != NULL)
            l.pTail = l2.pTail;
        else
            l.pTail = X;
    }
}

int main() {
    List l;
    CreateList(l);
    QuickSort(l);
    PrintList(l);
    return 0;
}
