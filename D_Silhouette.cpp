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
int n ; cin >> n ;
    vi a(n) ; cin >> a ; 
    vi b(all(a)) ; 
    vector<pii> b_oc ; 
    int blk = 1 ; 
    sort(all(b)) ; 

    if (b[0] != 0) { cout << -1 << "\n" ; return ; }

    for(int i = 1 ; i < n ; i++) {
        if(b[i] != b[i-1]) {
            b_oc.push_back({b[i-1] , blk}) ; 
            blk = 1 ; 
        }
        else blk ++ ; 
    }
    b_oc.push_back({b[n-1] , blk}) ; 

    map<int,int> ans ;  
    int k = b_oc.size() ; 

    if(k == 1) {
        ans[0] = 1 ;
    }
    else {
        int prev = 0 ;
        for(int i = 0 ; i < k - 1 ; i++) {
            int bval = b_oc[i].first ; 
            int nxtval = b_oc[i+1].first ; 
            int occ = b_oc[i].second ; 
            if((nxtval - bval) % occ != 0) { cout << -1 << "\n" ; return ; }
            int v = (nxtval - bval) / occ ; 
            if(v <= prev) { cout << -1 << "\n" ; return ; }
            ans[bval] = v ; 
            prev = v ; 
        }
        ans[b_oc[k-1].first] = prev + 1 ; 
    }

    for(int i = 0 ; i < n ; i++) {
        a[i] = ans[a[i]] ; 
        cout << a[i] << " \n"[i == n - 1] ; 
    }

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

