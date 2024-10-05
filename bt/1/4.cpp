#include<iostream>
#include<cmath>
#define Max 10002
using namespace std;

void LinearSearchA(int [], int, int, int&, int []);

int main()
{
    int n;
    cin >> n;
    int a[Max], b[Max];
    for(int i=0; i<n; i++)  cin >> a[i];
    int x;      cin >> x;
    int cnt=0;
    LinearSearchA(a,n,x,cnt,b);
    if(cnt==0)  cout << 0;
    else
    {
        cout << cnt << endl;
        for(int i=0; i<cnt; i++)
            cout << b[i] << " " << b[i]+1 << endl;
    }
    return 1;
}

void LinearSearchA(int a[], int n, int x, int &cnt, int b[])
{
    int i;
    for(i=0; i<n; i++)
    {
        if(a[i]==x)
        {
            b[cnt++] = i;
        }
    }
}