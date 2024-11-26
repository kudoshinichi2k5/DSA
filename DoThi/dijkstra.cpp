#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Graph {
    vector<string> names;  // Danh sách tên các đỉnh
    map<string, int> nameToIndex;  // Mảng ánh xạ tên đỉnh sang chỉ số
    vector<vector<int>> maTrix;  // Ma trận kề của đồ thị

public:
    // Hàm nhập dữ liệu cho đồ thị
    void nhap(int v) {
        names.resize(v);
        maTrix.resize(v, vector<int>(v, 0));  // Khởi tạo ma trận kề với các phần tử là 0
        for (int i = 0; i < v; i++) {  // Nhập các tên đỉnh
            cin >> names[i];
            nameToIndex[names[i]] = i;
        }
        for (int i = 0; i < v; i++) {  // Nhập các cạnh
            for (int j = 0; j < v; j++) {
                cin >> maTrix[i][j];
            }
        }
    }
}

//truyen vo index cua dinh
void Dijkstra(int s, int g, int v)
{
    //c1:
    //set<pair<string, int>> open;
    //VD: open={(A, 20), (B, 35)};
    //c2:
    //priority_queue<pair<string, int>, vector<pair<string, int>>> open;
    //vector<bool> close(v,0);
    //map<string, string>parent;
    //vector<int> d(v,0);
}

int main()
{
    Graph G;
    int v, n;
    cin >> v >> n;
    G.inputGraph(v);
    G.outputGraph(v);
    string x, y;
    for(int i=0; i<n; i++)
    {
        cin >> x >> y;      //tim duong di tu x toi y
        G.Dijkstra(x,y);
        //G.Dijkstra(toindex[x], toindex[y]);
    }
}