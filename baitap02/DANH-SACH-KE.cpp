#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
#define FI "DANH-SACH-KE.INP"
#define FO "DANH-SACH-KE.OUT"
ifstream fi;
ofstream fo;
int n;
vector<int>  danhsachke;
void nhap()
{
    fi.open(FI);
    fi>>n;// nhap so dinh
    if(n>1000000)
    {
        cerr<<"vuot qua gioi han dinh cho phep"<<endl;
        exit(1);
    }
    danhsachke.resize(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int x;
        while(fi>>x)
        {
            if(x==-1)
            {
                break;
            }
            if(x==i)
            {
                continue;
            }
            danhsachke[i]++;
        }
    }
    fi.close();
}
void xuat()
{
    fo.open(FO);
    fo<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        fo<<danhsachke[i]<<endl;
    }
    fo.close();
}
int main()
{
    nhap();
    xuat();
    return 0;
}