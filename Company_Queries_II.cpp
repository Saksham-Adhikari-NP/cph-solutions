#include <bits/stdc++.h>
using namespace std;
#define ll long long
//ordered set; 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

#define int long long
#define endl '\n'
#define vi vector<int>  
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



int up[MAXN][30] ; 
void solve () 
{
    // solve here
    int n,q ; cin >> n >> q ; 
    Graph adj(n+1) ;
    FOR(i,2,n+1) 
    {
        int x ; cin >> x ; 
        up[i][0] = x ; 
        adj[x].pb(i) ; 

    }
    vector<int>  mplevel(n+1,0) ; // node , its level in tree // rooted in 1 
    function<void(int ,int)> level_assign = [&](int node , int level) 
    {
        trav(s ,adj[node]) 
        {
            mplevel[s] = level+1 ; 
            level_assign(s, level+1);
        }
    };

    level_assign(1,0) ; 
    // preprocessing for kth ancestor  
    FOR(k , 1 , 30) 
    {
        FOR(node , 1 , n+1) 
        {
            if(up[node][k-1] != -1 ) 
            {
                up[node][k] = up[  up[node][k-1]  ][k-1] ; 

            }
        }
    }

    function<int(int , int)> kth_ancestor = [&]( int node , int k) 
    {
        FOR(bit,0, 31) 
        {
            if(node != -1) 
            {
                if((1ll << bit) & k) 
                {
                    node = up[node][bit] ; 
                }
            }
        }

        return node ; 

    };

    while (q --) 
    {
        int a, b ; cin >> a >> b ; 
        int diff = abs(( mplevel[a] -  mplevel[b])) ;

        if( mplevel[a] > mplevel[b])  a = kth_ancestor(a,diff)  ;
        else if (mplevel[b] > mplevel[a] ) b = kth_ancestor(b,diff) ; 

        int level = mplevel[a] ; 

        if (a == b) { cout << a << endl ;  }
        else
            {
                // step 2: lift both together
                for (int k = 29; k >= 0; k--)
                {
                    if (up[a][k] != up[b][k])
                    {
                        a = up[a][k];
                        b = up[b][k];
                    }
                }

                // step 3: parent is LCA
                cout << up[a][0] << endl ; 
            }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);   // debug

    // init_fact(); // Uncomment if nCr needed
    memset(up , -1 , sizeof(up)) ; 
solve() ; 
    return 0;
}

