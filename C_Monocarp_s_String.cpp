#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int total_a = count(s.begin(), s.end(), 'a');
        int total_b = count(s.begin(), s.end(), 'b');

        if (total_a == total_b) {
            cout << 0 << "\n";
            continue;
        }

        if (total_a == 0 || total_b == 0 || (total_a + total_b) % 2 == 1) {
            cout << -1 << "\n";
            continue;
        }

        int target_diff = total_a - total_b;
        int min_length = n + 1;

        for (int i = 0; i < n; i++) {
            int count_a = 0, count_b = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'a') count_a++;
                else count_b++;

                int diff = count_a - count_b;
                if (diff == target_diff) {
                    min_length = min(min_length, j - i + 1);
                    break;
                }
            }
        }

        if (min_length == n + 1) cout << -1 << "\n";
        else cout << min_length << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
