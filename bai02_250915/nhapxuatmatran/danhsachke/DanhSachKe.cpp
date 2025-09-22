#include <iostream> // Thư viện để nhập xuất chuẩn
#include <fstream> // Thư viện để làm việc với file
#include <vector>   // Thư viện để sử dụng vector
#include <string>   // Thư viện để sử dụng string
#include <sstream>  // Thư viện để sử dụng stringstream

int main() {
    // Mở file đầu vào và đầu ra
    std::ifstream inputFile("DanhSachKe.inp");
    std::ofstream outputFile("DanhSachKe.out");

    // Kiểm tra xem file có mở thành công không
    if (!inputFile.is_open()) {
        std::cerr << "Loi: Khong the mo file DanhSachKe.inp!" << std::endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        std::cerr << "Loi: Khong the mo file DanhSachKe.out!" << std::endl;
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

    //Lặp qua từng dòng của danh sách kề, tính và lưu bậc
    std::string line;
    for (int i = 0; i < n; ++i) {
        std::getline(inputFile, line); // Đọc một dòng
        std::stringstream ss(line); // Sử dụng stringstream để tách các số
        int vertex; // Biến để đọc từng đỉnh kề
        int current_degree = 0; // Bậc hiện tại của đỉnh i
        
        while (ss >> vertex) { // Đọc từng giá trị trong dòng
            current_degree++; // Tăng bậc cho mỗi đỉnh kề được đọc
        }
        degrees.push_back(current_degree); // Lưu bậc của đỉnh i
    }

    // Ghi kết quả vào file đầu ra
    outputFile << n << std::endl; // Ghi số đỉnh
    for (int i = 0; i < n; ++i) { // Ghi bậc của từng đỉnh
        outputFile << degrees[i] << std::endl; 
    }

    // Đóng file
    inputFile.close();
    outputFile.close();

    std::cout << "Da xu ly thanh cong! Ket qua duoc ghi vao file DanhSachKe.out" << std::endl;

    return 0;
}