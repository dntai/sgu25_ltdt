 #include <iostream>
using namespace std;

long long dem_so_0(long long n) {
    long long count = 0;
    while (n > 0) 
    {
        count += n / 5;
        n /= 5;
    }
    return count;
}

int main() 
{
    long long n;
    while (cin >> n)
 {         
        cout << dem_so_0(n) << '\n';
    }
    return 0;
}
