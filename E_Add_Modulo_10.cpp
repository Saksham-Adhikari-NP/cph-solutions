#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Max(x) (*max_element(all(x)))
#define Min(x) (*min_element(all(x)))
#define sz(x) ((int)x.size())
#define Unique(x) sort(all(x)); (x).erase(unique(all(x)),x.end())

// bitmanip shortcuts 
int hsetbit (int a ) { return (63 - __builtin_clzll(a)) ; } 
int lsetbit (int n ) { return (n & -n) ; }
int setbit (int n) { return __builtin_popcountll(n); } 

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define formul(i,a,b,k) for(ll i=a;i<b;i=i+k)

const int INF = 1e18;
const int MOD = 1e9+7; 

// Modular operations
int modpow(int x, int n, int m = MOD) {
    if (n == 0) return 1%m;
    int u = modpow(x, n/2, m);
    u = (u * 1LL * u) % m;
    if (n%2 == 1) u = (u * 1LL * x) % m;
    return u;
}
int add(int a, int b, int m = MOD) { return (a + b) % m; }
int sub(int a, int b, int m = MOD) { return (a - b + m) % m; }
int mul(int a, int b, int m = MOD) { return (a * 1LL * b) % m; }
int modinv(int a, int m = MOD) { return modpow(a, m-2, m); }
int moddiv(int a, int b, int m = MOD) { return mul(a, modinv(b,m), m); }
int norm(int x, int m = MOD) { x %= m; if(x < 0) x += m; return x; }

// nCr
const int MAXN = 1e6+5;
int fact[MAXN], invfact[MAXN];
void init_fact() {
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++) fact[i] = mul(fact[i-1], i);
    invfact[MAXN-1] = modinv(fact[MAXN-1]);
    for(int i = MAXN-2; i >= 0; i--) invfact[i] = mul(invfact[i+1], i+1);
}
int nCr(int n, int r) {
    if(r<0 || r>n) return 0;
    return mul(fact[n], mul(invfact[r], invfact[n-r]));
}

// vector io
template<typename T>
istream& operator >> (istream& s, vector<T> & v){
    for(auto &x: v) s >> x;
    return s;
}
template<typename T>
ostream& operator << (ostream& s, vector<T> & v){
    for(auto &x: v) s << x << " ";
    s << endl;
    return s;
}


void solve () 
{
    // if 2 diff mod 20 cant solve ::  
    // mod 10 some odd turn even after 1 op :: // 
    // 2 - 4 - 8 - 16 ;;after even if we do mod like : with anyeven mod 10 :: it doesnt turn into a multiple of 10 ;; like 2 - 4 - 8 - 16 ;; so rotates in cycle of 20 
    // so its like only solvable if its odd and like can be transformed into the mod10 val if there is one :: else if no mod 10 : odd smth transformed to even smth so if
    // for even it grows in circle : so like we make 2-4-8-16 -22 - 2 :: grows by 20 each cycle :: 
    // we can make it stop in the part when they have that common remainder and if that part of the cycle mod 20 is common then they can have sane elem array cause 
    // when we move to like the next place it will have same digit it would always be shifted by 20 ;; like 
    // check 6 ; 6 -> 12 ;; if the x we want it 2 :: so ;; with 8 ; it would be like 8 , 16 , 22 :: so checking they never mix together : cause their shift in 20s dont match 
    // solve here
    int n; cin >> n;
    vector<int> a(n); cin >> a ; 
    bool any = false;
    for (int i = 0; i < n; i++) {
      while (a[i] % 10 != 0 && a[i] % 10 != 2) {
        a[i] += a[i] % 10;
      }
      any |= (a[i] % 10 == 0);
    }
    if (any) {
      cout << (a == vector<int>(n, a[0]) ? "Yes" : "No") << '\n';
      return ;
    }
    int val = a[0] % 20;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      ok &= (a[i] % 20 == val);
    }
    cout << (ok ? "Yes" : "No") << '\n';

    
    

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);   // debug

    // init_fact(); // Uncomment if nCr needed

    int t;
    cin >> t;
    while (t--) {
        solve() ; 
    }

    return 0;
}

