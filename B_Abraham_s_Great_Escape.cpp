#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

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

    int n, k;
    cin >> n >> k;
    k = n * n - k;
    if (k == 1) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (k > 0) {
          k -= 1;
          if (i == 0 && j == 0) cout << 'R'; else
          if (i == 0) cout << 'L';
          else cout << 'U';
        } else {
          cout << 'D';
        }
      }
      cout << '\n';
    }

    }
    
    return 0;
}
