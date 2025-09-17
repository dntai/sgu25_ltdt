#include <bitset>
#include <iostream>

using namespace std;

int main(){
    bitset<8> b1;// 00000000
    bitset<8> b2("10110011");// 11001101
    bitset<8> b3(4);// 00100000

    cout << "So bit 1 la " << (int)b2.count() << endl; // 5
    cout << "So bit 0 la " << (int)b2.size() - (int)b2.count() << endl; // 3

    b2.reset();// b2 = 00000000
    b2.set(3); // b2 = 00010000
    b2[0] = 1; b2[2] =1; // b2 = 10110000
    b1.set(); // b1 = 11111111
    b1.reset(2); // b1 = 11011111
    b1.flip(); // b1 = 00100000
    b1.flip(1); // b1 = 01100000

    cout << b1.any() << endl; // co 1 bit 1 (true)
    cout << b1.none() << endl; // khong co bit 1 (false)
    cout << b1.test(3) << endl;// vi tri co gia tri false
    cout << b1.to_string() << endl; // "00000110"
    cout << b1.to_ulong() << endl; // 6
    
    // cac phep toan co the thuc hien:
    // and (&), or (|), xor (^), not(~), shift left (<<), shift_right(>>)

return 0;
}