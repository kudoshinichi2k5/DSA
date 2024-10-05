#include <iostream>
#include <string>

#define LOAD 0.7
#define EMPTY 0
#define DELETE -1
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh* table;
};

void CreateHashtable(Hashtable &, int);
int Delete(Hashtable &, int, int &);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);
void Insert(Hashtable &, Hocsinh);
int Search(Hashtable &, int, int &);

void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}
int main()
{
    Hashtable hashtable;

    int m, n, k, nprob;
    Hocsinh hs;

    cin >> m;       //kich thuoc bang bam
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++) {
        Input(hs);
        hashtable.table[i] = hs;
        if (hs.Maso > 0)
            hashtable.n++;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (Delete(hashtable, k, nprob)) {
            cout << "THAM DO " << nprob << endl;
        }
        else {
            cout << "KHONG XOA DUOC" << endl;
        }
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}

void CreateHashtable(Hashtable &ht, int m) {
    ht.table = new Hocsinh[m];
    if (ht.table == NULL)
        exit(1);
    for (int i = 0; i < m; i++) {
        ht.table[i].Maso = EMPTY;
    }
    ht.M = m;
    ht.n = 0;
}

void PrintHashtable(Hashtable ht) {
    for (int i = 0; i < ht.M; i ++) {
        Hocsinh hs = ht.table[i];
        if (hs.Maso > 0)
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "]\n";
        else
            cout << "[" << hs.Maso <<  ",  " << "  , " << ", " << ", " << "]\n";
    }
}

void DeleteHashtable(Hashtable &ht) {
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int Delete(Hashtable &ht, int maso, int &nprob) {
    nprob = 0;
    int i, h_key;
    for(i=0; i<ht.M; i++)
    {
        h_key = ((x.maso % ht.M) + i*i) % ht.M;
        if(ht.table[h_key].Maso == maso){
            ht.table[h_key].Maso = DELETE;
            ht.n--;
            return 1;
        }     
        nprob++;
    }
    return -1;
}

void Insert(Hashtable &ht, Hocsinh x)
{
    if((ht.n+1)*1.0/ht.M >= LOAD)   return 0;
    for(int i=0; i<ht.M; i++)
    {
        int h_key = ((x.Maso % ht.M) + i) % ht.M;
        if(ht.table[h_key].Maso == EMPTY || ht.table[h_key].Maso == DELETE){
            ht.table[h_key].Maso = x;
            ht.n++;
            return 1;
        }
    }
    return 0;
}

int Search(Hashtable ht, int maso, int &nprob)
{
    nprob = 0;
    int i, h_key;
    for(i=0; i<ht.M; i++)
    {
        h_key = ((x.maso % ht.M) + i*i) % ht.M;
        nprob++;
        if(ht.table[h_key].Maso == maso)     return 1;
    }
    return -1;
}