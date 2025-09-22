#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <deque>
using namespace std;

#define FI "LIENTHONGDFS.INP"
#define FO "LIENTHONGDFS.OUT"

int n, x;
vector<set<int>> adjlist;
string s;

vector<int> visited;
vector<int> parent;
vector<pair<int,int>> times;
deque<int> open;
int cnt;

void try_dfs(int u, int &cnt, int &time) {
    int v;
    visited[u] = true;
    cnt = cnt + 1;
    time = time + 1;
    times[u] = make_pair(time, -1);
    for(set<int>::iterator it = adjlist[u].begin(); it != adjlist[u].end(); it++){
        v = *it;
        if(visited[v] == false){
            parent[v] = u;
            try_dfs(v, cnt, time);
        }
    }
    time = time + 1;
    times[u].second = time;
}

int dfs1(int s)
{
    int time;

    fill(visited.begin(), visited.end(), 0);
    fill(parent.begin(), parent.end(), -1);

    cnt = 0; time = 0;
    try_dfs(s, cnt, time);

    return cnt;
}

int dfs(int s)
{
    int u, v, cnt;

    open.clear();
    fill(visited.begin(), visited.end(), 0);
    fill(parent.begin(), parent.end(), -1);

    cnt = 0;
    open.push_back(s);
    while(!open.empty()){
        u = open.back(); // stack
        open.pop_back(); 
        visited[u] = true;
        cnt = cnt + 1;
        for(set<int>::iterator it = adjlist[u].begin(); it != adjlist[u].end(); it++){
            v = *it;
            if(visited[v] == false){
                parent[v] = u;
                open.push_back(v);
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
    times.resize(n+1);
    
    cnt = dfs1(x);

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