#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define sz(v) v.size()
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forrr(i,b,a) for(ll i=b;i>=a;i--)
#define forrrr(i,a,b,k) for(ll i=a;i<b;i=i+k)



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

      string s; 
      cin >> s; 
      int ones = count(all(s) , '0') ;
      int zeroes = count(all(s) , '1') ;

      foi(sz(s)) 
      {
         if (s[i] == '1') ones --;
         else zeroes -- ;
         
         if ( ones < 0 || zeroes < 0) 
         {
          cout << sz(s) - i << endl ;
          goto end ;
         }
      }
       cout << 0 << endl ;
       end :
    }
    
    return 0;
}
