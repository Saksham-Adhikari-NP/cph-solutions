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
    
       int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    // prefix sum to calc max possible sum in any interval ;
    
    vector<int> prefix(n+1,0);
    prefix[0] = 0 ;
    for(int i = 0; i< n ; i++) prefix[i+1] = prefix[i] + a[i];
    vector<vector<int>> dp(n,vector<int>(n,0)) ; 

    for(int len = 1 ; len <= n ; len++) 
    {
        for(int l = 0 ; len+l-1 < n ; l++)
        {
            int r = l+len-1;
            int sum_lr = prefix[r+1] - prefix[l];
            if ( l == r)
            {
                dp[l][r] = a[l];

            }
            else 
            {
                dp[l][r] = max(a[l] + (sum_lr - a[l] - dp[l+1][r]) , a[r] + (sum_lr - a[r] - dp[l][r-1])) ; 
            }
        }
    }
    cout << dp[0][n-1] ; 
    
    return 0;
}
