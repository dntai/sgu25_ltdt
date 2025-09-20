#include <set>
#include <vector>
#include <iostream>
using namespace std;


int main() 
{
    int nx,ny,nz;
    cin>>nx;
    set<int> X,Y,Z;
    for(int i=0;i<nx;i++)
    {
        int n;
        cin>>n;
        X.insert(n);
    }
    cin>>ny;
    for(int i=0;i<ny;i++)
    {
        int n;
        cin>>n;
        Y.insert(n);
    }
    cin>>nz;
    for(int i=0;i<nz;i++)
    {
        int n;
        cin>>n;
        Z.insert(n);
    }
    vector<int>ket_qua;
    for(int x:X)
    {
        if(Y.count(x) && Z.count(x))
            ket_qua.push_back(x);
    }
    cout<<ket_qua.size()<<"\n";
        for(size_t i=0; i< ket_qua.size();i++)
        {
            cout<<ket_qua[i]<<" ";
            
        }
    cout<<"\n";
    return 0;
}
