#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    const int MAX_LEN = 106;
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        if (s.size() > MAX_LEN) {
            cout << "toi da 106 ky tu" << endl;
            continue;
        }

        map<string,int> tan_suat;

        // Đếm tần suất các chuỗi con 3 ký tự
        for (int i = 0; i + 2 < s.size(); i++) {
            string sub = s.substr(i, 3);
            tan_suat[sub]++;
        }

        int lonnhat = 0;

        // Tìm tần suất lớn nhất
        for (auto it : tan_suat) {
            lonnhat = max(lonnhat, it.second);
        }

        cout << lonnhat << endl;
    }

    return 0;
}
