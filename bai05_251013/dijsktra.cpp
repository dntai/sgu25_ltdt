#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; // so dinh, canh
int s, t; // tim duong tu s toi t

const int INF = 1000000000;

vector<vector<pair<int,int>>> adjlist;
vector<int> dist; // dist[u]: duong di ngan nhat tu s -> u
vector<bool> label; // label[u] = true/false
vector<int> pre;

void dijsktra(int s){
    // khoi tao
    dist.resize(n+1, INF);
    label.resize(n+1, false);
    pre.resize(n+1, -1);

    dist[s] = 0;
    for(int i=0; i<n; i++){
        // tim u chua xet, co gia tri nho nhat
        int u = -1;
        for(int v=1; v<=n; v++){
            if(label[v]==false){
                if(u==-1) {
                    u = v;
                } else if(dist[u]>dist[v]){
                    u = v;
                }
            }
        }
        // cap nhat xung quanh dinh dang xet
        if(u==-1) break;
        // gan u da xet
        label[u] = true;
        // cap nhat dinh v ke u chua xet, ko toi uu
        for(auto v: adjlist[u]){
            int vv = v.first;
            int ww = v.second;
            if(label[vv]==false && 
                dist[vv]>dist[u] + ww){
                    dist[vv] = dist[u] + ww;
                    pre[vv] = u;
                }
        }
    }
}

vector<int> FindPath(int t){
    vector<int> path;
    while(t!=-1){
        path.push_back(t);
        t = pre[t];
    }
    reverse(path.begin(), path.end());
    return path;
}

void solve(){
    int u, v, w;

    // doc do thi
    cin >> n >> m >> s >> t;
    // printf("n=%d, m=%d, s=%d, t=%d\n", n, m, s, t);

    adjlist.resize(n+1);
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        adjlist[u].push_back(make_pair(v, w));
    }

    // chay tim duong
    dijsktra(s);

    // truy hoi
    if(pre[t]==-1)
        cout << -1 << endl;
    else{
        vector<int> path = FindPath(t);
        int weight = 0;
        for(int i=1; i<path.size(); i++){
            int u = path[i-1];
            int v = path[i];
            for(int j=0; j<adjlist[u].size(); j++){
                if(adjlist[u][j].first == v){
                    weight += adjlist[u][j].second;
                }
            }
        }
        cout << path.size() << " " << weight << endl;
        for(auto x : path)
            cout << x << " ";
        cout << endl;
    }
    
}

int main(){
    // freopen("dijsktra.in1", "rt", stdin);
    solve();
    return 0;
}