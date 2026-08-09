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
    int n , k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    int len = 2 * n;
    vector<int> pos;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '1') pos.push_back(i);
    }
    
    int m = pos.size();
    if (m == 0) {
        cout << 0 << " " << 0 << "\n";
        return;
    }
    
    vector<int> final_pos(m);
    for (int i = 0; i < m; ++i) {
        int next_pos = (i + 1 < m) ? pos[i + 1] : pos[0] + len;
        int max_move = min(1LL, next_pos - pos[i] - 1);
        final_pos[i] = pos[i] + max_move;
    }
    
    int red_score = 0, blue_score = 0;
    for (int i = 0; i < m; ++i) {
        int final_idx = final_pos[i] % len;
        
        int lep_id = final_idx + 1;
        
        if (lep_id % 2 == 1) {
            blue_score++;
        } else {
            red_score++;
        }
    }
    
    cout << red_score << " " << blue_score << "\n";
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

