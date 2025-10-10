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
        vector<int> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];
        vector<int> bb(2*n);
        for (int i = 0; i < 2*n; ++i) bb[i] = b[i % n];
        int ans = 1;
        for (int start = 0; start < n; ++start) {
            vector<int> lis;
            for (int j = start; j < start + n; ++j) {
                int x = bb[j];
                auto it = upper_bound(lis.begin(), lis.end(), x);
                if (it == lis.end()) lis.push_back(x);
                else *it = x;
            }
            ans = max(ans, (int)lis.size());
        }
        cout << ans << endl;
    }
    
    return 0;
}
