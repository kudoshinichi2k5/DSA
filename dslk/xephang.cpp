#include<iostream>
using namespace std;
#define MAX 100001
int main()
{
    int n, m;
    cin >> n >> m;
    int a[MAX];
    bool b[MAX] ={0};
    for(int i=1; i<=m; i++)
    {
        cin >> a[i];
        b[a[i]] = 1;
    }  
    for(int i=m; i>0; i--)   cout << a[i] << " ";
    for(int i=1; i<=n; i++)
    {
        if(!b[i])   cout << i << " ";
    }
    return 0;
}