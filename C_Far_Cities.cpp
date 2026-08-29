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

int n;
int query_cnt;

// ask if dist(u,v) >= d
int ask(int u,int v,int d){
    if(d<=0) return 1;
    if(d>n) return 0;
    cout << "? " << u << " " << v << " " << d << endl;
    cout.flush();
    int res; 
    if(!(cin >> res)){
        exit(0);
    }
    if(res==-1) exit(0);
    query_cnt++;
    return res;
}

// get exact dist(u,v) via binary search, assumes 0<=dist<n
int get_dist(int u,int v){
    int lo=0, hi=n-1, ans=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(ask(u,v,mid)){
            ans=mid;
            lo=mid+1;
        }else hi=mid-1;
    }
    return ans;
}

// farthest from src : returns {node, dist}
pair<int,int> farthest(int src, mt19937 &rng){
    int best = src;
    int best_dist = 0;
    vector<int> cand;
    for(int i=1;i<=n;i++) if(i!=src) cand.push_back(i);
    shuffle(all(cand), rng);
    for(int v: cand){
        if(query_cnt >= 3*n) break;
        // is v farther than best ?
        if(!ask(src, v, best_dist+1)) continue;
        // v is farther, find its exact distance via exponential + binary
        // we know dist >= best_dist+1
        int lo = best_dist+1;
        int hi = lo;
        // exponential to find upper bound where dist < hi
        // we already know lo is true, try hi = lo+1,2,4,8...
        int step=1;
        int cur_hi = lo+1;
        int last_true = lo;
        bool found_false=false;
        int up = -1;
        while(cur_hi <= n-1){
            if(!ask(src, v, cur_hi)){
                up = cur_hi;
                found_false=true;
                break;
            }else{
                last_true = cur_hi;
                // increase step
                cur_hi += step;
                step <<=1;
                if(cur_hi > n) cur_hi = n;
            }
        }
        int exact;
        if(!found_false){
            // all up to n-1 true => dist = n-1, but need to binary search between lo and n-1
            // we know lo true, hi = n (false beyond range)
            int l = lo, r = n-1, ans2 = lo;
            while(l <= r){
                int mid=(l+r)/2;
                // avoid re-querying lo if lo==mid and we already know true
                // we can just query mid
                if(mid==lo){
                    // already known true
                    ans2=mid;
                    l=mid+1;
                }else{
                    if(ask(src, v, mid)){
                        ans2=mid;
                        l=mid+1;
                    }else r=mid-1;
                }
            }
            exact = ans2;
        }else{
            // we have last_true and up false, binary search between last_true+1 and up-1
            int l = last_true+1, r = up-1, ans2 = last_true;
            while(l <= r){
                int mid=(l+r)/2;
                if(ask(src, v, mid)){
                    ans2=mid;
                    l=mid+1;
                }else r=mid-1;
            }
            exact = ans2;
        }
        best = v;
        best_dist = exact;
    }
    return {best, best_dist};
}

void solve_one(){
    cin >> n;
    query_cnt=0;
    if(n==1){
        cout << "! 1 1 0" << endl;
        cout.flush();
        return;
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count() + n);
    // first farthest from 1
    auto p1 = farthest(1, rng);
    int a = p1.first;
    // second farthest from a
    auto p2 = farthest(a, rng);
    int b = p2.first;
    int d = p2.second;
    // In case we didn't find exact diameter due to query limit, fallback to get_dist
    // Ensure d is exact dist(a,b) (already is)
    cout << "! " << a << " " << b << " " << d << endl;
    cout.flush();
}

void solve () 
{
    int t;
    if(!(cin >> t)) return;
    while(t--){
        solve_one();
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
