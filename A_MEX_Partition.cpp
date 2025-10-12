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
        vector<int> a(n), cnt(101, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        int ans = 0;
        for (int i = 0; i <= 100; i++) {
            if (cnt[i] == 0) {
                ans = i;
                break;
            }
            if (cnt[i] == 1) {
                ans = i + 1;
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
