#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
#define FI "BAC-VAO-BAC-RA.INP"
#define FO "BAC-VAO-BAC-RA.OUT"
ifstream fi;
ofstream fo;
int n;
vector<vector<int>> a;
vector<int> bacvao;
vector<int> bacra;
void nhap ()
{   fi.open(FI);
    fi>>n; // nhap so dinh
    if(n>1000)
    {
        cerr<<"vuot qua gioi han dinh cho phep"<<endl;
        exit(1);
    }
    a.resize(n);
    bacvao.resize(n);
    bacra.resize(n);
    for(int i=0;i<n;i++)
    {
        a[i].resize(n);
        for(int j=0;j<n;j++)
        {
            fi>>a[i][j];
        }
    }
    fi.close();
}
void xuat()
{
    fo.open(FO);
    fo<<n<<endl;
    for(int i=0;i<n;i++)
    {
        int bacvaoj=0,bacrai=0;
        for(int j=0;j<n;j++)
        {
            bacvaoj=bacvaoj+a[j][i];
            bacrai=bacrai+a[i][j];
        }
        bacvao[i]=bacvaoj;
        bacra[i]=bacrai;
    }
    for(int i=0;i<n;i++)
    {
         fo<<bacvao[i]<<" "<<bacra[i]<<endl;
         
    }
    fo.close();
}
int main()
{
    nhap();
    xuat();
    return 0;
}