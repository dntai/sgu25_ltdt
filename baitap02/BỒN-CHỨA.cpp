#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
#define FI "BỒN-CHỨA.INP"
#define FO "BỒN-CHỨA.OUT"
ifstream fi;
ofstream fo;
int n;
vector<vector<int>> danhsachke;
vector<int> bacvao;
vector<int> bacra;
void nhap()
{
    fi.open(FI);
    fi>>n;
    danhsachke.resize(n);
     bacvao.resize(n,0);
    bacra.resize(n,0);
    for(int i=0;i<n;i++)
    {
        danhsachke[i].resize(n);
        for(int j=0;j<n;j++)
        {
            fi>>danhsachke[i][j];
        }
    }
    fi.close();
}
void xuat()
{
    fo.open(FO);
    for(int i=0;i<n;i++)
    {
         int bacvaoj=0,bacrai=0;
         for(int j=0;j<n;j++)
         {
           bacvaoj=bacvaoj+danhsachke[j][i];
           bacrai=bacrai+danhsachke[i][j];
         }
         bacvao[i]=bacvaoj;
         bacra[i]=bacrai;
    }
    int dem=0;
    for(int i=0;i<n;i++)
    {
        if(bacvao[i]>0&&bacra[i]==0)
        dem++;
    }
   
    fo<<dem<<endl;
    
    if(dem>0)
    {
     for(int i=0;i<n;i++)
     {
        if(bacvao[i]>0&&bacra[i]==0)
        fo<<i+1<<" ";
     }
     fo<<endl;
    }
   fo.close();
}
int main()
{
    nhap();
    xuat();
    return 0;
}
