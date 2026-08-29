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
    int n , k ; 
    cin >> n >> k ; 
    vi cur(n+1 , 0) ; 

    auto psbl = [&] (int pos , int rem) -> bool {
         
        if(rem == 0) return true ; 
        if(pos > n ) return false ; 
        int max_val = rem/pos ; 
        int mn_val = (rem+n-1)/ n; 
        return (max_val >= mn_val) ;
    };

    auto dfs = [&] (auto &&self , int pos , int rem) {
        if(pos == n) {
            if(rem % n == 0) 
            {
                cur[pos] = rem/n ; 
                FOR(i,1,n+1) cout<<cur[i] <<" \n"[i==n] ; 
            }
            return ; 
        }
        int max_val  = rem/pos ; 
        for(int cur_val = 0 ; cur_val<max_val+1 ; cur_val++) {
            int new_rem = rem - pos*cur_val ; 
            // if(!psbl(pos+1,new_rem)) continue; 
            cur[pos] = cur_val ; 
            self(self,pos+1 , new_rem ) ; 
        }
    };

    dfs(dfs , 1 , k) ;
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
