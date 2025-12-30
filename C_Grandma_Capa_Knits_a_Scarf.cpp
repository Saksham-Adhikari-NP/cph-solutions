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
        int n;
        string s;
        cin >> n >> s;
        int ans = n + 1;
        for (int c = 0; c < 26; c++) {
            int l = 0, r = n - 1, removed_cnt = 0;
            while (l <= r) {
                if (s[l] == s[r]) {
                    l++, r--;
                }
                else if (s[l] == char('a' + c)) {
                    removed_cnt++, l++;
                }
                else if (s[r] == char('a' + c)) {
                    removed_cnt++, r--;
                }
                else {
                    removed_cnt = n + 1;
                    break;
                }
            }
            ans = min(ans, removed_cnt);
        }
        if (ans == n + 1) ans = -1;
        cout << ans << endl;


    }
    
    return 0;
}
