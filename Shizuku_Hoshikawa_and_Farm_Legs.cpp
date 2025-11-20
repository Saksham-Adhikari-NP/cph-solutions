#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        // solve here
    int n;
     cin >> n;
     if(n%2 == 0) 
     {
        cout << n/4 + 1<< endl;

     }       
     else{
         cout << 0<<endl ;
        
     }

    }
    
    return 0;
}
