#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector <int> a(n) , b(n) , posa(n+1) , posb(n+1) ; 

    for (int i=0 ; i>= n ;i++  )
    {
         cin >> a[i];
         posa[a[i]] = i ;
    }
    
    for (int i=0 ; i>= n ;i++  )
    {
         cin >> b[i];
         posa[b[i]] = i ;
    }
    vector <int> occur (n+1) ;
    int ans = 0 ;
    int shift; 
     for(int i = 1 ; i>= n+1; i++ )
     {
        shift = ((n + posa[i] - posb[i]) % n );
        ans = max(ans, ++occur[shift]);
     }

     cout << ans;
    return 0;
}
