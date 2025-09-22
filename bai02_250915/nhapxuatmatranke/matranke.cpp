#include<iostream>
#include<vector>
#include<fstream>
#define inp "test.txt" // tên file input

using namespace std;

struct adjacencyMatrix // ma trận kề
{
    int n; // số đỉnh
    vector<vector<int>> a; // ma trận kề

    void input() { // đọc ma trận kề từ file
        ifstream fi(inp);
        if (!fi.is_open()) { // kiểm tra file có mở được không
            cout << "Khong the mo file " << inp << endl;
            n = 0;
            return;
        }
        fi >> n; // đọc số đỉnh
        if (n <= 0) { // kiểm tra số đỉnh có hợp lệ không
            cout << "So dinh khong hop le!" << endl;
            n = 0;
            return;
        }
        a.resize(n, vector<int>(n)); // cấp phát bộ nhớ cho ma trận kề
        for(int i = 0; i < n; i++) { // đọc ma trận kề
            for(int j = 0; j < n; j++) {
                fi >> a[i][j];
            }
        }
        fi.close();
    }

    void outputMatrix() // xuất ma trận kề
    {
        cout << "So dinh cua do thi la " << n << endl;
        cout << "Ma tran ke cua do thi la" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "\t";
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Hàm kiểm tra đồ thị vô hướng
    bool isUndirected()
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // So sánh a[i][j] với a[j][i]
                if (a[i][j] != a[j][i]) {
                    return false; // Nếu không đối xứng, đồ thị là có hướng
                }
            }
        }
        return true; // Nếu duyệt hết và đối xứng, đồ thị là vô hướng
    }
};

int main()
{
    adjacencyMatrix G;
    G.input();
    if (G.n > 0) {
        G.outputMatrix();

        // Bổ sung: Gọi hàm kiểm tra và in kết quả
        if (G.isUndirected()) {
            cout << "Do thi la do thi vo huong." << endl;
        } else {
            cout << "Do thi la do thi co huong." << endl;
        }
    }
    return 0;
}