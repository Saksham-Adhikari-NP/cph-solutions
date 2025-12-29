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
        int a, b;
        cin >> a >> b;
        
        int ans = 0;
        int cur_size = 1;
        int odd_layer = 0;
        int even_layer = 0;
        
        for (int h = 1; h <= 63; h++) {
            if (h % 2 == 1) odd_layer += cur_size;
            else even_layer += cur_size;
            
            int total = (1LL << h) - 1;
            
            if (total > a + b) break;
            
            if ((odd_layer <= a && even_layer <= b) || (odd_layer <= b && even_layer <= a)) {
                ans = h;
            }
            
            cur_size *= 2;
        }
        
        cout << ans << endl;


    }
    
    return 0;
}
