#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int lonnhat(int a[], int n) {
	int max = a[1];
	for (int i = 2; i <= n; i++)
		if (max < a[i])
			max = a[i];
	return max;
}

int xacdinhhoanvi(int a[], int n)
{
	int d = lonnhat(a, n);
	vector<int> b(n + 1,0);
	if (d != n)
		return 0;
	for (int i = 1; i <= n; i++)
		b[a[i]]++;
	for (int j = 1; j <= n; j++)
		if (b[j] != 1)
			return 0;
	return 1;
}
int main() {
	int t;
	int ans;
	int a[1001];
	cin >> t;
	for (int i = 1; i <= t; i++)
		cin >> a[i];
	ans = xacdinhhoanvi(a, t);
	if (ans == 0)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}