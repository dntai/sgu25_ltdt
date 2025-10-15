#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FI "dijkstra.in1"
#define FO "dijkstra.ou1"
#define pb push_back

#define INF 100000000

int n, m; // so dinh, so canh
int s, t; // tim duong di ngan nhat tu s den t


vector<vector<pair<int,int>>> adjlist;
vector<int> pre;    // pre[s] = u (truoc s la u)
vector<bool> label; // label[s] = true/false (dang xet, chua xet)
vector<int> dist;   // dist[u] = INF / k  

void dijkstra(int s){
    // for v thuoc v: pre[v] = -1
    pre.resize(n+1, -1);
    dist.resize(n+1, INF);
    label.resize(n+1, false);

    // khoi tao
    dist[s] = 0;
    while(true){
        // tim min
        int u = -1;
        for(int v=1; v<=n; v++)
            if(label[v]==false && dist[v] != INF && 
                (u==-1 || dist[v]<dist[u]))
                u = v;
        // tim khong ra
        if(u == -1) break;
        // tim thay
        // + dong dinh
        label[u] = true;
        // + cap nhat ke
        for(auto node: adjlist[u]){
            int v = node.first;
            int w = node.second;
            if(dist[v]>dist[u]+ w){
                dist[v] = dist[u] + w;
                pre[v] = u;
            }
        }
    }
}

void findpath(int t){
    if(label[t] == false)
        cout << -1 << endl;
    else
    {
        vector<int> path;
        while(t != -1)
        {
            path.pb(t);
            t = pre[t];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << " ";
        
        int weight = 0;
        for(int i=1; i<path.size(); i++){
            int u = path[i-1];
            int v = path[i];
            for(auto k: adjlist[u]){
                int vv = k.first;
                int ww = k.second;
                if(vv == v){
                    weight += ww;
                    break;
                }
            }
        }
        cout << weight;
        cout << endl;
        for(auto v: path)
            cout << v << " ";
        cout << endl;
    }
}

void solve(){
    int u, v, w;

    // doc do thi
    // printf("Hello, World!");
    cin >> n >> m >> s >> t;
    printf("n=%d, m=%d, s->t:%d->%d\n", n, m, s, t);

    // doc danh sach canh
    adjlist.resize(n+1);
    for(int i=1; i<=m; i++){
        cin >> u >> v >> w;
        adjlist[u].pb(make_pair(v, w));
    }
    
    dijkstra(s);
    findpath(t);
}

int main(){
    // freopen(FI, "rt", stdin);
    solve();
    return 0;
}