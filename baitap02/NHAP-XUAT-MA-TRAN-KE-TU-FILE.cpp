#include<iostream>
#include<vector>
#include<fstream>
#define FI "NHAP-XUAT-MA-TRAN-KE-TU-FILE.INP"
#define FO "NHAP-XUAT-MA-TRAN-KE-TU-FILE.OUT"
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
    

}
bool hopLe() {
    for (int i = 0; i < n; i++) {
        if (a[i][i] != 0) return false; // không được có cạnh khuyên
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0 && a[i][j] != 1) return false; // chỉ cho phép 0 hoặc 1
        }
    }
    return true;
}

bool voHuong() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) return false;
        }
    }
    return true;
}
void xuat()
{
    cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
        cout<<a[i][j]<<" ";
       }
       cout<<endl;
    }
    if (!hopLe()) {
        cout << "Do thi khong hop le" << endl;
        return;
    }

    if (voHuong())
        cout << "Do thi VO HUONG" << endl;
    else
        cout << "Do thi CO HUONG" << endl;
}

int main()
{
    freopen(FI,"r",stdin);
    freopen(FO,"w",stdout);
    nhap();
    xuat();
    return 0;
}