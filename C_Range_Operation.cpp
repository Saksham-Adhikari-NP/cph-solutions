#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n+1);
        long long sum = 0 , mine =0 , best = LLONG_MIN ; 
        for( int i = 1 ; i <= n ; i++ ) 
        {
         cin >> a[i] ; 
         sum += a[i] ;    

         long long current =  1ll*i*i + i   - sum ;

         best = max( best , current - mine) ; 
         mine = min(mine , current) ;

        }
        cout << sum + best << "\n" ;
        }
    return 0 ;
}