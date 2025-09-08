#include <set>
#include <iostream>

using namespace std;

int main() {
    multiset<int>::iterator it;
    multiset<int> s;

    s.insert(1); s.insert(5); s.insert(1);
    s.insert(3); s.insert(3); s.insert(2);
    // s[6](1,1,2,3,3,5)
    cout << s.count(3) << endl; // 2
    pair<multiset<int>::iterator,multiset<int>::iterator> ret = s.equal_range(3);
    for(it = ret.first;it!=ret.second;it++){
        cout << (*it) << " ";// 3 3
    }
    cout << endl;
    for(it = s.begin();it!=s.end();it++) {
        cout << (*it) << " ";
    }// 1 1 2 3 3 5
    return 0;
}