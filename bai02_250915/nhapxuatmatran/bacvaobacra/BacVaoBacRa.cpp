#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    // Mở file đầu vào và đầu ra
    std::ifstream inputFile("BacVaoBacRa.inp");
    std::ofstream outputFile("BacVaoBacRa.out");

    // Kiểm tra xem file có mở thành công không
    if (!inputFile.is_open()) {
        std::cerr << "Loi: Khong the mo file BacVaoBacRa.inp!" << std::endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        std::cerr << "Loi: Khong the mo file BacVaoBacRa.out!" << std::endl;
        return 1;
    }

    // Đọc số đỉnh n
    int n;
    inputFile >> n;

    // Bỏ qua ký tự xuống dòng còn lại sau khi đọc số n
    std::string dummy;
    std::getline(inputFile, dummy);

    // Vector để lưu bậc vào và bậc ra của các đỉnh
    std::vector<int> inDegree(n, 0);
    std::vector<int> outDegree(n, 0);

    // Lặp qua từng dòng của ma trận kề, tính và lưu bậc
    std::string line;
    for (int i = 0; i < n; ++i) {
        std::getline(inputFile, line);
        std::stringstream ss(line); // Sử dụng stringstream để tách các số
        int value;
        for (int j = 0; j < n; ++j) { // Đọc từng giá trị trong dòng
            ss >> value;  // Đọc giá trị
            if (value == 1) { // Nếu có cạnh từ i đến j
                outDegree[i]++; // Tăng bậc ra của đỉnh i
                inDegree[j]++;  // Tăng bậc vào của đỉnh j
            }
        }
    }

    // Ghi kết quả vào file đầu ra
    outputFile << n << std::endl;
    for (int i = 0; i < n; ++i) {
        outputFile << inDegree[i] << " " << outDegree[i] << std::endl;
    }

    // Đóng file
    inputFile.close();
    outputFile.close();

    std::cout << "Da xu ly thanh cong! Ket qua duoc ghi vao file BacVaoBacRa.out" << std::endl;

    return 0;
}