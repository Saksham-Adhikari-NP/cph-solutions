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
        cin >> n; 
        vector<int> arr (n) ; 
        cin >> arr ;

        bool replacaeble_sum = false ;
        int y , z ;

        if (is_sorted(arr.begin() , arr.end())) cout << 0 << endl ;
        else {
          for ( int i = n-1 ; i >= 1; i--)
          {
            if (arr[i-1] > arr[i]  ) 
            {
              cout << -1 << endl;
              break;
            }
            else if((arr[i-1] - arr[i]) <= arr[i-1]  )
            {
              y = i-1 ;
              z = i ;
              replacaeble_sum = true ;
              break;
            }

          }
          if ( replacaeble_sum ) 
          {
             cout << y << endl ;
             for(int i = 0 ; i < y ; i++) 
             {
              cout << i+1 << " " << y+1 << " " << z+1 << endl ;
             }

          }


        }

    }
    
    return 0;
}
