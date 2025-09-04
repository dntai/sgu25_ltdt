#include<iostream>
#include<string>
using namespace std;

int main(){
    string a="acm icpc world";
    cout<<a.size()<<" ";
    cout<<!a.empty()<<" ";
    a+=" final";
    a.push_back('.');
    cout<<a.find("icpc")<<" ";
    cout<<(a.find("acm",5)==string::npos)<<" ";
    cout<<a.find_first_of("ijk")<<" ";
    cout<<a.find_first_not_of("abcde")<<" ";
    cout<<a.find_first_of(' ',4)<<" ";
    string b=a.substr(4,4);
    string c=a.substr(15);
    a.insert(a.size()-1," 2010");
    a.erase(14);
    a.replace(9,a.size()-9,"WF");
    a.erase(3);
    printf("%s\n",a.c_str());
    return 0;
}