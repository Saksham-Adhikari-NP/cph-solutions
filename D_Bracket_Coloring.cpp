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
    string s ; cin >> s ; 
    int op = 0 , cl = 0 ; 
    for( int i = 0 ; i<n ; i++) 
    {
        if(s[i] == '(') op ++ ; 
        else  cl ++ ; 
    }

    vi prefneg(n),pref(n)  ;
    pref[0] = (s[0] == '(' ? 1 : 0) ;  
        prefneg[0] = (s[0] == ')' ? 1 : 0) ;  


    for( int i = 1 ; i<n  ; i++) prefneg [i] += prefneg[i-1] + (s[i] == ')' ? 1 : 0)  ; 
    for (int i = 1 ; i < n ; i++) pref[i] += pref[i-1] +(s[i] == '('? 1 : 0) ; 

    if (cl != op){
        cout << -1 << endl ; 
        return ; 
    }

    vi ans(n) ;  ; int debt = 0  ;
    bool has1 = false, has2 = false;

    for(int i = 0 ; i<n ; i++) {
         
        int bal = pref[i] - prefneg[i] ; 

        if (bal < 0 || (bal == 0 && debt > 0)) {
            ans[i] = 2;
            has2 = true;
            if (s[i] == ')') debt++; 
            else debt--;
        } 
        else {
            ans[i] = 1;
            has1 = true;
        }
    }

    int clr = (has1 && has2) ? 2 : 1; 
    cout << clr << "\n"; 

    for(int i = 0; i < n; i++) {
        if (clr == 1) cout << 1 << " \n"[i == n - 1];
        else cout << ans[i] << " \n"[i == n - 1];
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

