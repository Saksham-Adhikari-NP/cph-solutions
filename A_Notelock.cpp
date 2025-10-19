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
        int n, k;
        string s;
        cin >> n >> k >> s;

        int ans = 0;
        int last_occupied = -k;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i - last_occupied >= k) {
                    ans++;
                }
                last_occupied = i;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
