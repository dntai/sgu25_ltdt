#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int timboba(string& day)
{
    map<string, int> kitu;
    int nhieunhat = 0;
    for (int i = 0; i <= day.length() - 3; i++)
    {
        string tachday = day.substr(i, 3);
        kitu[tachday]++;
        if (nhieunhat < kitu[tachday])
            nhieunhat = kitu[tachday];

    }
    return nhieunhat;

}
int main() {
    int T;
    cin >> T;
    vector<string> nhap(T);
    for (int i = 0; i < T; i++)
    {
        cin >> nhap[i];
    }
    for (int j = 0; j < T; j++)
        cout << timboba(nhap[j]) << endl;
    return 0;
}