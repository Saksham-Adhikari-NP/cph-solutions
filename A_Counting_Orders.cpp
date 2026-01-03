#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define sz(v) v.size()
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forrr(i,b,a) for(ll i=b;i>=a;i--)
#define forrrr(i,a,b,k) for(ll i=a;i<b;i=i+k)

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
    forr(i,1,MAXN) fact[i] = mul(fact[i-1], i);
    invfact[MAXN-1] = modinv(fact[MAXN-1]);
    forrrr(i,MAXN-2,0,1) invfact[i] = mul(invfact[i+1], i+1);
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

    // init_fact(); // Uncomment if nCr needed

    int t;
    cin >> t;
    while (t--) {
        // solve here
        int n;
        cin >> n ;
        vector<int> a(n) , b(n) ;
        cin >> a >> b ;
        sort(all(a) ) ;
        sort(all(b)) ;
        int ans = 1 ;

        forrr(i , n-1 , 0) 
        {
            auto count = a.end() - upper_bound(all(a) , b[i] ) ;
            int choices = count-(  n - i - 1 )  ;

            if ( choices <= 0 ) 
            {
                ans = 0 ;
                break ;
            }
            ans = mul( ans , choices) ; 
        }
        cout << ans << endl;;

    }

    return 0;
}

