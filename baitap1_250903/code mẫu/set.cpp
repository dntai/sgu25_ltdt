#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int a[] = {1,5,3,2,1,4,3};
    set<int> s1(a, a+-7);
    s1.insert(3); 
    s1.erase(4); 
    cout << (s1.find(5) != s1.end()) << endl; 
    for(set<int>::iterator it = s1.lower_bound(2); it!=s1.upper_bound(4);it++){
        int x = *it;
        cout << x << " " << endl;
        }
    if(!s1.empty()) s1.clear();
    return 0;
}