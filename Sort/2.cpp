#include <iostream>
using namespace std;

int n;
int a[21];

void OutputArray(int a[], int n, int left, int right)
{
    for(int i=0; i<n; i++){
        if(i==left) cout << "[ ";
        cout << a[i] << " "; 
       if(i==right)    cout << "] ";
    }  
    cout << "\n";
}
// Hàm để gộp hai mảng con đã được sắp xếp
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tạo các mảng tạm thời
    int L[n1], R[n2];

    // Sao chép dữ liệu vào các mảng tạm thời
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Gộp các mảng tạm thời lại
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L[], nếu có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[], nếu có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm chính để sắp xếp mảng sử dụng Merge Sort
void mergeSort(int arr[], int left, int right) 
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Sắp xếp nửa đầu và nửa sau
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Gộp hai nửa đã sắp xếp
    merge(arr, left, mid, right);
    OutputArray(arr, n, left, right);
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)  cin >> a[i];
    mergeSort(a, 0, n-1);
    return 0;
}