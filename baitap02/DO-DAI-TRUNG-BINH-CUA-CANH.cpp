#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define FI "DO-DAI-TRUNG-BINH-CUA-CANH.INP"
#define FO "DO-DAI-TRUNG-BINH-CUA-CANH.OUT"

int main() {
    ifstream fi(FI);
    ofstream fo(FO);

    int n;
    fi >> n;
    vector<vector<int>> a(n, vector<int>(n));

    // Đọc ma trận trọng số
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fi >> a[i][j];
        }
    }
    fi.close();

    int maxW = -1;
    long long tong = 0; 
    int dem = 0;
    vector<pair<int,int>> canhMax;

    // Duyệt các cạnh (chỉ lấy i<j để tránh trùng)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] > 0) {
                tong += a[i][j];
                dem++;

                if (a[i][j] > maxW) {
                    maxW = a[i][j];
                    canhMax.clear();
                    canhMax.push_back({i+1, j+1});
                } else if (a[i][j] == maxW) {
                    canhMax.push_back({i+1, j+1});
                }
            }
        }
    }

    // Xuất kết quả
    fo << canhMax.size() << "\n";
    for (auto c : canhMax) {
        fo << c.first << " " << c.second << " ";
    }
    fo << "\n";

    double tb = (double)tong / dem;
    fo << tb << "\n";  

    fo.close();
    return 0;
}