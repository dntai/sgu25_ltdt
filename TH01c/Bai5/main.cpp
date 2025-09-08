#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int nx, ny, nz;

    // Đọc số lượng phần tử của tập hợp X
    cin >> nx;
    vector<int> X;
    // Giới hạn giá trị phần tử trong khoảng [0, 10000]
    for (int i = 0; i < nx; ++i) {
        int val;
        cin >> val;
        if (val >= 0 && val <= 10000) {
            X.push_back(val);
        }
    }
    // Đọc số lượng phần tử của tập hợp Y
    cin >> ny;
    vector<int> Y;
    // Giới hạn giá trị phần tử trong khoảng [0, 10000]
    for (int i = 0; i < ny; ++i) {
        int val;
        cin >> val;
        if (val >= 0 && val <= 10000) {
            Y.push_back(val);
        }
    }

    // Đọc số lượng phần tử của tập hợp Z
    cin >> nz;
    vector<int> Z;
    // Giới hạn giá trị phần tử trong khoảng [0, 10000]
    for (int i = 0; i < nz; ++i) {
        int val;
        cin >> val;
        if (val >= 0 && val <= 10000) {
            Z.push_back(val);
        }
    }

    // Xử lý để tìm giao của ba tập hợp
    // Sắp xếp và loại bỏ phần tử trùng lặp trong mỗi tập hợp
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    sort(Z.begin(), Z.end());
    Z.erase(unique(Z.begin(), Z.end()), Z.end());

    // Tìm giao của ba tập hợp
    vector<int> tmp(min(X.size(), Y.size()));
    auto tmp_end = set_intersection(X.begin(), X.end(), Y.begin(), Y.end(), tmp.begin());
    tmp.resize(tmp_end - tmp.begin());
    // tmp bây giờ chứa giao của X và Y
    vector<int> A(min(tmp.size(), Z.size()));
    auto end = set_intersection(tmp.begin(), tmp.end(), Z.begin(), Z.end(), A.begin());
    // end là iterator chỉ phần tử cuối cùng trong A sau khi tìm giao với Z
    // A bây giờ chứa giao của X, Y và Z

    // In kết quả
    cout << distance(A.begin(), end) << endl;
    for (auto it = A.begin(); it != end; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}