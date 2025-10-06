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
            int n ;
            cin >> n;

             int r = n%3 ;
            if(r == 1)
            {
                cout << ++r ;
            }
            else if (r==2)
            {
                cout << --r ;
            }
            else {
                cout << r;
            }
            

    }
    
    return 0;
}
