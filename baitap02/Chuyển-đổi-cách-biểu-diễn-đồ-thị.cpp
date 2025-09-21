#include <iostream>
#include <vector>
using namespace std;

// 1. Ma trận kề -> Danh sách kề
vector<vector<int>> mat_to_adj(const vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j]) {
                adj[i].push_back(j);
            }
        }
    }
    return adj;
}

// 2. Ma trận kề -> Danh sách cạnh
vector<pair<int,int>> mat_to_edges(const vector<vector<int>>& mat) {
    int n = mat.size();
    vector<pair<int,int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (mat[i][j]) {
                edges.push_back({i, j});
            }
        }
    }
    return edges;
}

// 3. Danh sách kề -> Ma trận kề
vector<vector<int>> adj_to_mat(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int v : adj[i]) {
            mat[i][v] = 1;
        }
    }
    return mat;
}

// 4. Danh sách kề -> Danh sách cạnh
vector<pair<int,int>> adj_to_edges(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<pair<int,int>> edges;
    for (int i = 0; i < n; i++) {
        for (int v : adj[i]) {
            if (v > i) edges.push_back({i, v});
        }
    }
    return edges;
}

// 5. Danh sách cạnh -> Ma trận kề
vector<vector<int>> edges_to_mat(const vector<pair<int,int>>& edges, int n) {
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (auto e : edges) {
        int u = e.first, v = e.second;
        mat[u][v] = mat[v][u] = 1;
    }
    return mat;
}

// 6. Danh sách cạnh -> Danh sách kề
vector<vector<int>> edges_to_adj(const vector<pair<int,int>>& edges, int n) {
    vector<vector<int>> adj(n);
    for (auto e : edges) {
        int u = e.first, v = e.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}