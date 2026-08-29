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
const int MOD = 1e9+7; 


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
    // score = number of segments with sum % K == 0
    int n , k ; 
    cin >> n >> k ; 
    vi a(n+1 , 0) ; 
    for(int i = 1 ; i<= n ; i++) cin >> a[i] ; 

    vi pref(n+1 , 0) ; 
    for(int i = 1 ; i<= n ; i++){
        pref[i] = (pref[i-1] + a[i]) % k ; 
    }

    // best[mod] = max dp for prefix with pref == mod
    unordered_map<int,int> best ; 
    best.reserve(n*2) ; 
    best[0] = 0 ; 

    int best1_val = 0 , best1_mod = 0 ; 
    int best2_val = -INF , best2_mod = -1 ; 

    vi dp(n+1 , 0) ; 
    dp[0] = 0 ; 

    for(int i = 1 ; i<= n ; i++){
        int cur = pref[i] ; 

        int cand1 = -INF ; 
        auto it = best.find(cur) ; 
        if(it != best.end()) cand1 = it->second + 1 ; 

        int cand2 = -INF ; 
        if(best1_mod != cur) cand2 = best1_val ; 
        else cand2 = best2_val ; 

        int dpi = max(cand1 , cand2) ; 
        // dpi is at least 0 because best1 exists
        if(dpi < 0) dpi = 0 ; 
        dp[i] = dpi ; 

        auto it2 = best.find(cur) ; 
        int old = -INF ; 
        if(it2 != best.end()) old = it2->second ; 
        if(dpi > old){
            best[cur] = dpi ; 
            // maintain top two
            if(cur == best1_mod){
                best1_val = dpi ; 
            } else if(cur == best2_mod){
                best2_val = dpi ; 
                if(best2_val > best1_val){
                    swap(best1_val , best2_val) ; 
                    swap(best1_mod , best2_mod) ; 
                }
            } else {
                if(dpi > best1_val){
                    best2_val = best1_val ; 
                    best2_mod = best1_mod ; 
                    best1_val = dpi ; 
                    best1_mod = cur ; 
                } else if(dpi > best2_val){
                    best2_val = dpi ; 
                    best2_mod = cur ; 
                }
            }
        }
    }

    cout << dp[n] << '\n' ; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);   // debug

    // init_fact(); // Uncomment if nCr needed

    int t = 1 ;     while (t--) {
        solve() ; 
    }

    return 0;
}
