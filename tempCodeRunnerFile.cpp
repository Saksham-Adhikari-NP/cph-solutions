#include <bits/stdc++.h>
using namespace std;
int main () {
     
    map<char , int> m;
    m['a'] = 1;
    m['b'] = 2;
    m['c'] = 3;
     cout<< m.begin()->first << " " << m.begin()->second << endl;
     m.erase(2);
     cout<< m.size() << endl;
        for(auto it : m){
            cout<< it.first << " " << it.second << endl;
        }
    return 0;
    
    
    }