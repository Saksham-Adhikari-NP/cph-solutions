#include <bits/stdc++.h>
using namespace std;
#define ll long long

//ordered set; 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

#define int long long
#define vi vector<int>  
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

const int MAXN = 2e5+5;
const int INF = 1e18;
const int MOD = 998244353 ; 


// vector io
template<typename T>
istream& operator >> (istream& s, vector<T>& v){ for(auto &x: v) s >> x; return s; }
template<typename T>
ostream& operator << (ostream& s, const vector<T>& v){ for(auto &x: v) s << x << ' '; return s; }

inline void printYN(bool t) { cout << (t ? "YES" : "NO" ) << endl; }

struct Edge {
    int to;
    long long weight;
};

using Graph = std::vector<std::vector<int>>;
using WeightedGraph = std::vector<std::vector<Edge>>;

 int dx[]={0,0,1,-1};
 int dy[]={1,-1,0,0};
 string ds="RLDU";
int get_dir_idx(char c) {
    if (c == 'R') return 0;
    if (c == 'L') return 1;
    if (c == 'D') return 2;
    if (c == 'U') return 3;
    return -1;
}

using pii = pair<int, int>;

void solve () 
{
    // solve here
int n; cin >> n ; 
    vi a(n + 1);
    FOR(i, 1, n + 1) cin >> a[i];

    vi inv(n + 1, 1), hprfx(n + 1, 0);
    FOR(i, 2, n + 1) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }
    FOR(i, 1, n + 1) {
        hprfx[i] = (hprfx[i - 1] + inv[i]) % MOD;
    }

    int ans = 0;

    FOR(i, 1, n + 1) {
        int l = min(i, n - i + 1);
        int r = max(i, n - i + 1);

        int w1 = l % MOD;

        int w2 = (l % MOD) * ((hprfx[r] - hprfx[l] + MOD) % MOD) % MOD;

        int sum_inv_3 = (hprfx[n] - hprfx[r] + MOD) % MOD;
        int count_3 = (n - r) % MOD;
        int w3 = (((n + 1) % MOD) * sum_inv_3 % MOD - count_3 + MOD) % MOD;

        int W_i = (w1 + w2 + w3) % MOD;
        ans = (ans + (a[i] % MOD) * W_i) % MOD;
    }

    cout << ans << endl ; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);   // debug

    // init_fact(); // Uncomment if nCr needed

solve() ; 
    return 0;
}

