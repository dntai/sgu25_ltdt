#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    const int max_i = 1000;
    int n;
    cin>> n;
    if(n>max_i)
    {
        cout<<"n<=1000";
        return 0;
    }
    vector<int>A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    vector<bool> tim_kiem(n+1,false); //tạo 1 mảng chỉ chứa giá trị true false , số nào xuất hiện lần đầu sẽ đuọc gán là false 
    for (int i=0;i<n;i++){
        int tam =A[i];
    if(tam<1||tam>n||tim_kiem[tam]==true) // kiểm tra dãy số có hoán vị không 
{
        cout<<"NO";
        return 0;
}
     tim_kiem[tam]=true;
    }
    cout<<"YES";
    return 0;
}
