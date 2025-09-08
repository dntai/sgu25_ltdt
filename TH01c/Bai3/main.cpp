#include<iostream>
#include<vector>

using namespace std;

// Hàm sinh các số nguyên tố nhỏ hơn hoặc bằng n bằng sàng Eratosthenes
vector<int> getPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return primes;
}

// Hàm phân tích thừa số nguyên tố của N! và in ra dãy số lần xuất hiện
void analyse(int N, const vector<int>& primes) {
    vector<int> counts;
    for (int p : primes) {
        if (p > N) break; // Chỉ xét các số nguyên tố <= N
        int cnt = 0;
        int temp = N;
        // Đếm số lần xuất hiện của p trong N!
        while (temp) {
            cnt += temp / p;
            temp /= p;
        }
        counts.push_back(cnt);
    }
    // Loại bỏ các số 0 ở cuối dãy (chỉ giữ phần tử cuối cùng là số dương)
    while (!counts.empty() && counts.back() == 0) counts.pop_back();
    for (size_t i = 0; i < counts.size(); ++i) {
        cout << counts[i];
        if (i + 1 < counts.size()) cout << " ";
    }
    cout << endl;
}

int main() {
    vector<int> primes = getPrimes(1000); // Sinh trước các số nguyên tố <= 1000
    int N;
    while (cin >> N) { // Đọc nhiều dòng, mỗi dòng 1 số N
        analyse(N, primes);
    }
    return 0;
}