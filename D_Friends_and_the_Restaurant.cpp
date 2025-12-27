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
        cin >> n;
        vector<int> spending (n) ;
        vector<int> budget(n) ;
        cin >> spending ;
        cin >> budget ;
        multiset<int> donor;
        multiset<int> reciever ;
        int ans = 0;
        for(int i=0 ; i<n ; i++) 
        {
          if ( spending[i] <= budget[i])
          {
            donor.insert(budget[i] - spending[i]);
             
          }
          else {
            reciever.insert(spending[i] - budget[i]);

          }
        }

        for(auto &x:reciever)
        {
          auto it = donor.lower_bound(x);
          if ( it != donor.end())
          {
            donor.erase(it);
            ans ++ ;
          }
        }

        ans +=  (donor.size() / 2);
        cout << ans << endl; 
    
      }
    return 0;

}
