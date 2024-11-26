#include<iostream>
#include<string>
#include<vector>
using namespace std;

string s[50001];

void QuickSort(string [], int, int);
int Compare(string, string);
void Freq(string [], int, vector< pair<string, int> > &);
void Merge(vector<pair<string, int>> &, int, int, int);
void MergeSort(vector<pair<string, int>> &, int , int);

int main()
{
    int n;
    cin >> n;
    vector< pair<string, int> > v;
    for(int i=0; i<n; i++)      cin >> s[i];
    QuickSort(s, 0, n-1);
    Freq(s, n, v);
//    for(int i=0; i<v.size(); i++)
//    {
//        cout << v[i].first << " " << v[i].second << '\n';
//    }
    MergeSort(v, 0, v.size()-1);
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << '\n';
    }
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

void Merge(vector<pair<string, int>> &v, int left, int middle, int right)
{
    vector<pair<string, int>> temp;
    int i=left, j=middle+1;
    while(!(i>middle && j>right))
    {
        if((i<=middle && j<=right && v[i].second >= v[j].second) || j>right)
            temp.push_back(v[i++]);
        else
            temp.push_back(v[j++]);
    }
    for(int i=0; i<temp.size(); i++)
        v[left+i] = temp[i];
}

void MergeSort(vector<pair<string, int>> &v, int l, int r)
{
    if(l < r)       // can nhieu hon 1 phan tu
    {
        int m = (l+r)/2;
        MergeSort(v, l, m);     //sap xep ben trai
        MergeSort(v, m+1, r);   //sap xep ben phai
        Merge(v, l, m, r);
    }
}

void Freq(string s[], int n, vector<pair<string, int>> &v)
{
    for(int i=0; i<n; i++)
    {
        int cnt = 1;
        while(i<n-1 && s[i] == s[i+1])
        {
            cnt++;
            i++;
        }
        pair<string, int> temp;
        temp.first = s[i];
        temp.second = cnt;
        v.push_back(temp);
    }
}
