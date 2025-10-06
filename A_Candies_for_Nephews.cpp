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

            const int r = n%3 ;
            if(r == 1)
            {
                cout << "2";
            }
            else if (r==2)
            {
                cout << "1";
            }
            else {
                cout << "0";
            }
            

    }
    
    return 0;
}
