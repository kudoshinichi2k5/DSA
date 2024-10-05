#include<iostream>
using namespace std;
#include<cmath>
#define Max 202

void Input(int [], int&);
void Output(int [], int);
void SelectionSort(int [], int);

int main()
{
    int n;
    int a[Max];
    Input(a,n);
    SelectionSort(a,n);
    return 1;
}

void Input(int a[], int &n)
{
    cin >> n;
    for(int i=0; i<n; i++)  cin >> a[i];
}

void Output(int a[], int n)
{
    for(int i=0; i<n; i++)  cout << a[i] << " ";
}

void SelectionSort(int a[], int n)
{
    int minn, i=0, j=0;
    bool flag = 0;
    for(int i=0; i<n-1; i++)
    {
        bool flag = 0;
        minn = i;
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[i])
            {
                minn = j;
                flag = 1;
            }
        }
        swap(a[i], a[minn]);
        if(flag==1){
            Output(a,n);
            cout << endl;
        }     
    }
    
}