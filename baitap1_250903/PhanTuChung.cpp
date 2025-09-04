#include<iostream>
#include<vector>
#include<algorithm> // dùng set_intersection và sort
using namespace std;

int main(){
    int nx,ny,nz;
    cin>>nx;
    vector<int> x(nx);
    for(int i=0;i<nx;i++)
        cin>>x[i];
    cin>>ny;
    vector<int> y(ny);
    for(int i=0;i<ny;i++)
        cin>>y[i];
    cin>>nz;
    vector<int> z(nz);
    for(int i=0;i<nz;i++)
        cin>>z[i];
    // Xắp xếp các phần tử bên trong 3 vector đã nhập theo thứ tự tăng dần
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(z.begin(),z.end());

    // tìm giao cua vector x và y
    vector<int> xy;
    set_intersection(x.begin(),x.end(),y.begin(),y.end(),back_inserter(xy));
    // tìm giao của vector xy đã tạo ở trên và vector z
    vector<int> xyz;
    set_intersection(xy.begin(),xy.end(),z.begin(),z.end(),back_inserter(xyz));
    // xóa các phần tử trùng nhau trong vector xyz
    xyz.erase(unique(xyz.begin(),xyz.end()),xyz.end());
    //in ra số lượng phần tử trong vector xyz tướng ứng cho số phần tử trùng nhau
    cout<<xyz.size()<<endl;
    // duyệt và in ra tất cả phần tử trong vector xyz
    for(int phantu:xyz){
        cout<<phantu<<" ";
    }
}   
