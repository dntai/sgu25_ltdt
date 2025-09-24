#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

#define FI "MIENLIENTHONG.INP"
#define FO "MIENLIENTHONG.OUT"

int n, m;
vector<set<int>> adjlist;
vector<bool> visited;
deque<int> open;
vector<int> parent;
vector<int> components;

int BFS(int s, int d){
    int cnt = 0;

    open.clear();

    // init
    open.push_back(s);
    visited[s] = true;
    components[s] = d;
    while (!open.empty()) {
        cnt = cnt + 1;
        int u = open.front();
        open.pop_front();
        for(set<int>::iterator it = adjlist[u].begin(); 
            it != adjlist[u].end(); it++){
            int v = *it;
            if(visited[v] == false){
                visited[v] = true;
                parent[v] = u;
                components[v] = d;
                open.push_back(v);
            }
        }
    }
    return cnt;
}

void solve(){
    int u, v;

    // doc do thi tu danh sach ke
    cin >> n >> m;
    cin.ignore(1000, '\n');
    // printf("n = %d, m = %d\n", n, m);
    
    adjlist.resize(n + 1);
    for(int i=0; i<m; i++)
    {
        cin >> u >> v;
        // cout << u << " " << v << endl;
        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }

    open.resize(n + 1);
    visited.resize(n + 1);
    parent.resize(n + 1);
    components.resize(n + 1);

    // khoi tao
    fill(visited.begin(), visited.end(), false);
    fill(parent.begin(), parent.end(), -1);
    fill(components.begin(), components.end(), -1);
    
    int d = 0;
    for(int u=1; u<=n; u++){
        if(visited[u] == false){
            BFS(u, d);
            d = d + 1;
        }
    }

    cout << d << endl;
    for(int i=0; i<d; i++){
        for(int u=1; u<=n; u++){
            if(components[u]==i){
                cout << u << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    freopen(FI, "rt", stdin);
    // freopen(FO, "wt", stdout);
    solve();
    return 0;
}