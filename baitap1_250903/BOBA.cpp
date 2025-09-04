#include<iostream>
#include<string>
#include<map> // dùng map cho chương trình


using namespace std;

int main(){
    int T;
    cin>>T;
    //khai báo biến T và lặp T lần để nhập các chuỗi
    while(T--){
        string s;
        cin>>s;
        map<string,int> chuoi;//khai báo map để lưu trữ các chuỗi con độ và số lần xuất hiện của chúng
        int chieu_dai_chuoi=s.size();//lấy chiều dài chuỗi đã nhập
        int lan_lap_max=0; // lưu số lần lặp của chuỗi đang kiểm tra
        //duyệt từng chuỗi con độ dài 3 trong chuỗi s
        for(int i=0;i+2<chieu_dai_chuoi;i++){
            string sub=s.substr(i,3);//lấy chuỗi con độ dài 3 bắt đầu từ vị trí i
            chuoi[sub]++;// tăng số lần lặp của chuỗi đó lên 1 trong vector lưu
            if (chuoi[sub]>lan_lap_max)//xác định số lần lặp lại tối đa
                lan_lap_max=chuoi[sub];
        }
        cout<<lan_lap_max<<endl;
    }
}