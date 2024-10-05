#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAX 100000
#define ll long long
bool BinarySearch(ll [], int, ll);
bool comp(ll, ll);

int main()
{
    int n, q;
    cin >> n >> q;
    ll a[MAX];
    ll b[MAX];
    for(int i=0; i<n; i++)      cin >> a[i];
    for(int i=0; i<q; i++)      cin >> b[i];
    sort(a, a+n, comp);
    for(int i=0; i<q; i++)
    {
        if(BinarySearch(a, n, b[i]) == true)    cout << "YES\n";
        else                                    cout << "NO\n";
    }
    return 1;
}

bool BinarySearch(ll a[], int n, ll x)
{
    int l=0, r=n-1, m;
    while(l<=r)
    {
        m=(l+r)/2;
        if(a[m] == x)   return true;
        else if(a[m] < x)
        {
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return false;
}

bool comp(ll a, ll b)
{
    return a < b;
}