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
        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        
        vector<int> a(n + 1);
        
        for (int i = 1; i <= n; i++) {
            int diff = b[i] - b[i - 1];
            int required_last = i - diff;
            
            if (required_last == 0) {
                // New value - use i itself
                a[i] = i;
            } else {
                // Reuse value from position required_last
                a[i] = a[required_last];
            }
        }
        
        for (int i = 1; i <= n; i++) {
            cout << a[i];
            if (i < n) cout << " ";
        }
        cout << endl;
    }
    return 0;
}