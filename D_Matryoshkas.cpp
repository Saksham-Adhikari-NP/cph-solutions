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
      cin >> n ;
      vector<int> a(n) ;
      map<int,int> count ;

      set<int> distinct_num ; 
      for(int i =0 ; i<n ; i++)
      {
        cin >> a[i] ;
        distinct_num.insert(a[i]); distinct_num.insert(a[i] + 1);
        count[a[i]] ++ ;
      }
      int last_freq = 0 ;
      int ans = 0 ;
      
      for(auto num:distinct_num) 
      {
        int current_freq = count[num] ;
        ans += max(0LL,current_freq - last_freq); 
        last_freq = current_freq;
      }
      cout << ans ;
    }
    
    return 0;
}
