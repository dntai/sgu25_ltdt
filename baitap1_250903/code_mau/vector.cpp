#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a; // empty vector
    vector<int> b(100); // b.size() == 100
    vector<int> c(100, 0); // c.size() == 100, c[i] == 0

    a.push_back(1);
    a.push_back(3);
    a.push_back(5); // a == {1, 3, 5}
    a.pop_back(); // a == {1, 3}

    
    cout << "Elements of a (by index): ";
    for (int i = 0 ; i < a.size() ; i++) {
        int x = a[i];
        cout << x << " ";
    }
    cout << endl;

    
    cout << "Elements of a (by iterator): ";
    for (vector<int>::iterator it = a.begin(); it != a.end(); it++) {
        int x = *it;
        cout << x << " ";
    }
    cout << endl;

    
    cout << "Elements of a (reverse): ";
    for (vector<int>::reverse_iterator it = a.rbegin(); it != a.rend(); it++) {
        int x = *it;
        cout << x << " ";
    }
    cout << endl;

    
    a.insert(find(a.begin(), a.end(), 1), 2); // a == {2, 1, 3}
    cout << "After insert 2 before 1: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    
    a.erase(find(a.begin(), a.end(), 3)); // a == {2, 1}
    cout << "After erase 3: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    
    if (!a.empty())
        a.clear();

    cout << "Size of a after clear: " << a.size() << endl;

    return 0;

}