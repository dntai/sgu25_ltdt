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

    sort(a.begin(), a.end());// 1 2 3 4 5
    sort(a.begin(), a.end(), greater<int>());// 5 4 3 2 1
    sort(a.begin(), a.end(), my_sorter());// 4 2 5 3 1
    sort(a.begin(), a.end(),greater<int>()); // 5 4 3 2 1

    do { // sinh hoan vi: 5 4 3 2 1 -> 1 2 3 4 5
         for_each(a.begin(),a.end(), print);
              cout << endl;
    }while(next_permutation(a.begin(),a.end(),greater<int>()));
    
return 0;
}