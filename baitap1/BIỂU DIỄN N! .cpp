#include<cmath>
#include <vector>
#include <iostream>
using namespace std;

bool la_so_nguyen_to(int n)
{
    if(n<2){
    return false;
    }
    for(int i=2;i<n;i++){
        if(n%i==0)
    return false;
    }
    return true;
}
int dem_so_mu(int n, int p)
{
    int mu=0;
    int tam=n;
    while(tam>0)
    {
        tam=tam / p;
        mu=mu+tam;
    }
    return mu;
}


int main() {
    const int max_i=1000;
    int n ;
    while(cin>>n)
    {
        if(n<1||n>max_i)
            return 0;
        vector<int>a;
        for(int i=0;i<=n;i++)
        {
            If (la_so_nguyen_to(i))
            {
                a.push_back(i);
            }
        }
        for(size_t i=0;i< a.size();i++)
        {
            int mu = dem_so_mu(n,a[i]);
            cout<<mu;
            if(i<a.size()-1)
            {
                cout<< " " ;
            }
        }
       cout<<"\n";
    }
    return 0;
}
