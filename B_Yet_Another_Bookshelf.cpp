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
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int first = -1, last = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                if (first == -1) first = i;
                last = i;
            }
        }

        int moves = 0;
        for (int i = first; i <= last; i++)
            if (a[i] == 0) moves++;

        cout << moves << "\n";


    }
    
    return 0;
}
