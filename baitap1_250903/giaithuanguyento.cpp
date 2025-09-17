#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int ktsnt(int a)
{
    if (a < 2)
        return 0;
    else
        for (int i = 2; i <= sqrt(a); i++)
        {
            if (a % i == 0)
                return 0;

        }
    return 1;
}
int congthucLegendre(int n, int k)
{
    int somu = 0;
    while (n > 0)
    {
        somu += n / k;
        n = n / k;
    }

    return somu;
}
void xuatgiaithuanguyento(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (ktsnt(i)) {
            int mu = congthucLegendre(n, i);
            cout << mu << " ";
        }
    }
    cout << endl;
}
int main()
{
    int n;
    while (cin >> n)
    {
        xuatgiaithuanguyento(n);
    }
    return 0;
}

