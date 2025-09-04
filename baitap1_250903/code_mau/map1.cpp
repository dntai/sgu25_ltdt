#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<string>

using namespace std;
int main(){
    char s[]="Hom nay thu hai. Hom sau thu ba, mot thu tu.";
    map<string,int>tanso;
    char *p=strtok(s," ,.");
    while(p!=NULL){
        string sub=string(p);
        if (tanso.find(sub)==tanso.end())
            tanso[sub]=1;
        else
            tanso[sub]++;
        p=strtok(NULL," ,.");
    }
    for(map<string,int>::iterator it=tanso.begin();it!=tanso.end();it++){
        string key=it->first;
        int val=it->second;
        cout<< "["<<key<<"]"<<" xuat hien "<<val<<" lan"<<endl;
    }
    tanso.erase(string("Hom"));
    map<string,int>::iterator jLeft = tanso.lower_bound("c");
    map<string,int>::iterator jRight = tanso.upper_bound("s");
    vector<pair<string,int>>v(jLeft,jRight);
    if (!tanso.empty())
        tanso.clear();
    return 0;
}