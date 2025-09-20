#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int a[] = {5,3,2,1,4,3};

    stack<int> s(deque<int>(a,a+6));
    queue<int> q;

    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}