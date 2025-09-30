#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

// Hàm đọc dữ liệu từ file và xây dựng đồ thị VÔ HƯỚNG
void read_data(ifstream& fin, int& n, int& x, vector<vector<int>>& adj) {
    if (!(fin >> n >> x)) { // Đọc số đỉnh và đỉnh xuất phát

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

// Thuật toán BFS để tìm các đỉnh liên thông
vector<int> BFS(int start_node, int n, const vector<vector<int>>& adj) {
    // Khởi tạo
    vector<bool> visited(n + 1, false); // Đánh dấu các đỉnh đã thăm
    queue<int> q;   // Hàng đợi cho BFS
    vector<int> all_result; // Lưu TẤT CẢ các đỉnh tìm được

    if (start_node < 1 || start_node > n) { // Kiểm tra đỉnh x có hợp lệ không
        return all_result;
    }

    // Bắt đầu duyệt
    visited[start_node] = true; // Đánh dấu đỉnh x đã thăm
    q.push(start_node); // Đưa x vào hàng đợi
    all_result.push_back(start_node); // Thêm x vào danh sách tạm thời

    // Vòng lặp BFS
    while (!q.empty()) {    // Trong khi hàng đợi không rỗng
        int u = q.front();  // Lấy đỉnh đầu hàng đợi
        q.pop(); // Loại bỏ đỉnh khỏi hàng đợi

        for (int v : adj[u]) {  // Duyệt các đỉnh kề của u
            if (v >= 1 && v <= n && !visited[v]) { // Nếu đỉnh v chưa thăm
                visited[v] = true; // Đánh dấu v đã thăm
                q.push(v);  // Đưa v vào hàng đợi
                all_result.push_back(v); // Thêm v vào danh sách tạm thời
            }
        }
    }

    // Lọc kết quả: Loại bỏ đỉnh xuất phát (x)
    vector<int> filtered_result; // Lưu kết quả cuối cùng
    for (int node : all_result) { // Duyệt qua tất cả các đỉnh tìm được
        if (node != start_node) {   // Loại bỏ đỉnh xuất phát
            filtered_result.push_back(node); // Thêm đỉnh vào kết quả cuối cùng
        }
    }

    return filtered_result;
}

// Hàm ghi kết quả ra file
void write_result(ofstream& fout, const vector<int>& result) {
    // Ghi số lượng đỉnh
    fout << result.size() << endl;

    // Ghi danh sách đỉnh
    for (size_t i = 0; i < result.size(); ++i) {
        fout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    fout << endl;
}

int main() {
    // Thiết lập nhập xuất từ file LienThongBFS.INP và LienThongBFS.OUT
    ifstream fin("LienThongBFS.INP");
    ofstream fout("LienThongBFS.OUT");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Không thể mở file INP/OUT." << endl;
        return 1;
    }

    int n, x;
    vector<vector<int>> adj;

    read_data(fin, n, x, adj);

    vector<int> result = BFS(x, n, adj);

    write_result(fout, result);

    fin.close();
    fout.close();

    return 0;
}
