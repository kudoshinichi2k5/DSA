#include<iostream>
#include<cmath>
#include<map>
using namespace std;

int main()
{
    int n;  cin >> n;
    map<int, int> m;
    int x;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        //m[x]++;
        if(m.find(x) == m.end())    m[x]=1;
        else                        m[x]++;
    }
    int ans = 0;
    for(map<int, int>::iterator it = m.begin(); it!=m.end(); ++it)
    {
        if(it->first<= it->second)      ans = ans + it->first - it->second;
        else                            ans = ans + it->second;
    }
    cout << ans;
    // for(pair<int, int> i : m)
    // {
    //     cout << m.first << " " << m.second << "\n";
    // }
    return 0;
}