#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

void Input(int a[], int &);
void Output(int a[], int);
void BubbleSort(int [], int);
void SelectionSort(int [], int);
void InsertionSort(int [], int);
void Merge(int [], int, int [], int, int []);

int main()
{
    // int a[100], n;
    // Input(a, n);
    // cout << "Mang ban dau: ";
    // Output(a, n);
    // InsertionSort(a, n);
    // cout << "\nMang sau sap xep: ";
    // Output(a, n);
    int n, m;
    cin >> n >> m;
    int a[100], b[100], c[100];
    //int *a = new int [n], *b = new int[m], *c = new int[n+m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

	Merge(a, n, b, m, c);
	int nc = n + m;;
    for(int i = 0; i < nc; i++){
        cout << c[i] << " ";
    }
    //delete c;
    return 1;
}

void Input(int a[], int &n)
{
    srand(time(NULL));
    n = rand() % 10 + 5;
    for(int i=0; i<n; i++)
        a[i] = rand() % 20 + -10; 
}

void Output(int a[], int n)
{
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
}

void BubbleSort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[i])   swap(a[i], a[j]);
        }
    }
}

void SelectionSort(int a[], int n)
{
    int min;
    for(int i=0; i<n-1; i++)
    {
        min=i;
        for(int j=i+1; j<n; j++)
            if(a[i]>a[j])   min=j;
        swap(a[i], a[min]);
    }
}

void InsertionSort(int a[], int n)
{
    int i, temp, j;
    for(i=1; i<n; i++)
    {
        temp = a[i];
        j = i - 1;
        while(temp<a[j] && j>=0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

void Merge(int a[], int n, int b[], int m, int c[])
{
    int i=0, j=0, k=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])   c[k++] = a[i++];
        else            c[k++] = b[j++];
    }
    while(i<n)
    {
        c[k++] = a[i++];
    }
    while(j<m)
    {
        c[k++] = b[j++];
    }
}
