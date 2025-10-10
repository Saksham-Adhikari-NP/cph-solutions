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
        int ans = 1;
        for (int start = 0; start < n; ++start) {
            vector<int> lis;
            for (int k = 0; k < n; ++k) {
                int x = b[(start + k) % n];
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
