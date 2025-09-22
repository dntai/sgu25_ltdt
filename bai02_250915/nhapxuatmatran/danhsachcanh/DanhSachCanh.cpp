#include <iostream>
#include <fstream>
#include <vector>// Thư viện để sử dụng vector

int main() {
    // Mở file đầu vào và đầu ra
    std::ifstream inputFile("DanhSachCanh.inp");
    std::ofstream outputFile("DanhSachCanh.out");

    // Kiểm tra xem file có mở thành công không
    if (!inputFile.is_open()) {
        std::cerr << "Loi: Khong the mo file DanhSachCanh.inp!" << std::endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        std::cerr << "Loi: Khong the mo file DanhSachCanh.out!" << std::endl;
        return 1;
    }

    // Đọc số đỉnh n và số cạnh m
    int n, m; 
    inputFile >> n >> m;

    // Vector để lưu bậc của các đỉnh, sử dụng kích thước n+1 để dễ truy cập
    std::vector<int> degrees(n + 1, 0);

    // Đọc từng cạnh và tính bậc
    int u, v;
    for (int i = 0; i < m; ++i) { // Lặp m lần để đọc m cạnh
        inputFile >> u >> v; // Đọc cạnh từ u đến v
        degrees[u]++; // Tăng bậc của đỉnh u
        degrees[v]++; // Tăng bậc của đỉnh v 
    }

    // Ghi kết quả vào file đầu ra
    outputFile << n << std::endl;
    for (int i = 1; i <= n; ++i) {
        outputFile << degrees[i] << std::endl;
    }

    // Đóng file
    inputFile.close();
    outputFile.close();

    std::cout << "Da xu ly thanh cong! Ket qua duoc ghi vao file DanhSachCanh.out" << std::endl;

    return 0;
}