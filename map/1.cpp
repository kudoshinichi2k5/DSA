#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if(a.second > b.second)     return a;
    else
        return a.first < b.first;
}

int main()
{
    int n;      cin >> n;
    map<int, int, comp> m;
    int x;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        m[x]++;
    }
    //sort(m.begin, m.end, comp);
    for(pair<int, int> x : m)
    {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}