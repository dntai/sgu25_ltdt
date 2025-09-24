#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void demsotancung(int n)
{
	int kq = 0;
	while (n >= 5)
	{
		kq += n / 5;
		n /= 5;
	}
	cout<< kq<<endl;

}
int main()
{
	int n;
	while (cin >> n)
	{
		 demsotancung(n);
        
	}
	return 0;
}