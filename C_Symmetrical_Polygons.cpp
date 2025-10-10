#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        sort(a.rbegin(), a.rend());

        vector<pair<long long,int>> groups;
        for (int i = 0; i < n; ) {
            long long len = a[i];
            int count = 0;
            while (i < n && a[i] == len) { count++; i++; }
            groups.push_back({len, count});
        }

        int d = groups.size();
        vector<long long> suffix_sum(d+1, 0);
        vector<int> suffix_count(d+1, 0);

        for (int i = d-1; i >= 0; i--) {
            suffix_sum[i] = suffix_sum[i+1] + groups[i].first * groups[i].second;
            suffix_count[i] = suffix_count[i+1] + groups[i].second;
        }

        vector<int> odd_indices;
        for (int i = 0; i < d; i++) if (groups[i].second % 2 == 1) odd_indices.push_back(i);

        int sz_odd = odd_indices.size();
        vector<long long> odd_lengths(sz_odd);
        for (int i = 0; i < sz_odd; i++) odd_lengths[i] = groups[odd_indices[i]].first;

        vector<long long> suffix_odd(sz_odd+1, 0);
        for (int i = sz_odd-1; i >= 0; i--) suffix_odd[i] = suffix_odd[i+1] + odd_lengths[i];

        long long max_perimeter = 0;

        for (int start = 0; start < d; start++) {
            long long total_len = suffix_sum[start];
            int total_count = suffix_count[start];
            if (total_count < 3) continue;

            long long longest = groups[start].first;

            auto it = lower_bound(odd_indices.begin(), odd_indices.end(), start);
            int first_odd_pos = it - odd_indices.begin();
            int remaining_odds = sz_odd - first_odd_pos;

            long long remove_len = 0;
            int remove_count = 0;
            if (remaining_odds > 2) {
                remove_len = suffix_odd[first_odd_pos + 2];
                remove_count = remaining_odds - 2;
            }

            long long used_len = total_len - remove_len;
            int used_count = total_count - remove_count;

            if (used_count >= 3 && used_len > 2*longest) {
                max_perimeter = max(max_perimeter, used_len);
            }
        }

        cout << max_perimeter << "\n";
    }
}
