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
        int n , k ;
        cin >> n >> k ;
        vector<int> a(n) ; cin >> a ; 

        int s = 0, curSum = 0, x = 0;
        for(auto val : a) {
            s += val;
            curSum = max(0LL, curSum + val);
            x = max(x, curSum);
        }

        int add = 0, cur = x;
        for(int i = 0; i < k; i++) {
            add = (add + cur) % MOD;
            cur = (cur * 2) % MOD;
        }

        int ans = (s % MOD + add) % MOD;
        if(ans < 0) ans += MOD;
        cout << ans << endl;        
      }
    
    return 0;
}
