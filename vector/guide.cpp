#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Input(vector<int> &);
void Output(vector<int>);
void Top5(vector<int>);
int FindK(vector<int>, int);

int main()
{
    vector<int> v;
    int k;
    Input(v);
    cout << "Danh sach da nhap: ";
    Output(v);
    cout << "\nGia tri can tim k = ";       cin >> k;
    cout << FindK(v, k);      // xuat ra vi tri
    // Xuat ra gia tri
    // vector<int>::iterator i;
    // i = find(v.begin(), v.end(), k);
    // cout << *i;
    cout << "\nTop 5: ";
    Top5(v);
    return 0;
}

void Input(vector<int> &v)
{
    int tmp;
    cout << "Nhap danh sach: ";     cin >> tmp;
    while(tmp > 0)
    {
        v.push_back(tmp);
        cin >> tmp;
    }
}

void Output(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
}

int FindK(vector<int> v, int k)
{
    int i=0;
    while(i<v.size() && v[i] != k)
        i++;
    if(i == v.size())       return -1;
    else                    return  i;
}

void Top5(vector<int> v)
{
    if(v.size() < 5)
    {
        cout << "Danh sach ko co du 5 phan tu";
        return;
    }
    sort(v.begin(), v.end());   // sap xep tang dan
    //sort(v.begin(), v.end(), greater<int>());       // sap xep giam dan
    for(vector<int>::iterator i = v.end()-1; i>v.end()-6; i--)
    {
        cout << *i << " ";
    }
}