#include<iostream>
#include<cmath>
using namespace std;

struct Map
{
    long data;
    int key;
};

int BinarySearch(Map m[], int l, int r, int x);
int BinarySearchFirst(Map m[], int l, int r, int x);
int BinarySearchLast(Map m[], int l, int r, int x);
void Merge(Map [], int, int, int);
void MergeSort(Map [], int, int);

int main()
{
    int n, q;  cin >> n >> q;
    Map m[n];

    for(int i=0; i<n; i++)
    { 
        long tmp;
        cin >> tmp;
        m[i].data = tmp;
        m[i].key = i+1;
    }
    MergeSort(m, 0, n-1);
    // for(int i=0; i<n; i++)
    //     cout << m[i].data << " " << m[i].key << '\n';
    int a, b;
    string type;

    for(int i=0; i<q; i++)
    {
        cin >> type >> a >> b;
        if(a == 1)
        {
            cout << BinarySearchFirst(m, 0, n-1, b) << "\n";
        }
        else
        {
            cout << BinarySearchLast(m, 0, n-1, b) << "\n";
        }
    }
    return 0;
}


void Merge(Map a[], int left, int middle, int right)
{
    Map* temp = new Map[right-left+1];
    int m=0;
    int i=left, j=middle+1;
    while(!(i>middle && j>right))
    {
        if((i<=middle && j<=right && a[i].data <= a[j].data) || j>right)
            temp[m++] = a[i++];
        else
            temp[m++] = a[j++];
    }
    for(int i=0; i<m; i++)
        a[left+i] = temp[i];
    delete []temp;
}

void MergeSort(Map a[], int l, int r)
{
    if(l < r)       // can nhieu hon 1 phan tu
    {
        int m = (l+r)/2;
        MergeSort(a, l, m);     //sap xep ben trai
        MergeSort(a, m+1, r);   //sap xep ben phai
        Merge(a, l, m, r);
    }
}


int BinarySearchFirst(Map m[], int l, int r, int x)
{
    while(l<=r)
    {
        int middle = (l+r)/2;
        if(m[middle].data == x)
        {
            while(m[middle].data == x)
            {  middle--;
            }
            return  m[middle+1].key;
        }
        else if(m[middle].data < x)
            l = middle+1;
        else
            r = middle-1;
    }
    return -1;
}

int BinarySearch(Map m[], int l, int r, int x)
{
    while(l<=r)
    {
        int middle = (l+r)/2;
        if(m[middle].data == x)
        {
            return  m[middle].key;
        }
        else if(m[middle].data < x)
            l = middle+1;
        else
            r = middle-1;
    }
    return -1;
}

int BinarySearchLast(Map m[], int l, int r, int x)
{
    while(l<=r)
    {
        int middle = (l+r)/2;
        if(m[middle].data == x)
        {
            while(m[middle].data == x)  middle++;
            return  m[middle-1].key;
        }        else if(m[middle].data < x)
            l = middle+1;
        else
            r = middle-1;
    }
    return -1;
}