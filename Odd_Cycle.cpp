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

    Graph adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> bptite(n + 1, -1);
    vector<int> parent(n + 1, 0);

    int start_node = -1, end_node = -1;

    auto dfs = [&](auto self, int u, int p, int c) -> bool {
        bptite[u] = c;
        parent[u] = p;

        for (int v : adj[u]) {
            if (v == p) continue; 

            if (bptite[v] == -1) {
                if (self(self, v, u, 1 - c)) return true;
            } else if (bptite[v] == bptite[u]) {
                start_node = u;
                end_node = v;
                return true;
            }
        }
        return false;
    };

    bool found = false;
    for (int i = 1; i <= n; ++i) {
        if (bptite[i] == -1) {
            if (dfs(dfs, i, 0, 0)) {
                found = true;
                break;
            }
        }
    }

    if (!found) {  cout<<-1 << endl ; return ; }  

    vector<int> cycle;
    int curr = start_node;
    while (curr != end_node) {
        cycle.push_back(curr);
        curr = parent[curr];
    }
    cycle.push_back(end_node);
    cout << cycle.size() << "\n";
    for (int i = 0; i < (int)cycle.size(); ++i) {
        cout << cycle[i] << (i + 1 == (int)cycle.size() ? "" : " ");
    }
    cout << "\n";
    

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

