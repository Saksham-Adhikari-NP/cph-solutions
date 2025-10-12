#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> a(n);
    int b_prev = 0;
    int unused_val_provider = n; 
    for (int i = 0; i < n; ++i) {
        int b_curr = b[i];
        int delta = b_curr - b_prev;

        
        int p_1_based = (i + 1) - delta;

        if (p_1_based == 0) {
            // This means a[i] must be a new value.
            a[i] = unused_val_provider;
            unused_val_provider--;
        } else {
           
            a[i] = a[p_1_based - 1];
        }

        b_prev = b_curr;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}