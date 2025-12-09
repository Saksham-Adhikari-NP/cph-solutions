#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

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
    
    
     int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    if(grid[0][0] == '.') dp[0][0] = 1;

    for(int i = 0; i <n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                if(i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD ;
                if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD ;
            }
        }
    }

    cout << dp[n-1][n-1] % MOD << '\n';

    
    
    return 0;
}
