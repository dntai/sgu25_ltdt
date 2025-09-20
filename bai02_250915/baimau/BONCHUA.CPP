#include <iostream>
#include <vector>
using namespace std;

#define FI "BONCHUA.INP"

int n;
vector<vector<int>> a;
vector<int> deg;
vector<int> ans;

void solve(){
    // Nhap ma tran ke
    cin >> n;
    a.resize(n);
    for(int i=0; i<n; i++){
        a[i].resize(n);
        for(int j=0;j<n; j++){
            cin >> a[i][j];
        }
    }

    // tinh bac vao (tong dong)
    deg.resize(n);
    for(int i=0; i<n; i++){
        int degi = 0;   
        for(int j=0;j<n; j++){
            degi = degi + a[i][j];
        }
        deg[i] = degi;
    }

    // tim dinh bac 0
    for(int i=0; i<n; i++){
        if(deg[i] == 0)
            ans.push_back(i);
    }

    // in ket qua
    cout << ans.size() << endl;
    for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++){
        cout << *it + 1 << " ";
    }
    cout << endl;
}

int main() {
    // freopen(FI, "r", stdin);
    solve();
    return 0;
}