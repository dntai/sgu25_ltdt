#include <iostream>
#include <fstream>
#include<string>
#include<cstring>
using namespace std;
ifstream fin("tong.in");
#define cin fin

int main(){
char line[10001];
int tong = 0;
while(cin.getline(line,10000,'\n')){
    int d = 0, a, tmp,tong=0;
    int len = strlen(line);
    while(d<len){
        if(sscanf(line+d,"%d%n",&a, &tmp)==1){
            tong += a;
            d += tmp;
        }
        else
            d++;
    }
    cout << tong << endl;
}
return 0;
}