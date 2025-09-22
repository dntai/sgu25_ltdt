#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <deque>
using namespace std;

#define FI "LIENTHONGBFS.INP"
#define FO "LIENTHONGBFS.OUT"

int n, x;
vector<set<int>> adjlist;
string s;

vector<int> visited;
vector<int> parent;
deque<int> open;
int cnt;

int bfs(int s)
{
    int u, v, cnt;

    open.clear();
    fill(visited.begin(), visited.end(), 0);
    fill(parent.begin(), parent.end(), -1);

    cnt = 1;
    open.push_back(s);
    visited[s] = 1;
    while(!open.empty()){
        u = open.front(); // queue
        open.pop_front(); 

        for(set<int>::iterator it = adjlist[u].begin(); it != adjlist[u].end(); it++){
            v = *it;
            if(visited[v] == false){
                visited[v] = true;
                parent[v] = u;
                open.push_back(v);
                cnt = cnt + 1;
            }
        }
    }
    return cnt;
}

void solve(){
    // doc do thi danh sach canh
    cin >> n >> x;
    // cout << n << endl;
    adjlist.resize(n + 1);
    cin.ignore();
    for(int u=1; u<=n; u++){
        int v;
        getline(cin, s);
        // cout << s << endl;
        
        stringstream ss(s);
        while(ss >> v){
            // cout << u << " " << v << endl;
            adjlist[u].insert(v);
        }
    }

    // bfs
    visited.resize(n+1);
    parent.resize(n+1);
    cnt = bfs(x);

    cout << cnt - 1 << endl;
    for(int u=1; u<=n; u++){
        if(u!=x && visited[u]==true)
            cout << u << " ";
    }
    cout << endl;

}

int main() {
    freopen(FI, "r", stdin);
    // freopen(FO, "w", stdout);
    solve();
    return 0;
}