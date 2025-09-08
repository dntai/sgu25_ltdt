#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream fin("tong.in");
#define cin fin
int main(){
char line[10001];
int tong = 0;
while(cin.getline(line,10000,'\n')){
char *p;
p = strtok(line," ");
while(p!=NULL){
int a;
sscanf(p,"%d",&a);
tong += a;
p = strtok(NULL," ");
}
}
cout << tong << endl;
return 0;
}