#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    vector<vector<int>> a;
    int n, m;
    cin >> n >> m;
    int x;
    for(int i=0; i<n; i++)
    {
        vector<int> tmp;
        for(int j=0; j<m; j++)
        {
            cin >> x;
            tmp.push_back(x);
        }
        a.push_back(tmp);
    }
    int minn = 1e6, s;
    for(int i=0; i<n-2; i++)
    {
        //s=0;
        for(int j=0; j<m-2; j++)
        {
            s = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j] + a[i+1][j+1] + a[i+1][j+2] + a[i+2][j] + a[i+2][j+1] + a[i+2][j+2];
            if(s<minn)  minn = s;
        }  
    }
    cout << minn;
    return 1;
}