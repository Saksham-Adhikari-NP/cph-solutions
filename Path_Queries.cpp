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
    struct Fenwick 
    {
        int n ; 
        vi bit ; 

        Fenwick(int sz) 
        {
            n = sz ; 
            bit.assign(n+1,0) ; 
        }

        void add(int idx , int delta) 
        {
            while(idx <= n) 
            {
                bit[idx] += delta ;
                idx += (idx &-idx) ; 
            }
        }

        int sum(int idx) 
        {   int ans = 0 ; 
            while(idx>= 1) 
            {
                ans += bit[idx] ; 
                idx -= (idx&-idx) ; 
            }
            return ans ; 
        }

    }; 

void solve () 
{
    // solve here
    int n , q ; 
    cin >> n >> q ; 

    Graph adj(n+1) ; 

    vi value(n+1) ; 
    for(int i = 1 ; i<= n ; i++) cin >> value[i] ; 

    for(int i = 1 ; i<= n-1 ; i++) 
    {
        int a ,b ; 
        cin >> a >> b ;

        adj[a].push_back(b) ;
        adj[b].push_back(a) ; 

    }  ;  

    vi tin(n+1) , tout(n+1); 
    int timer = 0 ; 
    vi dist_from_root(n+1,0) ; 
    
    auto dfs =[&](auto &&self, int node , int parent , int curr_val) -> void {

        tin[node] = ++timer ; 
        dist_from_root[node] = curr_val + value[node] ; 

        for(auto child : adj[node]) {
            if(child == parent) continue; 
            self(self , child ,node, dist_from_root[node]) ; 
        }

        tout[node] = timer ; 

    };

    dfs(dfs,1,-1,0); 

    Fenwick tree(n+2) ; 
    while(q--) 
    {
        int x ; cin >> x ; 

        if(x == 1) {

            int node ,  new_val ; 
            cin >> node >> new_val ;

            int delta = new_val - value[node] ; 
            value[node] = new_val ; 

            tree.add(tin[node] , delta) ;

            if(tout[node] + 1 <= n) {
                tree.add(tout[node]+1, -delta) ; 
            }
        }
        else {
            int node ; 
            cin >> node ; 

            cout << dist_from_root[node]  + tree.sum(tin[node]) << endl  ; 
        }
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);   // debug

    // init_fact(); // Uncomment if nCr needed

solve() ; 

    return 0;
}

