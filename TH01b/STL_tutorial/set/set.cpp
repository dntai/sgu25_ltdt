/* Phép toán trên tập hợp*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a[] = {1,5,3,2,1,4,3};
    set<int> s1(a, a+7);// {1,2,3,4,5}
    s1.insert(3); // not happen
    s1.erase(4); // {1,2,3,5}

    cout << (s1.find(5) != s1.end()) << endl; // TRUE: find 5

    for(set<int>::iterator it = s1.lower_bound(2); it!=s1.upper_bound(4);it++){
        int x = *it;
        cout << x << " " << endl;
    }// 2 <= 2,3 <= 4

    if(!s1.empty()) s1.clear();
    
    return 0;
}