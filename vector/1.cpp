#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

void Input(vector<int>, int);
void Output(vector<int>);
int FindIdxEvenFirst(vector<int>);
int FindIdxEvenLast(vector<int>);
int FindEvenMax(vector<int>);

int main()
{
    int n;
    vector<int> v;
    Input(v, n);
    cout << "Mang vua nhap: ";
    Output(v);
    int idx1 = FindIdxEvenFirst(v);
    int idx2 = FindIdxEvenLast(v);
    if(idx1 != -1)
        cout << v[idx1] << " la so chan dau tien, co chi so " << idx1 << " trong mang\n";
    if(idx2 != -1)
        cout << v[idx2] << " la so chan cuoi cung, co chi so " << idx2 << " trong mang\n";
    if(idx1 == -1 && idx2 == -1)
        cout << "Mang khong co so chan";
    else    
        cout << "So chan lon nhat: " << FindEvenMax(v);
    return 0;
}

void Input(vector<int> v, int &n)
{
    cin >> n;
    int tmp;
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
}

void Output(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
        cout << v[i] <<  " ";
}

int FindIdxEvenFirst(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
        if(v[i] % 2 == 0)
            return i;
    return -1;
}

int FindIdxEvenFirst(vector<int> v)
{
    for(int i=v.size()-1; i>=0; i--)
        if(v[i] % 2 == 0)
            return i;
    return -1;
}

int FindEvenMax(vector<int> v)
{
    //int minn = numeric_limits<int>::min();
    int minn = INT_MAX;
    for(int i=0; i<v.end(); i++)
    {
        if(v[i] % 2 == 0 && v[i] < minn)
            minn = v[i];
    }
    return minn;
}
