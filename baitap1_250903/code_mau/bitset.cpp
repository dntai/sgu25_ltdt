#include <bitset>
#include <iostream>


using namespace std;

int main(){
    bitset<8> b1;
    bitset<8> b2("10110011");
    bitset<8> b3(4);
    cout << "So bit 1 la " << (int)b2.count() << endl;
    cout << "So bit 0 la " << (int)b2.size() - (int)b2.count() << endl;
    b2.reset();
    b2.set(3);
    b2[0] = 1; b2[2] =1;
    b1.set();
    b1.reset(2);
    b1.flip();
    b1.flip(1);
    cout << b1.any() << endl;
    cout << b1.none() << endl;
    cout << b1.test(3) << endl;
    cout << b1.to_string() << endl; 
    cout << b1.to_ulong() << endl;
    return 0;
}