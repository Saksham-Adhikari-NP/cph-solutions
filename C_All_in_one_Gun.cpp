#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'
#define vi vector<int>  
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
#define Sum(x) (accumulate(all(x), 0LL))
#define sz(x) ((int)x.size())
#define Unique(x) sort(all(x)); (x).erase(unique(all(x)),x.end())

// bitmanip shortcuts 
int hsetbit (int a ) { return (63 - __builtin_clzll(a)) ; } 
int lsetbit (int n ) { return (n & -n) ; }
int setbit (int n) { return __builtin_popcountll(n); } 


#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define trav(a,x) for (auto& a : x)

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
inline void printYN(bool t) { cout << (t ? "YES" : "NO" ) << endl; }


void solve () 
{

    // since the enemy has some health ;; if its greater than the total damage bullet deals ;; 
    //then we do like enemy health / sum of total bullets ;; 
    // then the only the last part of magazine matters l;;so then remainder health == =health mod sum of bullets ;
    //; then to get the min time to kill it ;; at first we prepare a min pref array ;; and max pref arr and sum pref arr ;; then sum pref arr ;; then for each index we do sum - min elem till that pref + max elem in that pref ::
     //then if the sum till that pref > = remainder health taht pref is the ans is it the correct way 
    // total time = fullcylce * reload + optimal time in last seq 

    // solve here
    int n, h, k;
    cin >> n >> h >> k;
    vi a(n);
    int sum_a = 0;
    FOR(i, 0, n) {
        cin >> a[i];
        sum_a += a[i];
    }

    // h can be direct multiple 
    int R = (h - 1) / sum_a;
    int h_rem = h - (R * sum_a);

    vi pref_sum(n + 1, 0);
    vi pref_min(n + 1, INF);
    vi suff_max(n + 2, -INF);

    FOR(i, 0, n) {
        pref_sum[i + 1] = pref_sum[i] + a[i];
        pref_min[i + 1] = min(pref_min[i], a[i]);
    }
    FORd(i, 0, n) {
        suff_max[i + 1] = max(suff_max[i + 2], a[i]);
    }

    int best_m = n;
    FOR(m, 1, n + 1) {
        // swapping decreases the damage 
        if (pref_sum[m] >= h_rem) {
            best_m = min(best_m, m);
            break; 
        }

        if (m < n) {
            int potential_sum = pref_sum[m] - pref_min[m] + suff_max[m + 1];
            if (potential_sum >= h_rem) {
                best_m = min(best_m, m);
                break;
            }
        }
    }

    int ans = R * (n + k) + best_m;
    cout << ans << endl;
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

