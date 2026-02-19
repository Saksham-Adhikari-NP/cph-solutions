#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'
#define vi vector<int>  
#define f first
#define sc second
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


void solve () 
{
    // solve here
    vector<pair<int,int>> a(4), b(4);
    FOR(i,0,4) cin >> a[i].f >> a[i].sc;
    FOR(i,0,4) cin >> b[i].f >> b[i].sc;

    int xmin = INF, ymin = INF;
    int xmax = -INF, ymax = -INF;

    
    trav(p,a){
        xmin = min(xmin, p.f);
        xmax = max(xmax, p.f);
        ymin = min(ymin, p.sc);
        ymax = max(ymax, p.sc);
    }

    // check each edge of rotated square using Liang–Barsky
    FOR(i,0,4){
        int ni = (i+1)%4;

        double u1 = 0.0, u2 = 1.0;
        int dx = b[ni].f - b[i].f;
        int dy = b[ni].sc - b[i].sc;

        int p1 = -dx, q1 = b[i].f - xmin ;
        int p2 = dx , q2 = xmax - b[i].f;
        int p3 = -dy, q3 = b[i].sc - ymin;
        int p4 = dy , q4 = ymax - b[i].sc;

        vector<pair<int,int>> v = {
            {p1,q1},{p2,q2},{p3,q3},{p4,q4}
        };

        bool reject = false;

        trav(x,v){
            if(x.f == 0){
                if(x.sc < 0){
                    reject = true;
                    break;
                }
            }
            else{
                double t = x.sc / (double)x.f;
                if(x.f < 0)
                    u1 = max(u1, t);
                else
                    u2 = min(u2, t);
            }
        }

        if(!reject && u1 <= u2){
            printYN(true);
            return;
        }
    }

    printYN(false);

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);   // debug

    // init_fact(); // Uncomment if nCr needed

    int t = 1;
    // cin >> t;
    while (t--) {
        solve() ; 
    }

    return 0;
}

