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

        int k , x ; 
        cin >> k >> x;
        cout << (k*x + 1) << endl;

    }
    
    return 0;
}
