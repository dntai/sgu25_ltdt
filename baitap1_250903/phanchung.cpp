#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int locchung(int a[], int n, int k) {
    for (int i = 0; i < n; ++i) if (a[i] == k) return 1;
    return 0;
}

int inchung(int a[], int n, int b[], int m, int chung[]) {
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (locchung(b, m, a[i]) == 1 && locchung(chung, k, a[i]) == 0) {
            chung[k++] = a[i];
        }
    }
    return k;
}

void shellSort(int a[], int n) {
    if (n <= 1) return;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = a[i], j = i;
            while (j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
    }
}

int main()
{
    int nx, ny, nz, i;
    int x[MAX], y[MAX], z[MAX], xy[MAX], chung[MAX];
    int chungxy, soluong;
    cin >> nx;
    for (int i = 0; i < nx; i++)
        cin >> x[i];
    cin >> ny;
    for (i = 0; i < ny; i++)
        cin >> y[i];
    cin >> nz;
    for (i = 0; i < nz; i++)
        cin >> z[i];
    chungxy = inchung(x, nx, y, ny, xy);
    soluong = inchung(z, nz, xy, chungxy, chung);
    cout << soluong << endl;
    shellSort(chung, soluong);
    for (i = 0; i < soluong; i++)
        cout << chung[i] << " ";
    return 0;
}