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
        int n, k, q;
        cin >> n >> k >> q;

        vector<pair<int,int>> c1, c2;
        for (int i = 0; i < q; i++) {
            int c, l, r;
            cin >> c >> l >> r;
            l--; r--; // convert to 0-based
            if (c == 1) c1.push_back({l,r});
            else c2.push_back({l,r});
        }

        vector<int> a(n, k+1);      // initialize all to k+1
        vector<bool> blocked(n,false);

        // Step 1: handle c=1
        for (auto &[l,r] : c1) {
            for (int i = l; i <= r; i++) {
                if (!blocked[i]) {
                    a[i] = k;
                    blocked[i] = true; // block for c=2
                    break; // only need one k to make min=k
                }
            }
        }

        // Step 2: handle c=2
        for (auto &[l,r] : c2) {
            vector<int> freq(k,0);
            for (int i = l; i <= r; i++) {
                if (a[i] <= k-1) freq[a[i]]++;
            }
            for (int i = l; i <= r; i++) {
                if (a[i] == k+1 && !blocked[i]) {
                    // find least used number 0..k-1
                    int x = min_element(freq.begin(), freq.end()) - freq.begin();
                    a[i] = x;
                    freq[x]++;
                }
            }
        }

        for (int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << endl;
    }
}
