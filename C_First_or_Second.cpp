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
        int n; cin >> n;
        vector <int> a(n) ; 
        cin >> a;
        vector<int> prefix(n+1) , suffix(n) ;
        for(int i = 1 ; i < n ; i ++ ) prefix[i+1] = prefix[i] + abs(a[i]) ;
        for(int i = n-1 ; i >= 1 ; i--) suffix[i-1] = suffix [i] - a[i] ;

        long long ans = suffix[0];
        for(int i = 1; i < n; i++) ans = max(ans, a[0] + prefix[i] + suffix[i]);
        cout << ans << '\n';
        }

        return 0;

    }
    
