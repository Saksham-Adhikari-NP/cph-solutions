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

int get_red_score(const vector<int>& initial_pos, int L, long long k) {
    int P = initial_pos.size();
    if (P == 0) return 0;

    vector<int> pos = initial_pos;
    long long sim_steps = min(k, (long long)L);

    // 1. Simulate up to 2n steps
    for (int step = 0; step < sim_steps; step++) {
        vector<int> next_pos = pos;
        for (int i = 0; i < P; i++) {
            int nxt = (pos[i] + 1) % L;
            if (nxt != pos[(i + 1) % P]) {
                next_pos[i] = nxt; // Move if target spot was empty at start
            }
        }
        pos = next_pos;
    }

    // 2. Fast-forward any remaining steps by direct shift
    if (k > L) {
        long long shift = (k - L) % L;
        for (int i = 0; i < P; i++) {
            pos[i] = (pos[i] + shift) % L;
        }
    }

    // 3. Count potatoes on Blue team members (odd 0-based indices)
    int red_score = 0;
    for (int p : pos) {
        if (p % 2 == 1) red_score++;
    }
    return red_score;
}

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    string s;
    cin >> s;

    int L = 2 * n;
    int P = 0;
    for (char c : s) if (c == '1') P++;

    bool inverted = false;
    if (P > n) {
        // Dual problem: invert 0/1 and reverse string so P <= n
        inverted = true;
        for (char &c : s) c = (c == '0' ? '1' : '0');
        reverse(s.begin(), s.end());
        P = L - P;
    }

    vector<int> pos;
    for (int i = 0; i < L; i++) {
        if (s[i] == '1') pos.push_back(i);
    }

    // Evaluate scores at k and k - 1 steps
    int r1 = get_red_score(pos, L, k);
    int r2 = get_red_score(pos, L, k - 1);

    int red_score = max(r1, r2);
    int blue_score = P - red_score;

    if (inverted) swap(red_score, blue_score);

    cout << red_score << " " << blue_score << "\n";
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

