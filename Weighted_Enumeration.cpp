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

int N, K;
vi cur;

// feasibility for suffix [pos , N] to achieve sum rem
// set S = {pos, pos+1, ..., N}, unlimited repetitions
// achievable iff exists t with pos*t <= rem <= N*t  (or rem==0 with t=0)
// proof: with t coins sum range is contiguous [pos*t , N*t]
inline bool feasible(int pos, int rem){
    if(rem==0) return true;
    if(pos > N) return false;
    // pos <= N and rem>0
    // t_low = ceil(rem / N), t_high = floor(rem / pos)
    int t_low = (rem + N - 1) / N;
    int t_high = rem / pos;
    return t_low <= t_high;
}

void dfs(int idx, int rem){
    if(idx > N){
        if(rem==0){
            for(int i=1;i<=N;i++){
                if(i>1) cout << ' ';
                cout << cur[i];
            }
            cout << '\n';
        }
        return;
    }
    if(idx == N){
        // last element forced
        if(rem % N == 0){
            cur[idx] = rem / N;
            for(int i=1;i<=N;i++){
                if(i>1) cout << ' ';
                cout << cur[i];
            }
            cout << '\n';
        }
        return;
    }
    int maxV = rem / idx;
    for(int v=0; v<=maxV; ++v){
        int newRem = rem - v * idx;
        if(!feasible(idx+1, newRem)) continue;
        cur[idx] = v;
        dfs(idx+1, newRem);
    }
}

void solve()
{
    // single test case: N K
    // problem guarantees total sequences <= 3e5
    if(!(cin >> N >> K)) return;
    cur.assign(N+2, 0);
    dfs(1, K);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);   // debug

    int t = 1;
    // note: problem is single case, not t. keep t=1 to match style
    while (t--) {
        solve();
    }

    return 0;
}
