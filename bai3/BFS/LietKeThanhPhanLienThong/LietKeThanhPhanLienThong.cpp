#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

// Hàm đọc dữ liệu từ file và xây dựng đồ thị VÔ HƯỚNG
void read_data(ifstream& fin, int& n, vector<vector<int>>& adj) {
    if (!(fin >> n)) { // Đọc số đỉnh và đỉnh xuất phát

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

// Hàm trả về vector các vector (mỗi vector con là một thành phần liên thông)
vector<vector<int>> findConnectedComponents(int n, const vector<vector<int>>& adj) {
    // Khởi tạo
    vector<bool> visited(n + 1, false);
    queue<int> q;
    vector<vector<int>> connected_components; // Danh sách các thành phần liên thông

    // Duyệt qua tất cả các đỉnh
    for (int start_node = 1; start_node <= n; ++start_node) {
        if (!visited[start_node]) { // Nếu đỉnh chưa được thăm -> Bắt đầu một thành phần mới
            
            vector<int> current_component; // Danh sách để lưu trữ thành phần hiện tại
            q.push(start_node); 
            visited[start_node] = true;

            // Vòng lặp BFS
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                // Thêm u vào thành phần hiện tại (Chỉ thêm 1 lần tại đây)
                current_component.push_back(u); 

                // Duyệt tất cả các đỉnh kề của u
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v); 
                    }
                }
            }
            // Lưu kết quả
            // Khi BFS kết thúc, current_component chứa TẤT CẢ các đỉnh của 
            // thành phần liên thông bắt đầu từ start_node.
            connected_components.push_back(current_component);
        }
    }
    return connected_components;
}

// Hàm ghi kết quả ra file
void write_result(ofstream& fout, const vector<vector<int>>& result) {
    // Ghi số lượng thành phần liên thông
    fout << result.size() << endl;
    // Ghi từng thành phần liên thông ra file
    for (const auto& component : result) {
        for (size_t i = 0; i < component.size(); ++i) {
            fout << component[i];
            if (i < component.size() - 1) {
                fout << " "; // Cách nhau bởi dấu cách
            }
        }
        fout << endl; // Kết thúc mỗi thành phần bằng một dòng mới
    }
}

int main() {
    // Thiết lập nhập xuất từ file LietKeThanhPhanLienThong.INP và LietKeThanhPhanLienThong.OUT
    ifstream fin("LietKeThanhPhanLienThong.INP");
    ofstream fout("LietKeThanhPhanLienThong.OUT");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Không thể mở file INP/OUT." << endl;
        return 1;
    }

    int n;
    vector<vector<int>> adj;

    read_data(fin, n, adj);

    vector<vector<int>> result = findConnectedComponents(n, adj);

    write_result(fout, result);

    fin.close();
    fout.close();

    return 0;
}
