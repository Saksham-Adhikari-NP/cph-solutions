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
        int n, m; cin >> n >> m;

    vi cnt(n + 1, 0);  vector<vi> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cnt[a]++;
        adj[a].push_back(b);
    }

    auto better = [&](int a, int b) -> bool {
        if (b == -1) return true;
        if (cnt[a] != cnt[b]) return cnt[a] > cnt[b];
        return a < b;
    };

    int first = -1, second = -1;

    for (int i = 1; i < n+1; i++) {
        if (better(i, first)) {
            second = first;
            first = i;
        } else if (better(i, second)) {
            second = i;
        }
    }

        vi add(n + 1, 0);

    for (int i = 1; i < n+1; i++) {
        int winner = (first == i ? second : first);
        int bst = cnt[winner];

        for (auto x : adj[i]) {
            add[x]++;

            int votes = cnt[x] + add[x];

            if (votes > bst || (votes == bst && x < winner)) {
                bst = votes;
                winner = x;
            }
        }

        cout << winner << endl;
        for(auto x:adj[i]) add[x] = 0 ; 

    }


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);   // debug

    // init_fact(); // Uncomment if nCr needed

    {
        solve() ; 
    }

    return 0;
}

