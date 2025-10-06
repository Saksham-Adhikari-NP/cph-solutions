#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = (s[i] == 'a' ? 1 : -1);

        int total = accumulate(arr.begin(), arr.end(), 0);
        if (total == 0) {
            cout << 0 << '\n';
            continue;
        }

        unordered_map<int,int> mp;
        mp[0] = -1;

        int pre = 0;
        int ans = n + 1;

        for (int i = 0; i < n; i++) {
            pre += arr[i];
            if (mp.count(pre - total))
                ans = min(ans, i - mp[pre - total]);
            if (!mp.count(pre))
                mp[pre] = i;
        }

        cout << (ans > n ? -1 : ans) << '\n';
    }
}
