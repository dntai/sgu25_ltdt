/* Nhập và kiểm tra tính đúng đắn của biểu thức
INPUT 1+3 OUTPUT 1+3=4

4-5 4-5=-1
4/0 4/0=Error */

#include <iostream>
#include <fstream>
using namespace std;
// DEBUG: nhập từ tập tin
ifstream fin("numbers.in");
#define cin fin
int main(){
char line[1000];
while(cin.getline(line,1000,'\n')) {
int a, b; char op; char ret[100];
sscanf(line,"%d%c%d",&a,&op,&b);
switch(op){
case '+': sprintf(ret,"%d%c%d=%d",a,op,b,a+b); break;
case '-': sprintf(ret,"%d%c%d=%d",a,op,b,a-b); break;
case '*': sprintf(ret,"%d%c%d=%d",a,op,b,a*b); break;
case '/':
if(b!=0)
sprintf(ret,"%d%c%d=%g",a,op,b,a/(double)b);
else
sprintf(ret,"%d%c%d=Error",a,op,b);
break;
}
cout << ret << endl;
}
return 0;
}
