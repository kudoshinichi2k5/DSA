#include<iostream>
#include<string>
using namespace std;

string s[50001];

void QuickSort(string [], int, int);
int Count(string [], int);
int Compare(string, string);

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)      cin >> s[i];
    QuickSort(s, 0, n-1);
    if(n == 0)  cout << 0;
    else        cout << Count(s, n);
    return 0;
}

int Compare(string a, string b)
{
    if(a.length() > b.length())         return 1;
    else if(a.length() < b.length())    return -1;
    else
    {
        if(a > b)       return 1;
        else if(a < b)  return -1;
        return 0;
    }
}

void QuickSort(string s[], int l, int r)
{
    int i = l, j = r;
    int m = (l+r)/2;
    string key = s[m];
    while(i<=j)
    {
        while(Compare(s[i], key) == -1)     i++;
        while(Compare(s[j], key) == 1)      j--;
        if(i <= j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    if(l<j)     QuickSort(s, l, j);
    if(i<r)     QuickSort(s, i, r);
}

int Count(string s[], int n)
{
    int cnt=1;
    for(int i=0; i<n-1; i++)
    {
        if(s[i] != s[i+1])  cnt++;
    }
    return cnt;
}