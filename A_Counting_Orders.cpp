#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int ans = 1;
        int j = 0;
        for(int i = 0; i < n; i++) {
            // move pointer j to the first a[j] > b[i]
            while (j < n && a[j] <= b[i]) j++;
            // number of choices for b[i] is remaining a's minus how many we already used
            int choices = j - i; 
            ans = (ans * choices) % MOD;
            if (choices <= 0) { 
                ans = 0; 
                break; 
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
