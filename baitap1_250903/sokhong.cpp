#include<iostream>

using namespace std;
// hàm đếm số lượng số 0 ở cuối giai thừa của n
long long dem_so_0(long long n){
    long long dem=0;
    // dùng đếm số thừa số 5 vì nếu n!<4 thì không có số 0 nào ở cuối 
    while(n>0){
        dem+=n/5;// đếm số lượng bội của 5 trong n!
        n/=5;
    }
    return dem;// trả về số lượng số 0 ở cuối giai thừa của n
}

int main(){
    long long N;//khai báo biến giai thừa N
    while(cin>>N){//nỗi N nhập vào sẽ tìm và in số lượng số 0
        cout<<dem_so_0(N)<<endl;
    }
}