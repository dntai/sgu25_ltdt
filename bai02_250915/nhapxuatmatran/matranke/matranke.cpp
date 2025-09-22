#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    // Mở file đầu vào và đầu ra
    std::ifstream inputFile("MaTranKe.inp");
    std::ofstream outputFile("MaTranKe.out");

    // Kiểm tra xem file có mở thành công không
    if (!inputFile.is_open()) {
        std::cerr << "Loi: Khong the mo file MaTranKe.inp!" << std::endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        std::cerr << "Loi: Khong the mo file MaTranKe.out!" << std::endl;
        return 1;
    }

    // Đọc số đỉnh n
    int n;
    inputFile >> n;

    // Bỏ qua ký tự xuống dòng còn lại sau khi đọc số n
    std::string dummy;
    std::getline(inputFile, dummy); 

    // Vector để lưu bậc của các đỉnh
    std::vector<int> degrees;
    degrees.reserve(n); // Tối ưu hóa bộ nhớ

    // Đọc từng dòng của ma trận kề, tính và lưu bậc
    std::string line;
    for (int i = 0; i < n; ++i) {
        std::getline(inputFile, line); // Đọc một dòng
        std::stringstream ss(line); // Sử dụng stringstream để tách các số
        int value;
        int current_degree = 0; // Bậc của đỉnh hiện tại
        while (ss >> value) { // Đọc từng giá trị trong dòng
            current_degree += value; // Cộng giá trị vào bậc
        }
        degrees.push_back(current_degree); // Lưu bậc vào vector
    }

    // Ghi kết quả vào file đầu ra
    outputFile << n << std::endl; // Ghi số đỉnh
    for (int i = 0; i < n; ++i) { // Ghi bậc của từng đỉnh
        outputFile << degrees[i] << std::endl;
    }

    // Đóng file
    inputFile.close();
    outputFile.close();

    std::cout << "Da xu ly thanh cong! Ket qua duoc ghi vao file MaTranKe.out" << std::endl;

    return 0;
}