/* Cắt chuỗi theo dấu ngắt từ */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int main() {
    char s[] = "Hom nay thu hai. Hom sau thu ba, mot thu tu.";
    map<string, int> tanso;
    char *p = strtok(s," ,.");

    while(p!=NULL) {
        string sub = string(p);
        if(tanso.find(sub) == tanso.end()) // not found
            tanso[sub] = 1; // insert sub --> tanso
        else
            tanso[sub]++;
        p = strtok(NULL," ,.");
    }
    // tanso[8](("Hom", 2),("ba", 1),("hai", 1),("mot", 1),("nay", 1),("sau", 1),("thu", 3),("tu", 1))
    for(map<string,int>::iterator it = tanso.begin(); it!=tanso.end(); it++){
        string key = it->first;
        int val = it->second;
        cout << "[" << key << "] xuat hien " << val << " lan." << endl;
    }

    tanso.erase(string("Hom")); // tanso[7](("ba",1),...)

    map<string,int>::iterator jLeft = tanso.lower_bound("c"); // jLeft->first>="c"
    map<string,int>::iterator jRight = tanso.upper_bound("s"); // jLeft->first<="s"
    vector<pair<string,int>> v(jLeft,jRight);// v[4](("hai", 1),("mot", 1),("nay",1),("sau", 1)

    if (!tanso.empty())
        tanso.clear();
        
return 0;
}