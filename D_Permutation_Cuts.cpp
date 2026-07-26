#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

using ll = long long ;
using vi = vector<int> ;

const int MOD = 998244353 ;

ll count_ways ( int m , int n , const vi &a ) 
{
    // 1. Left side must be non-decreasing, right side must be non-increasing
    for ( int i = 1 ; i < m - 1 ; i++ ) 
    {
        if ( a[i] > a[i+1] ) return 0 ; 
    }
    for ( int i = m ; i < n - 1 ; i++ ) 
    {
        if ( a[i] < a[i+1] ) return 0 ; 
    }

    vi forced ; 
    vi free_bounds ; 

    // Max element n sits at index m
    forced.push_back(n) ; 

    // Left side: first occurrence forces prefix max
    for ( int i = 1 ; i <= m - 1 ; i++ ) 
    {
        if ( i == 1 || a[i] > a[i-1] ) 
        {
            forced.push_back(a[i]) ; 
        } 
        else 
        {
            free_bounds.push_back(a[i]) ; 
        }
    }

    // Right side: last occurrence forces suffix max
    for ( int i = m ; i <= n - 1 ; i++ ) 
    {
        if ( i == n - 1 || a[i] > a[i+1] ) 
        {
            forced.push_back(a[i]) ; 
        } 
        else 
        {
            free_bounds.push_back(a[i]) ; 
        }
    }

    // 2. Check for duplicate forced elements
    sort(forced.begin() , forced.end()) ; 
    for ( int i = 0 ; i < (int)forced.size() - 1 ; i++ ) 
    {
        if ( forced[i] == forced[i+1] ) return 0 ; 
    }

    // 3. Find remaining elements set = {1..n} \ forced
    vi rem ; 
    int f_idx = 0 ; 
    for ( int val = 1 ; val <= n ; val++ ) 
    {
        if ( f_idx < (int)forced.size() && forced[f_idx] == val ) 
        {
            f_idx++ ; 
        } 
        else 
        {
            rem.push_back(val) ; 
        }
    }

    // 4. Fill free positions with suitable elements <= bound
    sort(free_bounds.begin() , free_bounds.end()) ; 

    ll ways = 1 ; 
    int ptr = 0 ; 
    for ( int i = 0 ; i < (int)free_bounds.size() ; i++ ) 
    {
        while ( ptr < (int)rem.size() && rem[ptr] <= free_bounds[i] ) 
        {
            ptr++ ; 
        }
        int available = ptr - i ; 
        if ( available <= 0 ) return 0 ; 
        ways = (ways * available) % MOD ; 
    }

    return ways ; 
}

void solve () 
{
    int n ; 
    cin >> n ; 

    vi a(n) ; 
    int mx = 0 ; 
    for ( int i = 1 ; i <= n - 1 ; i++ ) 
    {
        cin >> a[i] ; 
        mx = max(mx , a[i]) ; 
    }

    if ( mx >= n ) 
    {
        cout << 0 << endl ; 
        return ; 
    }

    // Find the peak range (L to R)
    int L = -1 , R = -1 ; 
    for ( int i = 1 ; i <= n - 1 ; i++ ) 
    {
        if ( a[i] == mx ) 
        {
            if ( L == -1 ) L = i ; 
            R = i ; 
        }
    }

    // Candidate max index positions m1 and m2
    int m1 = L ; 
    int m2 = R + 1 ; 

    ll ans = count_ways(m1 , n , a) ; 
    if ( m1 != m2 ) 
    {
        ans = (ans + count_ways(m2 , n , a)) % MOD ; 
    }

    cout << ans << endl ; 
}

int main () 
{
    ios_base::sync_with_stdio(false) ; 
    cin.tie(NULL) ; 

    int t ; 
    if ( cin >> t ) 
    {
        while ( t-- ) solve() ; 
    }
    return 0 ; 
}