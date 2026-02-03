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
#define Max(x) (*max_element(all(x)))
#define Min(x) (*min_element(all(x)))
#define sz(x) ((int)x.size())
#define Unique(x) sort(all(x)); (x).erase(unique(all(x)),x.end())

// bitmanip shortcuts 
int hsetbit (int a ) { return (63 - __builtin_clzll(a)) ; } 
int lsetbit (int n ) { return (n & -n) ; }

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


void solve () 
{
    // solve here
    int  n ; cin >> n ; 

    // for odd :: max it can be = n ;;;  n is odd ::
    /* last k ;; kl & n = n is the max possible ;;; last elem = n , n-1 ,  3rd last since it has to save 1 and use and ope   we can use 3rd elem as 1 ;; but to have k as 1 we need to make sure that the 
    k coming here has last bit set:: since the operation rem is or we can just or it with  1ll<hpow(n) - 1 ; since this is 
    OR kl == n-1 or 1(kl-1)  :: since n is odd its last bit is set so the sum num or 1 ; ;sets it back to n ;; 

    
     so to make  */
     vector<int> ans(n+1)  ; 
     unordered_map<int,int> used ; 
    if(n&1) {
        
        ans[n] = n ; ans[n-1] = n-1 ; ans[n-2] = 1 ; ans[n-3] = (1ll<< hsetbit(n) ) - 1 ; 
        FOR(i , n-3, n+1 ) 
        {
            used[ans[i]] = 1 ; 
        }
        int x = 1 ; 
        FOR(i,1,n-3) 
        {
            while(used[x])  x++ ; 
            ans[i] = x ; 
            used[x] = 1 ; 
        }
        int v = 0 ; 
        FOR(i,1,n+1) ((i&1) ? v&=ans[i] : v|=ans[i] ) ; 
        cout << v  << endl ; 
        FOR(i,1,n+1) cout << ans[i] <<" " ; 
        cout << endl ; 
    }    

    // for even we have like if its power of 2 it doesnt have any other highest bit no so we got to preserve that 
    // if not power of 2 :: 
    /* we can just have 2 units with last bit set so ;; last 3rd last or sets the highhest bit :: and keeps with n-1 keeps it ;: or with hpow(n) - 1 makes it the highest */

    // if its a power of 2 :: let the last num be n ;  ;; then to or with it we need like hpown -1 worth nums from the and operation we are about to do in n-1 ;; 
    // so let it be hpow(n) - 1 ;; so to make it lets say alls1 :: for the numbers before we have or:: since alls1 is odd :: we can just do alls1 - 1 or 1 here that would make future num 
    /*  so we can go like n , n-1 ( hpow - 1 ) , n-2  , 1 , 3  */
    else {
        if ( n == 1ll<< hsetbit(n)) {
            ans[n] = n ; ans[n-1] = n-1 ; ans[n-2] = n-2 ; ans[n-3] = 1 ;ans[n-4] = 3 ;
            FOR(i,n-4,n+1) {
                used[ans[i]] = 1 ; 
            }
        int x = 1 ; 
        FOR(i,1,n-4) 
        {
            while(used[x])  x++ ; 
            ans[i] = x ; 
            used[x] = 1 ; 
        }

        }
        else
        {
        ans[n] = ( (1ll<<hsetbit(n)) - 1) ; ans[n-1] = n ; ans [n-2] = n -1 ; 
        FOR(i,n-2,n+1) {
                used[ans[i]] = 1 ; 
            }
        int x = 1 ; 
        FOR(i,1,n-2) 
            {
                while(used[x])  x++ ; 
                ans[i] = x ; 
                used[x] = 1 ; 
            }
        }
        int v  = 0; 
        FOR(i,1,n+1) ((i&1) ? v&=ans[i] : v|=ans[i] ) ; 
        cout << v  << endl ; 
        FOR(i,1,n+1) cout << ans[i] <<" " ; 
        cout << endl ; 


    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // debug
   // freopen("input.txt", "r", stdin);   

    // init_fact(); // Uncomment if nCr needed

    int t;
    cin >> t;
    while (t--) {
        solve() ; 
    }

    return 0;
}
