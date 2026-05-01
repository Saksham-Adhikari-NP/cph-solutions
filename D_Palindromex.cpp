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

int getmex ( vi arr , int p ) 
{
    vi pres ; int mex = 0 ;  
    pres.pb(0) ; 
         int left = p -1 ,  right = p + 1 ; 
         while (left >= 0 && right < sz(arr) &&  arr[left] == arr[right] )  
         {
            pres.pb(arr[left]) ; pres.pb(arr[right]) ; 
            left -- ; right ++ ;
         }
         sort(all(pres)) ; 
         trav(x,pres)  if ( x == mex ) mex ++  ; 
         return mex ; 
}
int getmexcent ( vi arr , int l , int r) 
{
    vi pres ; int mex = 0 ; 
    pres.pb(0) ; 
    int lin = l+1 , rin = r-1  ;
    bool ctrl = 0 ; 
    while (  lin <= rin && arr[lin] == arr[rin]   ) 
    { 
        pres.pb(arr[lin]) ; 
        pres.pb(arr[rin]) ; 
        lin ++ ; 
        rin -- ; 
    }
    if ( lin >= rin ) 
    {
         int left  = l-1 ; int right = r+1 ; 
        while (left >= 0 && right < sz(arr) &&  arr[left] == arr[right] )  
        {
                        pres.pb(arr[left]) ; pres.pb(arr[right]) ; 
                        left -- ; right ++ ;
        }

    }
    else return 1 ; 
        sort(all(pres)) ; 
        trav(x,pres)  if ( x == mex ) mex ++  ; 
        return mex ; 

}

void solve () 
{
    // solve here
    // 0-0 ''2*  -0- 
    
    int n ; cin >>n ; 
    n *= 2 ; 
    vi arr (n) ; cin >> arr ; 
    int  lz = 0 , rz = 0  , bz = 0  ; 
    int lp , rp ,cnt = 0  ; 
    FOR(i,0,n)  { 
        if(arr[i]  == 0) 
        { if(!cnt ) {lp = i; cnt ++; }  
          else {rp = i ; break ; } 
        } 
    } 

     lz = getmex(arr, lp) ;
     rz = getmex(arr, rp) ; 
     bz = getmexcent(arr,lp,rp) ; 
    cout << max({lz,rz,bz}) << endl ; 
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

