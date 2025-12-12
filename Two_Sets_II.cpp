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

    long long S = 1LL * n * (n + 1) / 2;
    if (S % 2) {
        cout << 0;
        return 0;
    }

    int T = S / 2;

    vector<long long> dp(T + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int x = T; x >= i; x--) {
            dp[x] = (dp[x] + dp[x - i]) % MOD;
        }
    }

    long long inv2 = (MOD + 1) / 2; // since MOD is prime
    cout << (dp[T] * inv2) % MOD;
    
    return 0;
}
