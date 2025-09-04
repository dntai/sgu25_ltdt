#include<iostream>
#include<vector>
using namespace std;

vector<int> sieve(int n){// dùng thuật toán sieve để tìm các số nguyên tố
    vector<int> snt;
    vector<bool> isPrime(n+1,true);//tạo vector cờ và cho mặc định tất cả các số từ 0->n đều là số nguyên tố
    isPrime[0]=isPrime[1]=false;//đặt cờ 0 và 1 là không phải số nguyên tố
    for (int i=2;i<=n;i++){
        if(isPrime[i]){//nếu i là số nguyên tố
            snt.push_back(i);//thì thêm i vào danh sách các số nguyên tố
            for (int j=i*i;j<=n;j+=i){
                isPrime[j]=false;//sau đó đánh dấu tất cả bội của i trong khoảng N là không phải số nguyên tố
            }
        }
    }
    return snt;//trả về danh sách các số nguyên tố
}

int tinh_so_mu(int N,int p){//tính số mũ của p được truyền vào bằng cách phân tích các thừa số nguyên tố của N
    int mu=0;
    while(N>0){
        mu+=N/p;
        N/=p;
    }
    return mu;//khi hoàn tất trả về số mũ của p
}

int main(){
    vector<int> snt=sieve(1000);//tạo sẵn vector số nguyên tố cho các số từ 0->1000
    int N;
    while(cin>>N){//mỗi lần nhập vào N thì thực hiện chương trình 1 lần
        vector<int> mu;//tạo vector chứa mũ của các số nguyên tố 
        for(int p:snt){//phân tích từng số nguyên tố của vector sieve đã tạo ở trên
            if(p>N)
                break;
            mu.push_back(tinh_so_mu(N,p));//tính số mũ của p và thêm vào vector mu
        }
        //xóa các số 0 ở cuối vector mu để đúng định dạng đề cho
        while(!mu.empty()&&mu.back()==0)
            mu.pop_back();
        //in ra các số mũ của từng số nguyên tố trong vector mu
        for(size_t i=0;i<mu.size();i++){
            if ((i)>0)
                cout<<" ";
            cout<<mu[i];
        }
        cout<<"\n";
    }

}