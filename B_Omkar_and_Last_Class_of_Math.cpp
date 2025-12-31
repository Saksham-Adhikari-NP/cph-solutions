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
      int n ;
      cin >> n;
      int best_a = 1, best_b = n-1, min_lcm = n-1;
      for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            int d1 = i, d2 = n/i;
            for(int d : {d1, d2}){
                int a = d;
                int b = n - d;
                if(b==0) continue;
                int l = (a*b)/__gcd(a,b);
                if(l < min_lcm){
                    min_lcm = l;
                    best_a = a;
                    best_b = b;
                }
            }
        }
      }
        cout << best_a << " " << best_b << endl;


    }
    
    return 0;
}
