#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

// Hàm đọc dữ liệu từ file và xây dựng đồ thị VÔ HƯỚNG
void read_data(ifstream& fin, int& n, int& x, int& y, vector<vector<int>>& adj) {
    if (!(fin >> n >> x >>y)) { // Đọc số đỉnh và đỉnh xuất phát

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

// Thuật toán BFS để tìm đường đi từ x đến y
vector<int> BFS(int n, int start_node, int target_node, const vector<vector<int>>& adj) {
    // Khởi tạo
    vector<bool> visited(n + 1, false); // Đánh dấu các đỉnh đã thăm
    queue<int> q;   // Hàng đợi cho BFS
    vector<int> all_result; // Lưu TẤT CẢ các đỉnh tìm được

    if (start_node == target_node) {
        return {start_node}; // Nếu đỉnh bắt đầu trùng với đích, trả về ngay
    }

    if (start_node < 1 || start_node > n || target_node < 1 || target_node > n) {
        return all_result; // Nếu đỉnh không hợp lệ, trả về rỗng
    }
    vector<int> parent(n + 1, -1); // Mảng để theo dõi đường đi
    // Bắt đầu duyệt
    visited[start_node] = true; // Đánh dấu đỉnh x đã thăm
    q.push(start_node); // Đưa x vào hàng đợi
    all_result.push_back(start_node); // Thêm x vào danh sách tạm thời
    parent[start_node] = -1; // Đỉnh bắt đầu không có cha
    bool found = false; // Cờ để kiểm tra nếu đã tìm thấy đích
    // Vòng lặp BFS
    while (!q.empty() && !found) {    // Trong khi hàng đợi không rỗng và chưa tìm thấy đích
        int u = q.front();  // Lấy đỉnh đầu hàng đợi
        q.pop(); // Loại bỏ đỉnh khỏi hàng đợi

        // Duyệt tất cả các đỉnh kề của u
        for (int v : adj[u]) {
            if (!visited[v]) { // Nếu đỉnh v chưa thăm
                visited[v] = true; // Đánh dấu v đã thăm
                q.push(v); // Đưa v vào hàng đợi
                all_result.push_back(v); // Thêm v vào danh sách tạm thời
                parent[v] = u; // Gán cha của v là u

                if (v == target_node) { // Nếu đã tìm thấy đích
                    found = true;
                    break; // Thoát khỏi vòng lặp
                }
            }
        }
    }
    vector<int> path; // Lưu đường đi từ x đến y
    if (found) {
        // Truy vết đường đi từ target_node về start_node
        for (int v = target_node; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end()); // Đảo ngược để có đường đi đúng từ x đến y
    }
    return path; // Trả về đường đi tìm được (nếu có)
}


// Hàm ghi kết quả ra file
void write_result(ofstream& fout, const vector<int>& result) {
    if (result.empty()) {
        fout << 0 << endl; // Nếu không tìm được đường đi, ghi 0
    } else {
        // Ghi số lượng đỉnh
        fout << result.size() << endl;
        // Ghi danh sách đỉnh
        for (size_t i = 0; i < result.size(); ++i) {
            fout << result[i];
            if (i != result.size() - 1) {
                fout << " "; // Cách nhau bằng dấu cách
            }
        }
        fout << endl; // Kết thúc dòng
    }
}

int main() {
    // Thiết lập nhập xuất từ file DuongDiBFS.INP và DuongDiBFS.OUT
    ifstream fin("DuongDiBFS.INP");
    ofstream fout("DuongDiBFS.OUT");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Không thể mở file INP/OUT." << endl;
        return 1;
    }

    int n, x, y;
    vector<vector<int>> adj;

    read_data(fin, n, x, y, adj);

    vector<int> result = BFS(n, x, y, adj);

    write_result(fout, result);

    fin.close();
    fout.close();

    return 0;
}
