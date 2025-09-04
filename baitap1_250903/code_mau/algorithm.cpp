#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
struct my_sorter {
bool operator()(int a, int b) {
if(a%2==0&&b%2==1) return true;
return false;
}
};
void print(int x) { cout << x << " "; }
int main() {
    int b[] = {1, 5, 3, 4, 2};
    vector<int> a(b, b + 5);
    sort(a.begin(), a.end());
    sort(a.begin(), a.end(), greater<int>());
    sort(a.begin(), a.end(), my_sorter());
    sort(a.begin(), a.end(),greater<int>());
    do { 
    for_each(a.begin(),a.end(), print);
        cout << endl;
    }
    while(next_permutation(a.begin(),a.end(),greater<int>()));
    return 0;
}