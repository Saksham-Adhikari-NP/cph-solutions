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
        long long n;
        cin >> n;
        unsigned long long x = n; // ensure unsigned behavior
        if (x == 0 || (x & (x - 1)) != 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
