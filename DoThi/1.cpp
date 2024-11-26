#include<iostream>
using namespace std;

void InputGraph(bool*[], int);
void Process(bool*[], int, int);

int main()
{
    int v, e, n;    //v: so dinh, e:so canh, n:so thao tac
    cin >> v >> e >> n;
    bool **G;   //ma tran toan so 0, 1 nen kieu bool hay int deu duoc
    //B1: cap phat vung nho cho ma tran ke va khoi tao ma tran toan 0
    G = new bool*[v];
    for(int i=0; i<=v; i++)
    {
        G[i] = new bool[v+1]{0};
    }
    //B2: nhap danh sach canh va luu thong tin canh vao ma tran
    int x, y;   
    for(int i=0; i<e; i++)
    {
        cin >> x >> y;
        G[x][y] = 1;
    }
    //B3: xuat ma tran de kiem tra xxem viec nhap co thanh cong khong
    // for(int i=1; i<=v; i++)
    // {
    //     for(int j=1; j<=v; j++)
    //         cout << G[i][j] << " ";
    //     cout << endl;
    // }
    int k;
    for(int i=1; i<=n; i++)
    {
    	cin >> k;
    	if(k==1)
    	{
    		cin >> x >> y;
    		if(G[x][y] == 1)
    			cout << "TRUE";
    		else
    			cout << "FALSE";
    		cout << endl;
    	}
    	else
    	{
    		cin >> x;
    		for(int i=1; i<=v; i++)
    			if(G[x][i] == 1)
    				cout << i << ' ';
    		cout << '\n';
    	}
    }
    return 0;

}