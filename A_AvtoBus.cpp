#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair

const int INF = 1e9;
const int MOD = 1e9+7; 

template<typename T>
istream& operator >> (istream& s, vector<T> & v){
  for(auto &x: v)
    s >> x;
  return s;
}
template<typename T>
ostream& operator << (ostream& s, vector<T> & v){
  for(auto &x: v){
    s << x << " ";
  }
  s << endl;
  return s;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        // solve here
        int tires ;
        cin >> tires ;
        int min , max ;
        max = tires / 4 ;
        if ( tires % 6 == 0 )  min = tires / 6 ;
        else if ( tires % 6 == 4 ) min = (tires - 4) / 6 + 1 ;
        else if ( tires % 6 == 2 ) min = (tires-8) / 6 + 2 ; 
        if (min > max || ( tires % 2 || tires < 4)) cout << -1 << endl ;
        else {
          cout << min << " " << max << endl;
        }


    }
    
    return 0;
}
