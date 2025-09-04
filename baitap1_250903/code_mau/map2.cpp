#include<iostream>
#include<map>
using namespace std;

struct T{
    int x,y,z;
    T(){}
    T(int a,int b,int c):x(a),y(b),z(c){}
    bool operator<(const T &t) const{
        if(x<t.x) return false;
        if(x==t.x && y<t.y) return false;
        if(x==t.x && y==t.y && z<t.z) return false;
        return true;
    }
};
struct MyComp{
    bool operator()(const T& a,const T&b) const{
        if (a.x>b.x)
            return false;
        if (a.x==b.x && a.y>b.y)
            return false;
        if (a.x==b.x && a.y==b.y && a.z>b.z)
            return false;
        return true;
    }
};

int main(){
    map<T,int> m1;
    m1[T(1,2,3)]=1;
    m1[T(3,3,1)]=2;
    m1[T(1,2,1)]=3;
    m1[T(2,2,1)]=4;

    map<T,int,MyComp> m2(m1.begin(),m1.end());
    return 0;
}