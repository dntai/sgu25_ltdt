#include <iostream>

using namespace std;

// Hàm đếm số chữ số 0 ở cuối của N!
// Phương pháp sử dụng công thức Legendre, bằng cách đếm số thừa số 5.
int countTrailingZeros(long long n) {
    int count = 0;
    // Đếm số thừa số 5 trong các số từ 1 đến n
    // Mỗi số chia hết cho 5 đóng góp ít nhất một thừa số 5,
    // số chia hết cho 25 đóng góp thêm một thừa số 5 nữa,
    // số chia hết cho 125 đóng góp thêm một thừa số 5 nữa,
    // và cứ thế tiếp tục.
    for (long long i = 5; n / i >= 1; i *= 5) {
        // Cộng số bội của i (5, 25, 125, ...) trong các số từ 1 đến n
        count += n / i;
    }
    return count;
}

int main() {
    // Dùng long long để tránh tràn số với các giá trị N lớn
    long long N;
    while (cin >> N) {
        cout << countTrailingZeros(N) << endl;
    }

    return 0;
}