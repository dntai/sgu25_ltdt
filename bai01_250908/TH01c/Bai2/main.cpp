#include<iostream>
#include<vector>

using namespace std;

// Hàm kiểm tra xem một mảng có phải là hoán vị của các số từ 1 đến N hay không
void isPermutation(int N, const vector<int>& numbers) {
    vector<bool> seen(N + 1, false); // Mảng đánh dấu các số đã xuất hiện
    for (int num : numbers) {
        if (num < 1 || num > N || seen[num]) {
            cout << "NO" << endl; // Nếu số không hợp lệ hoặc đã xuất hiện trước đó
            return;
        }
        seen[num] = true; // Đánh dấu số đã xuất hiện
    }

    cout << "YES" << endl; // Nếu tất cả các số từ 1 đến N đều xuất hiện đúng một lần

}

int main() {
    int N;
    vector<int> numbers;

    cin >> N; // Đọc số lượng test case từ bàn phím

    // Nhập N số nguyên vào vector
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        numbers.push_back(x);
    }

    isPermutation(N, numbers); // Kiểm tra và in kết quả
 
    return 0;
}