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

int modpow(int x, int n, int m) {
if (n == 0) return 1%m;
int u = modpow(x,n/2,m);
u = (u*u)%m;
if (n%2 == 1) u = (u*x)%m;
return u;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m  ;
    cin >> m ;
    vector<int> n(m) , k(m) ; 
    cin >> n ;
    cin >> k;
    for (int i = 0 ; i< m ; i++) 
    {
      int ans = modpow(2 , k[i] , MOD) ; 
      cout << ans << endl ; 
    }
    return 0;
}
