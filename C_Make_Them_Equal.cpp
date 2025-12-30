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
        char target;
        string str; 

        cin >> n >> target ;
        cin >> str ; 
        bool all_eq = true ;
        for (int i = 0; i < n; i++)
         {
            if (str[i] != target) {
            all_eq = false;
            break;
         }
        }
        int ans = -1 ;
        for (int x = 1; x <= n; x++) {
            bool ok = true;
            for (int i = x; i <= n; i += x) {
                if (str[i-1] != target) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = x ;
                break;
            }
        }

        if (all_eq) cout << 0 << endl;
        else if ( str[n-1] == target && !all_eq ) cout << 1 << endl << n << endl ;
        else if ( str[n-1] != target && ans != -1 ) cout << 1 << endl << ans << endl ;
        else cout << 2 << endl << n << " " << n-1 << endl ; ;

    }
  
    return 0;
}
