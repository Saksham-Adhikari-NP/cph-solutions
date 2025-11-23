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
         int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        unordered_map<int,int> freq;
        for (auto &x : a) freq[x]++;

        int ans = 0;
        for (auto &p : freq) {
            int x = p.first;
            int f = p.second;

            if (x == 0) {
                ans += f;
                continue;
            }

            if (f >= x) ans += (f - x);
            else ans += f; 
        }

        cout << ans << endl;

    }
    
    return 0;
}
