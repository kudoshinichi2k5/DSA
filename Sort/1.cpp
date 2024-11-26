#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

void Input(int [], int);
void Output(int [], int);
void BubbleSort(int [], int);
void BubbleSort1(int [], int);
void SelectionSort(int [], int);
void InsertionSort(int [], int);
void Tron(int [], int, int [], int, int []);
void Merge(int [], int, int, int);
void QuickSort(int [], int, int);
void MergeSort(int [], int, int);

int main()
{
    srand(time(0));
    int n;       cin >> n;
    int *a = new int[n];
    //int *c = new int[n+m];
    Input(a, n);
    //Input(b, m);
    MergeSort(a, 0, n-1);
    Output(a, n);
    delete []a;
    return 0;
}

void Input(int a[], int n)
{
    for(int i=0; i<n; i++)
        a[i] = rand() % 20 + -10; 
}

void Output(int a[], int n)
{
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
}

void BubbleSort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=n-1; j>i; j--)
        {
            if(a[j]<a[i])   swap(a[i], a[j]);
        }
    }
}

//Biến thể của bubblesort
void BubbleSort1(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[i])   swap(a[i], a[j]);
        }
    }
}

void SelectionSort(int a[], int n)
{
    int min;
    for(int i=0; i<n-1; i++)
    {
        min=i;
        for(int j=i+1; j<n; j++)
            if(a[min]>a[j])   min=j;
        swap(a[i], a[min]);
    }
}

void InsertionSort(int a[], int n)
{
    int i, temp, j;
    for(i=1; i<n; i++)
    {
        temp = a[i];
        j = i - 1;
        while(temp<a[j] && j>=0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

void Tron(int a[], int n, int b[], int m, int c[], int &p)
{
   int i=0, j=0;
   p = 0;
   while(!(i>=n && j>=m))
   {
        if( (i<n && j<m && a[i] < b[j]) || j>=m )
            c[p++] = a[i++];
        else
            c[p++] = b[j++];
   }
}

void Merge(int a[], int left, int middle, int right)
{
    int* temp = new int[right-left+1];
    int m=0;
    int i=left, j=middle+1;
    while(!(i>middle && j>right))
    {
        if((i<=middle && j<=right && a[i] < a[j]) || j>right)
            temp[m++] = a[i++];
        else
            temp[m++] = a[j++];
    }
    for(int i=0; i<m; i++)
        a[left+i] = temp[i];
    delete []temp;
}

void MergeSort(int a[], int l, int r)
{
    if(l < r)       // can nhieu hon 1 phan tu
    {
        int m = (l+r)/2;
        MergeSort(a, l, m);     //sap xep ben trai
        MergeSort(a, m+1, r);   //sap xep ben phai
        Merge(a, l, m, r);
    }
}

void QuickSort(int a[], int left, int right)
{
    int middle = (left + right)/2;
    int key = a[middle];
    int i=left, j=right;
    while(i<=j)
    {
        while(a[i] < key)   i++;
        while(a[j] > key)   j--;
        if(i<=j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(left < j)   QuickSort(a, left, j);
    if(right > i)  QuickSort(a, i, right);
}