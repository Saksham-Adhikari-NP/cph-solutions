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
    // solve here
    int n, m; 
    cin >> n >> m;
    vi a(m), b(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
    }

    int a1 = a[0], b1 = b[0];

    auto cnt = [&](int fixed_val, int   avoid_val) {
        int fail_count = 0;
        vi freq(n + 1, 0);
        
        for (int i = 0; i < m; i++) {
            if (a[i] != fixed_val && b[i] !=fixed_val) {
                fail_count++;
                freq[a[i]]++;
                freq[b[i]]++;
            }
        }
        
        if (fail_count == 0) return n - 2;

        int valid_y = 0;
        for (int i = 1; i <= n; i++) {
            if (i != fixed_val&& i != avoid_val && freq[i] == fail_count) {
                valid_y++;
            }
        }
        return valid_y;
    };

    int ans = cnt(a1,b1) + cnt(b1, a1);

    bool both_valid = true;
    for(int i = 0; i < m; i++) {
        if(a[i] != a1 && b[i] != a1 && a[i] != b1 && b[i] != b1) {
            both_valid = false;
            break;
        }
    }
    if (both_valid) ans++;

    cout << ans << "\n";
    

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);   // debug

    // init_fact(); // Uncomment if nCr needed
solve() ; 
    return 0;
}

