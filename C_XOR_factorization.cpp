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

        int n , k;
        cin >> n >> k;
        int a = 0 , b = 0 , count_ones = 0 ; 
        
        for (int i = 62; i >= 0; i--) {
        int ni = (n >> i) & 1LL;
        if ( ni == 1LL)
        {
          if (count_ones >= 2LL )
          {
              a |= (1LL << i);
            
          }
          else if ( count_ones == 0LL )
          {
              a |= (1LL << i) ; 
              ++count_ones  ; 
          }
          else if ( count_ones == 1LL)
          {
            b |= (1LL << i) ; 
            ++count_ones ;
          }


        }
        if(ni == 0)
        {
          if (count_ones >= 2)
          {
              b |= (1LL << i) ; 
              a |= (1LL << i) ; 

          }

        }
      }


        if ( k == 1) cout << n ;
        else if (k % 2 == 0)
        {
          for (int i =0 ; i< k ; i++ )
          {
            if ( i == 0 ) cout << a << " ";
            else if (i == 1 ) cout << b << " ";
            else cout << n << " ";
          }

        }
        else {
          for (int i = 0 ; i< k ; i++ )
          {
            cout << n << " ";
          }
        }
        cout << endl;
    }
    
    return 0;
}
