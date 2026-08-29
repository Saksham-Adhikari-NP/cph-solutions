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
    int n , m ; 
    cin >> n >> m ; 
    vi cnt(m+1 , 0) ; 
    for(int i = 0 ; i < n ; i++){
        int a ; cin >> a ; 
        cnt[a]++ ; 
    }

    // pref[i] = carrots  <= i
    vi pref(m+1 , 0) ; 
    for(int i = 1 ; i<= m ; i++) pref[i] = pref[i-1] + cnt[i] ; 
    pref[0] = cnt[0] ; 

    // sumFloor[L] = sum floor(a / L)
    vi sumFloor(m+2 , 0) ; 
    for(int L = 1 ; L<= m ; L++){
        int total = 0 ; 
        for(int q = 1 , lo = L ; lo <= m ; q++ , lo += L){
            int hi = min(lo + L -1 , m) ; 
            int c = pref[hi] - (lo-1 >=0 ? pref[lo-1] : 0) ; 
            total += q * c ; 
        }
        sumFloor[L] = total ; 
    }

    // suffix max of sumFloor
    vi sufMax(m+3 , 0) ; 
    for(int i = m ; i>= 1 ; i--) sufMax[i] = max(sufMax[i+1] , sumFloor[i]) ; 

    int totalSum = sumFloor[1] ; // sum a_i
    vi ans(m+1 , 0) ; 

    int K0 = hsetbit(m); 
    // while((1LL<< (K0+1)) <= 2*m) K0++ ; 

    for(int k = 1 ; k<= K0 ; k++){
        int pow2 = 1LL<<k ; 
        int thr = m / pow2 ; //  thr ->  completely contributes if less than this ;; 
        int best = 0 ; 

        // candidateB : L <= thr
        for(int L = 1 ; L<= thr ; L++){
            int X = L * pow2 ; 
            // sum_small = sum_{a <= X} floor(a / L)
            int sum_small = 0 ; 
            for(int q = 1 ; q<= pow2 ; q++){
                int lo = q * L ; 
                int hi = lo + L-1  ; 
                if(hi > X) hi = X ; 
                if(lo > X) break ; 
                int c = pref[hi] - (lo-1 >=0 ? pref[lo-1] : 0) ; 
                sum_small += q * c ; 
            }
            int cnt_big = n - pref[X] ; 
            int cur = sum_small + cnt_big * (pow2 - 1) ; 
            if(cur > best) best = cur ; 
        }
        ans[k] = best ; 
    }
    for(int k = K0+1 ; k<= m ; k++) ans[k] = totalSum ; 

    for(int k = 1 ; k<= m ; k++){
        if(k>1) cout << ' ' ; 
        cout << ans[k] ; 
    }
    cout << '\n' ; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);   // debug

    // init_fact(); // Uncomment if nCr needed

    int t ; 
    cin >> t ; 
    while(t--) solve() ; 

    return 0;
}
