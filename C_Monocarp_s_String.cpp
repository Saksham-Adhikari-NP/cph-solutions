#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int total_a = 0, total_b = 0;
        for (char c : s) {
            if (c == 'a') total_a++;
            else total_b++;
        }

        if (total_a == total_b) {
            cout << 0 << '\n';
            continue;
        }
        if (total_a == 0 || total_b == 0) {
            cout << -1 << '\n';
            continue;
        }

        int diff = total_a - total_b;
        int prefix = 0, min_len = n;  // worst case: entire string
        unordered_map<int, int> first_occurrence;
        first_occurrence[0] = -1;

        for (int i = 0; i < n; i++) {
            prefix += (s[i] == 'a' ? 1 : -1);

            int target = prefix - diff;
            if (first_occurrence.count(target)) {
                min_len = min(min_len, i - first_occurrence[target]);
            }

            if (!first_occurrence.count(prefix)) {
                first_occurrence[prefix] = i;
            }
        }

        cout << (min_len == n ? -1 : min_len) << '\n';
    }
}
