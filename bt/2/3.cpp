#include<iostream>
using namespace std;
void merge(int [], int, int [], int, int []);

int main (){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m;
    int t; cin >> t;
    while (cin >> n >> m || t > 0){ 
        t--;
        int *a = new int [n], *b = new int[m], *c = new int[n+m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

	merge(a, n, b, m, c);
	int nc = n + m;;
        for(int i = 0; i < nc; i++){
            cout << c[i] << " ";
        }
        delete []c;
        cout << endl;
    }
}

void merge(int a[], int n, int b[], int m, int c[])
{
    int i=0, j=0, k=0;
    while(!(i>=n && j>=m))
    {
        if((i<n && j<m && a[i]<b[j]) || j>=m)
        {
            c[k++] = a[i++];
        }
        else
            c[k++] = b[j++];
    }
    // while(i<n && j<m)
    // {
    //     if(a[i] < b[j])     c[k++] = a[i++];
    //     else                c[k++] = b[j++];
    // }
    // while(i<n){
    //     c[k++] = a[i++];
    // }
    // while(j<m){
    //     c[k++] = b[j++];
    // }
}
