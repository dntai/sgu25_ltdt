#include <iostream> // Thư viện nhập xuất cơ bản
#include <vector>   // Thư viện sử dụng vector
#include <queue>    // Thư viện sử dụng queue
#include <algorithm>// Thư viện thuật toán (sắp xếp, đảo ngược, ...)
#include <fstream>  // Thư viện làm việc với file
#include <sstream>  // Thư viện xử lý chuỗi
#include <set>  // Thư viện sử dụng set để tránh cạnh trùng lặp

using namespace std;

// Hàm đọc dữ liệu từ file và xây dựng đồ thị VÔ HƯỚNG
void read_data(ifstream& fin, int& n, int& x, int& y, int& z, vector<vector<int>>& adj) {
    if (!(fin >> n >> x >> y >> z)) { // Đọc số đỉnh và đỉnh xuất phát

        cout << "Dữ liệu đầu vào không hợp lệ." << endl;

        return;
    }

    vector<set<int>> temp_adj(n + 1); // Sử dụng set để tránh cạnh trùng lặp
    string line;
    getline(fin, line); // Bỏ qua dòng trống/xuống dòng

    // Đọc n dòng tiếp theo (danh sách kề)
    for (int i = 1; i <= n; ++i) {
        if (!getline(fin, line)) {
            break;
        }

        stringstream ss(line); // Sử dụng stringstream để tách các số trong dòng
        int neighbor;   

        // Đọc các đỉnh kề cho đỉnh i
        while (ss >> neighbor) {
            // KIỂM TRA ĐIỀU KIỆN DỪNG: Nếu gặp -1, thoát khỏi vòng lặp này
            if (neighbor == -1) {
                break;
            }
            // Thêm cạnh (i, neighbor)
            temp_adj[i].insert(neighbor);
            // Thêm cạnh ngược (neighbor, i) vì là đồ thị vô hướng
            if (neighbor >= 1 && neighbor <= n) {
                temp_adj[neighbor].insert(i);
            }
        }
    }

    // Chuyển từ set sang vector cho danh sách kề cuối cùng
    adj.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        adj[i].assign(temp_adj[i].begin(), temp_adj[i].end());
    }
}

// Hàm đếm số thành phần liên thông
int countConnectedComponents(int n, const vector<vector<int>>& adj) {
    // Khởi tạo
    vector<bool> visited(n + 1, false);
    queue<int> q;
    int component_count = 0; // Đếm số thành phần liên thông

    // Duyệt qua tất cả các đỉnh
    for (int start_node = 1; start_node <= n; ++start_node) {
        if (!visited[start_node]) { // Nếu đỉnh chưa được thăm -> Bắt đầu một thành phần mới
            component_count++; // Tăng số thành phần liên thông
            q.push(start_node); 
            visited[start_node] = true;

            // Vòng lặp BFS
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                // Duyệt tất cả các đỉnh kề của u
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v); 
                    }
                }
            }
        }
    }
    return component_count;
}

// Hàm kiểm tra cạnh (x, y) có phải là cạnh cầu không
bool isBridge(int n, int x, int y, const vector<vector<int>>& adj) {
    // Đếm số thành phần liên thông ban đầu
    int initial_components = countConnectedComponents(n, adj);

    // Tạo đồ thị mới không có cạnh (x, y)
    vector<vector<int>> modified_adj = adj;
    modified_adj[x].erase(remove(modified_adj[x].begin(), modified_adj[x].end(), y), modified_adj[x].end());
    modified_adj[y].erase(remove(modified_adj[y].begin(), modified_adj[y].end(), x), modified_adj[y].end());

    // Đếm số thành phần liên thông sau khi loại bỏ cạnh (x, y)
    int new_components = countConnectedComponents(n, modified_adj);

    // Nếu số thành phần liên thông tăng lên, thì (x, y) là cạnh cầu
    return new_components > initial_components;
}

// Hàm kiểm tra đỉnh z có phải là đỉnh khớp không
bool isArticulationPoint(int n, int z, const vector<vector<int>>& adj) {
    // Đếm số thành phần liên thông ban đầu
    int initial_components = countConnectedComponents(n, adj);
    // Tạo đồ thị mới không có đỉnh z
    vector<vector<int>> modified_adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i == z) continue; // Bỏ qua đỉnh z
        for (int neighbor : adj[i]) {
            if (neighbor != z) {
                modified_adj[i].push_back(neighbor);
            }
        }
    }
    // Đếm số thành phần liên thông sau khi loại bỏ đỉnh z
    int new_components = countConnectedComponents(n, modified_adj);
    // Nếu số thành phần liên thông tăng lên, thì z là đỉnh khớp
    return new_components > initial_components;
}

//Hàm ghi kết quả ra file Dòng đầu tiên chữ “canh cau” nếu (x, y) là cạnh cầu hay “khong la canh cau” nếu (x, y) không phải là cạnh cầu. Dòng thứ 2 ghi “dinh khop” nếu z là đỉnh khớp hay “khong la dinh khop” nếu z không phải là đỉnh khớp.
void write_result(ofstream& fout, bool is_bridge, bool is_articulation) {
    if (is_bridge) {
        fout << "canh cau" << endl;
    } else {
        fout << "khong la canh cau" << endl;
    }

    if (is_articulation) {
        fout << "dinh khop" << endl;
    } else {
        fout << "khong la dinh khop" << endl;
    }
}

int main() {
    // Thiết lập nhập xuất từ file CanhCauDinhKhopBFS.INP và CanhCauDinhKhopBFS.OUT
    ifstream fin("CanhCauDinhKhopBFS.INP");
    ofstream fout("CanhCauDinhKhopBFS.OUT");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Không thể mở file INP/OUT." << endl;
        return 1;
    }

    int n, x, y, z;
    vector<vector<int>> adj;

    read_data(fin, n, x, y, z, adj);

    write_result(fout, isBridge(n, x, y, adj), isArticulationPoint(n, z, adj));

    fin.close();
    fout.close();

    return 0;
}   