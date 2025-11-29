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
        int n, y, r;
        cin >> n >> y >> r;
        int suspended = min(n, r + y/2);
        cout << suspended << endl;
    }
    
    return 0;
}
