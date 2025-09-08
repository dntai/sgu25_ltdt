#include <iostream>
#include <queue>

using namespace std;

struct T {
    int x, y, z;
    T(int a, int b, int c):x(a), y(b), z(c){}
};

bool operator < (const T &t1, const T &t2){
    return t1.z < t2.z;
}

bool operator > (const T &t1, const T &t2){
    return t1.z > t2.z;
}

struct MyComp {
    bool operator()(const T &t1,const T &t2) const {
        if(t1.x < t2.x) return true;
        return false;
    }
};

int main() {
    T a[] = {T(4,4,3),T(2,2,5),T(1,5,4),T(3,3,6)};
    priority_queue<T> maxHeap(a,a+4);// priority_queue<T, vector<T>,less<int>>
    priority_queue<T, vector<T>, greater<T>> minHeap(a,a+4);
    priority_queue<T, vector<T>,MyComp> myHeap(a,a+4);

    while (!maxHeap.empty()) {
        T t = maxHeap.top(); maxHeap.pop();
        cout << t.x << " " << t.y << " " << t.z << endl;
    }
    cout << endl;
    while (!minHeap.empty()) {
        T t = minHeap.top(); minHeap.pop();
        cout << t.x << " " << t.y << " " << t.z << endl;
    }
    cout << endl;
    while (!myHeap.empty()) {
        T t = myHeap.top(); myHeap.pop();
        cout << t.x << " " << t.y << " " << t.z << endl;
    }
    
    return 0;
}