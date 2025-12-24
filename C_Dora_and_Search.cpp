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

        int n ;
        cin >> n ;
        vector<int> inp (n) ;
        cin >> inp ;
        int lp = 0  , rp = n-1 ;
        int min = 1 ; int mx = n ; 
        while ( lp <= rp )
        {
          if (inp[lp] == min ) 
          {
            min ++ ; lp ++ ;
          }
          else if (inp[lp] == mx)
          {
            mx -- ; lp ++ ; 
          }
          else if (inp[rp] == min)
          {
            min ++ ; rp -- ;
          } 
          else if (inp[rp] == mx) 
          {
            mx -- ; rp -- ;
          }
          else break;
        }

        if ( lp <= rp )
        {
          cout << lp + 1 << " " << rp+1 << endl ;
        }
        else{
          cout << -1 << endl;
        }


    }
    
    return 0;
}
