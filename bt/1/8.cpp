#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define Max 100002
using namespace std;

int main()
{
    int t;      cin >> t;
    int n;
    long tmp;
    long b[t];
    for(int i=0; i<t; i++)
    {
        vector<long> a;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> tmp;
            a.push_back(tmp);
        }
        sort(a.begin(), a.end());
        if(n==2)    b[i] = a[1]-a[0];
        else
        b[i] = a[n-1] + a[n-2] - a[0] - a[1];
    }
    for(int i=0; i<t; i++)
        cout << b[i] << endl;
}