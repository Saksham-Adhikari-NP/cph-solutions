#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        unordered_set<long long> a_set;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a_set.insert(a[i]);
        }

        sort(a.begin(), a.end());
        vector<bool> used(n, false);
        vector<long long> B;

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            long long b = a[i];
            bool valid = true;

            for (long long mult = b; mult <= k; mult += b) {
                if (a_set.find(mult)= = a_set.end()) {
                    valid = false;
                    break;
                }
            }

            if (!valid) continue;

            for (int j = i; j < n; j++) {
                if (!used[j] && a[j] % b == 0) used[j] = true;
            }

            B.push_back(b);
        }

        bool all_covered = all_of(used.begin(), used.end(), [](bool x){ return x; });

        if (!all_covered) {
            cout << -1 << "\n";
        } else {
            cout << B.size() << "\n";
            for (int i = 0; i < B.size(); i++) {
                if (i > 0) cout << " ";
                cout << B[i];
            }
            cout << "\n";
        }
    }
    return 0;
}
