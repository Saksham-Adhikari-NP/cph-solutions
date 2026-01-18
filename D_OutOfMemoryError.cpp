#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(v) v.size()

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define formul(i,a,b,k) for(ll i=a;i<b;i=i+k)

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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);   // debug

    // init_fact(); // Uncomment if nCr needed

    int t;
    cin >> t;
    while (t--) {
        // solve here
        int n ;
        cin >>  n ;
        string s ;
        cin >> s ;
        bool seen_one = false;
        bool zero_seq = false;
        int zero_bbl = 0;
        int zero_blocks = 0;
        int first_one = -1;

        FOR(i,0,n) {
            if (!seen_one) {
                if (s[i] == '1') {
                    seen_one = true;
                    first_one = i;
                }
            } else {
                if (s[i] == '0') {
                    if ( zero_seq) zero_blocks ++ ; 

                    if (!zero_seq) {
                        zero_blocks++;
                        zero_bbl ++ ; 
                        zero_seq = true;
                    }
                } else  zero_seq = false;
                
            }
        }

        if (!seen_one || zero_blocks % 2 == 0 || zero_bbl > 1) 
        {
            cout << "Bob" << endl;
            continue;
        }

        cout << "Alice" << endl ;
        cout << 2 <<endl;

        int l = first_one+1;
        {
            cout << l << " " << l+1;
        }
        cout << endl;
    }

    return 0;
}

