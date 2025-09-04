#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> A(N);//Khai báo vector A có N phần tử
    for(int i=0;i<N;i++){
        cin >> A[i]; //Nhập N phần tử cho vector A
    }
    vector<int> CHECK(N+1,0);//khai báo vector CHECK tương đương với vector cờ để đánh dấu các số đã xuất hiện
    for (int i=0;i<N;i++){
        int x=A[i];
        //kiểm tra nếu 1 phần tử của A không thuộc khoảng từ 1->N hoặc đã xuất hiện thì in ra NO và kết thúc chương trình
        if(x<1||x>N){
            cout<<"NO";
            return 0;
        }
        if (CHECK[x]){
            cout<<"NO";
            return 0;
        }
        CHECK[x]=1;
    }
    //nếu duyệt hết mảng A mà không in ra NO thì in ra YES
    cout<<"YES";
    return 1;

}