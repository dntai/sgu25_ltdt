#include <iostream>
#include <deque>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
int main() {
deque<pair<int,string>> a(2,make_pair<int,string>(-1,"NULL")); // a.size()==2,
a[i]="NULL"
deque<pair<int,string>> b;
a.push_front(make_pair<int,string>(1,"Mot"));
a.push_front(make_pair<int,string>(2,"Hai"));
b = a; // gán nội dung của a vào b
while(!b.empty()) {
pair<int,string> v = b.front();
b.pop_front();
cout << "(" << v.first << "," << v.second<< ")";
}
return 0;
} //Kết quả: (2,Hai)(1,Mot)(-1,NULL)(-1,NULL)
//Các thao tác trên deque: giống vector nhưng bổ sung thêm các phương thức:
//d.front(), d.push_front(), d.pop_front()
