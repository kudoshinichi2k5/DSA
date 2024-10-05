#include<iostream>
#include<cmath>
#define Max 32002
using namespace std;

int BinarySearch(int [], int, int, int&);

int main()
{
    int cnt = 0;
    int n, x;      cin >> n;
    int a[Max];
    for(int i=0; i<n; i++)      cin >> a[i];
    cin >> x;
    int idx = BinarySearch(a, n, x, cnt);
    cout << idx << endl;
    if(idx != -1)
    {
        cout << cnt;
    }
    return 1;
}

int BinarySearch(int a[], int n, int x, int &cnt)
{
    int l = 0, r = n - 1, m = 0;
    while(l<=r)
    {
        cnt++;
        m = (l+r)/2;
        if(a[m] == x)   return m;
        else if(a[m]<x)
        {
            l = m + 1;
        }
        else   
            r = m - 1;
    }
    return -1;
}