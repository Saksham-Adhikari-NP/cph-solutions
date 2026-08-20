#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

const int MAXN = 1414215 + 5;
const int INF = 1e18;
const int MOD = 1e9+7; 


// vector io
template<typename T>
istream& operator >> (istream& s, vector<T>& v){ for(auto &x: v) s >> x; return s; }
template<typename T>
ostream& operator << (ostream& s, const vector<T>& v){ for(auto &x: v) s << x << ' '; return s; }

inline void printYN(bool t) { cout << (t ? "YES" : "NO" ) << endl; }

vi arr(632) ; 
vi primes ; 
void solve () 
{
    // solve here
    int n ; cin >> n ; if(n == 1 ) { cout << 0 ; return ;  }
    int ans = 0 ;  
        for(int i =0 ; i<sz(primes) ; i++ ) 
        {   int cont = 0 ; 
            while( n% primes[i] == 0 ) 
            {
                n/= primes[i] ; 
                cont ++ ; 
            }
            
            ans += ((upper_bound(all(arr),cont) - 1) - arr.begin()) ;    
            if(n<2) break ; 
        }
            if (n > 1) {
        ans++;
    }


    cout << ans << endl ; 
    

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);   // debug
   arr[0] = 0 ; 
    for(int i = 1; i < 632 ; i++) 
    {
        arr[i] = arr[i-1] + i ; 

    }
vi sieve(MAXN , 1); 
    for(ll i = 2 ; i*i < MAXN  ; i++)  
    {
        if(sieve[i]) 
        {   primes.push_back(i) ; 
            for(int j = i*i ; j< MAXN ; j+= i ) 
            {
                sieve[j] = 0 ; 
            }
        }
    }

    // init_fact(); // Uncomment if nCr needed

solve() ;     return 0;
}

