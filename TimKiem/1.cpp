#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
#define Max 100

//return -1: ko tim thay
void Input(int [], int &);
void Output(int [], int);
int LinearSearch(int [], int, int);
int LinearSearchA(int [], int, int);
int BinarySearch(int [], int, int);     //phai sap xep

int main()
{
    int a[Max];
    int n;
    Input(a, n);
    Output(a, n);
    int x;
    cout << "Nhap x: ";      cin >> x;
    if(BinarySearch(a, n, x) == -1)     cout << "Ko tim thay";
    else                                cout << "Tim thay";
    return 1;
}

void Input(int a[], int &n)
{
    srand(time(0));
    cout << "Nhap so luong: ";    cin >> n;
    //cout << "Nhap mang: ";
    for(int i = 0; i<n; i++)    a[i] = rand() % 100 + 1;
}

void Output(int a[], int n)
{
    cout << "Mang da nhap la: ";
    for(int i=0; i<n; i++)      cout << a[i] << " ";
    cout << "\n";
}

int LinearSearch(int a[], int n, int x)
{
    for(int i=0; i<n; i++)
        if(a[i] == x)   return i;
    return -1;
}

int LinearSearchA(int a[], int n, int x)
{
    int i = 0;
    a[n] = x;
    while(a[i] != x)
    {
        i++;
    }
    if(i!=n)    return i;
    else        return -1;
}

int BinarySearch(int a[], int n, int x)
{
    sort(a, a+n);
    int left = 0, right = n - 1, middle;
    while(left <= right)
    {
        middle = (left + right) / 2;
        if(a[middle] == x)      return middle;
        else if(a[middle] > x)
        {
            right = middle - 1;
        }
        else
            left = middle + 1;
    }
    return -1;
}

int BinarySearch(int a[], int n, int x)
{
    int left = 0, right = n-1, middle;
    while(left <= right)
    {
        middle = (left+right)/2;
        if(a[middle] == x)  return middle;
        else if(a[middle] > x)      right = middle - 1;
        else                        left = middle + 1;
    }
}