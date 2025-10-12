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
        vector<long long> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> a(n);
        deque<int> reused;          // numbers already assigned
        int next_new = 1;           // next new number to assign

        long long last = 0;
        for (int i = 0; i < n; i++) {
            long long delta = b[i] - last;
            last = b[i];

            if (delta > 0) {
                // Assign a new number
                a[i] = next_new;
                reused.push_back(next_new); // add to reused pool
                next_new++;
            } else {
                // Assign any number from reused pool
                a[i] = reused.back(); // pick most recently assigned number
            }
        }

        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}
