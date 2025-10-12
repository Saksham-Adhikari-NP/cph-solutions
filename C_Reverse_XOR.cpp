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
        int n;
        cin >> n;
        if (n == 0 || (n & (n - 1)) != 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
