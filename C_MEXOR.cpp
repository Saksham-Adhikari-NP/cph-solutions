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

inline void yno (bool t) { cout << (t ? "YES" : "NO" ) << endl; }

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
    // mex xor ever = k ;; 
    int n ; int k ; 
    cin >> n >> k ; 
    //  mex(n-1) -> n ;;;  ll; f (1- n-1-1) = s xor n ;; say k ;;; 
    // max mex of f(n-2) -> n-1 ;; lets say max  ;;;; 
    


    if(n == 1) 
    {
        if(k == 1) {
            yno(1) ; 
            cout << 0 << endl ; 
        }
        else { yno(0) ; } 
        return ; 
    }

    int K = k ^ n;
    if(K == 0)
    {
        yno(1);

        for(int i = 1; i < n; i++)
            cout << i << " ";

        cout << 0 << endl;
        return;
    }
    if(K <= n-1)
    {
        yno(1);

        for(int i = 1; i < n; i++)
        {
            if(i != K)
                cout << i << " ";
        }

        cout << 0 << " " << K << endl;
        return;
    }


    // Case 3: K > n-1
    if(hsetbit(K) > hsetbit(n-1))
    {
        yno(0);
        return;
    }


    int v = (n-1) ^ K;


    if(v <= 0 || v >= n-1)
    {
        yno(0);
        return;
    }


    yno(1);

    for(int i = 1; i < n-1; i++)
    {
        if(i != v)
            cout << i << " ";
    }

    cout << 0 << " " << v << " " << n-1 << endl;
    
}
 // 

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

