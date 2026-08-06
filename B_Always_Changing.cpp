#include <bits/stdc++.h>
using namespace std;
#define ll long long

//ordered set; 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<pair<char, int>> blocks;
    for (char c : s) {
        if (blocks.empty() || blocks.back().first != c) {
            blocks.push_back({c, 1});
        } else {
            blocks.back().second++;
        }
    }

    int red0 = 0, red1 = 0;
    for (auto b : blocks) {
        if (b.first == '0') red0 += (b.second - 1);
        else red1 += (b.second - 1);
    }

    int k = blocks.size();
    int min_ops = 1e9;

    for (int p = 0; p <= min(2, k - 1); p++) {
        for (int s_trim = 0; s_trim <= min(2, k - 1 - p); s_trim++) {
            int c0 = red0;
            int c1 = red1;

            for (int i = 0; i < p; i++) {
                if (blocks[i].first == '0') c0++;
                else c1++;
            }

            for (int i = 0; i < s_trim; i++) {
                if (blocks[k - 1 - i].first == '0') c0++;
                else c1++;
            }

            if (abs(c0 - c1) <= 1) {
                int total_ops = red0 + red1 + p + s_trim;
                min_ops = min(min_ops, total_ops);
            }
        }
    }

    if (min_ops > n) {
        cout << -1 << "\n";
    } else {
        cout << min_ops << "\n";
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

