#include<iostream>
#include<cmath>
using namespace std;
#define Max 100002
#include<algorithm>

struct point
{
    long x, y, z;
};

void Swap(point&, point&);
bool cmp(point, point);

int main()
{
    int n;
    cin >> n;
    point a[100002];
    for(int i=0; i<n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    sort(a, a+n, cmp);
    for(int i=0; i<n; i++)
    {
        cout << a[i].x << " " << a[i].y << " " << a[i].z;
        cout << endl;
    }
    return 1;
}

void Swap(point &a, point &b)
{
    point tmp = a;
    a = b;
    b = tmp;
}

bool cmp(point a, point b)
{
    if(a.x < b.x)             return 1;
    else if(a.x == b.x)
    {
        if(a.y > b.y)         return 1;
        else if(a.y == b.y)
        {
            if(a.z < b.z)     return 1;
        }
    }
    return 0;
}