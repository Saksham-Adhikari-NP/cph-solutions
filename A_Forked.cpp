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

        int a, b;
        cin >> a >> b;

        int xK, yK, xQ, yQ;
        cin >> xK >> yK;
        cin >> xQ >> yQ;

        vector<pair<int, int>> moves;
        int dx[2] = {a, b};
        int dy[2] = {b, a};

        foi(2) {
            for (int sx : {-1, 1}) {
                for (int sy : {-1, 1}) {
                    moves.push_back({sx * dx[i], sy * dy[i]});
                }
            }
        }

        set<pair<int, int>> K, Q;

        for (auto [dxi, dyi] : moves) {
            K.insert({xK + dxi, yK + dyi});
            Q.insert({xQ + dxi, yQ + dyi});
        }

        int ans = 0;
        for (auto &p : K) {
            if (Q.count(p)) ans++;
        }

        cout << ans << '\n';

    }
    
    return 0;
}
