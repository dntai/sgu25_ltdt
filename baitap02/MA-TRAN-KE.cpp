#include<iostream>
#include<vector>
#include<fstream>
#define FI "MA-TRAN-KE.INP"
#define FO " MA-TRAN-KE.OUT"
using namespace std;
int n;
vector<vector<int>> a;
vector<int>bac;
void nhap()
{
    cin>>n;
     if(n>1000)
    {
        cerr<<"vuot qua gioi han dinh cho phep"<<endl;
        exit(1);
    }
    a.resize(n);
    for(int i=0;i<n;i++)
    {
        a[i].resize(n);
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    bac.resize(n);
    for(int i=0;i<n;i++)
    {
        int baci=0; // tinh bac cua dinh thu i
        for(int j=0;j<n;j++)
        {
            baci=baci+a[i][j];
        }
        bac[i]=baci;
    }

}
void xuat()
{
    cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<bac[i]<<endl;
    }
}
int main()
{
    freopen(FI,"r",stdin);
    freopen(FO,"w",stdout);
    nhap();
    xuat();
    return 0;
}