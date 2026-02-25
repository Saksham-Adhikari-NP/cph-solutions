#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'
#define vi vector<int>  
#define f first
#define s second
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

bool check(int n, int s, int m) {
    int curr = 0;
    // Process from MSB to LSB
    FORd(j, 0, 62) {
        int bit_s = (s >> j) & 1;
        // Shift current remainder and add the bit from s at this position
        curr = (curr << 1) | bit_s;
        
        // If this bit is available in m, we can use it in our n numbers
        if ((m >> j) & 1) {
            curr -= n;
            if (curr < 0) curr = 0;
        }
        
        // Safety cap: if curr exceeds a reasonable threshold, it's impossible 
        // to reduce it to zero later. 2e18 is safe for 64-bit logic.
        if (curr > 2e18) curr = 2e18;
    }
    return curr == 0;
}

void solve() {
ll s, m;
    if (!(cin >> s >> m)) return;

    // We use a single pass from Most Significant Bit to Least Significant Bit
    ll current_count = 0;
    ll max_needed = 0;

    for (int j = 62; j >= 0; j--) {
        // 1. THE DOUBLING RULE
        // Moving down one bit level doubles the number of pieces needed
        // (e.g., one '8' becomes two '4's)
        current_count *= 2;

        // 2. Add the bit from 's' at this level
        if ((s >> j) & 1) {
            current_count++;
        }

        // 3. If the bit is present in 'm', we must be able to "park" 
        // all current pieces into our 'n' elements.
        if ((m >> j) & 1) {
            // Your 'max needed' logic: n must be at least the current pressure
            max_needed = max(max_needed, current_count);
            
            // Your 'reset' logic: Since we found a valid bit in m, 
            // we assume these elements carry the load and we clear the pressure.
            current_count = 0;
        }
    }

    // 4. Final Verification
    // If current_count is not zero, it means the smallest bits of 's'
    // could not be satisfied by the smallest bits of 'm'.
    if (current_count > 0) {
        cout << -1 << endl;
    } else {
        cout << max_needed << endl;
    }}
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

