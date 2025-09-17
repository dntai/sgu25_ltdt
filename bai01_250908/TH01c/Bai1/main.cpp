#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Hàm giải quyết bài toán cho mỗi test case
void solve(istream& input_stream) {
    string s;
    input_stream >> s; // Đọc chuỗi ký tự từ luồng đầu vào

    // Sử dụng map để lưu số lần xuất hiện của mỗi bộ ba ký tự
    map<string, int> counts;

    // Kiểm tra độ dài chuỗi để đảm bảo có thể tạo ít nhất một bộ ba
    if (s.length() >= 3) {
        // Duyệt qua chuỗi để lấy tất cả các bộ ba ký tự liên tiếp
        for (size_t i = 0; i <= s.length() - 3; ++i) {
            string boba = s.substr(i, 3);
            counts[boba]++;
        }
    }

    int max_count = 0;
    // Tìm số lần xuất hiện lớn nhất của các bộ ba
    for (const auto& pair : counts) {
        if (pair.second > max_count) {
            max_count = pair.second;
        }
    }
    cout << max_count << endl;
}

int main() {
    int T;
    cin >> T; // Đọc số lượng test case từ bàn phím

    while (T--) {
        solve(cin); // Gọi hàm solve() và truyền vào luồng nhập chuẩn
    }

    return 0;
}