#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair

const int INF = 1e9;
const int mod = 1e9+7; 

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
    vector<vector<int>> dp(1000002 , vector<int>(2,0));
    dp[1][0] = 1, dp[1][1] = 1;
    for(int i = 1; i < 1000000; ++i)
      {
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        dp[i+1][0] += 2*dp[i][0];
        dp[i+1][1] += dp[i][0];
        dp[i+1][0] += dp[i][1];
        dp[i+1][1] += 4*dp[i][1];
      }


    int t;
    cin >> t;
    while (t--) {
        // solve here
      int n ;
      cin >> n ;
      int ans = dp[n][0] + dp[n][1] ;
      cout << ans%mod<<endl;

    }
    
    return 0;
}
