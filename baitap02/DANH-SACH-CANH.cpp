#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
#define FI "DANH-SACH-CANH.INP"
#define FO "DANH-SACH-CANH.OUT"
ifstream fi;
ofstream fo;
int n, m;
vector<int> bac;
void nhap()
{
    fi.open(FI);
    fi>>n>>m;
    bac.resize(n+1,0);
    for(int i=0;i<m;i++)
    {  int u,v;
       fi>>u>>v;
       bac[u]++;
       bac[v]++;
    }
    fi.close();

}
void xuat()
{
    fo.open(FO);
    fo<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        fo<<bac[i]<<endl;
    }
    fo.close();
}
int main()
{
    nhap();
    xuat();
    return 0;
}