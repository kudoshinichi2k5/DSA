#include<iostream>
using namespace std;
#include<algorithm>

bool comp(long a, long b)
{
    return a<b;
}

int partition(long arr[], int start, int end) {
    long pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(long arr[], int start, int end) {
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int main()
{
    int n;
    cin >> n;
    long a[n];
    for(int i=0; i<n; i++)  cin >> a[i];
    quickSort(a, 0, n-1);
    bool flag = 0;
    for(int i=0; i<n; i++)
    {
        if(i<a[i])
        {
            flag=1;
            cout << i;
            break;
        }
    }
    if(flag==0)     cout << n;
    return 0;
}