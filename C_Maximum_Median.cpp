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
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        sort(a.begin(), a.end());
        int m = n / 2; // median index

        // Binary search on the maximum possible median
        int low = a[m], high = a[m] + k + 1;

        while (low < high) {
            int mid = (low + high) / 2;

            // Check if we can make median >= mid
            int needed = 0;
            for (int i = m; i < n; i++) {
                if (a[i] < mid)
                    needed += (mid - a[i]);
            }

            if (needed <= k)
                low = mid + 1; // possible, try higher
            else
                high = mid;    // impossible, try lower
        }

        cout << (low - 1) << endl;
    }
    
    return 0;
}
