#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
using namespace std;

#define FI "DANHSACHKE.INP"
#define FO "DANHSACHKE.OUT"

int n;
string s;

vector<set<int>> adjlist;

void solve(){
    // doc do thi danh sach canh
    cin >> n;
    // cout << n << endl;
    adjlist.resize(n);
    cin.ignore();
    for(int u=0; u<n; u++){
        int v;
        getline(cin, s);
        // cout << s << endl;
        
        stringstream ss(s);
        while(ss >> v){
            // cout << u << " " << v << endl;
            adjlist[u].insert(v);
        }
    }

    // in bac dinh
    cout << adjlist.size() << endl;
    for(int u=0; u<adjlist.size(); u++)
    {
        cout << adjlist[u].size() << endl;
    }
}

int main(){
    // freopen(FI, "r", stdin);
    solve();
    return 0;
}