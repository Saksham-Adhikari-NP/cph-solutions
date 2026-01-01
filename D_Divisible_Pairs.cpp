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
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        cin >> a;

        map<pair<int,int>, int> count;
        int ans = 0;

        foi(n) {
            int mod_y = a[i] % y;
            int target_x = (x - (a[i] % x)) % x;
            pair<int,int> key = {target_x, mod_y};
            if(count.count(key)) ans += count[key];

            int cur_x = a[i] % x;
            int cur_y = a[i] % y;
            count[{cur_x, cur_y}]++;
        }

        cout << ans << endl;


    }
    
    return 0;
}
