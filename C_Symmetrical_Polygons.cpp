#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for(auto &x : a) cin >> x;
        sort(a.rbegin(), a.rend());
        vector<pair<long long, int>> groups;
        int i = 0;
        while(i < n) {
            long long len = a[i];
            int cnt = 0;
            while(i < n && a[i] == len) { cnt++; i++; }
            groups.emplace_back(len, cnt);
        }
        int d = groups.size();
        vector<long long> suffix_total(d + 1, 0);
        vector<int> suffix_num(d + 1, 0);
        for(int j = d - 1; j >= 0; j--) {
            suffix_total[j] = suffix_total[j + 1] + groups[j].first * (long long)groups[j].second;
            suffix_num[j] = suffix_num[j + 1] + groups[j].second;
        }
        vector<int> odd_indices;
        for(int j = 0; j < d; j++) {
            if(groups[j].second % 2 == 1) odd_indices.push_back(j);
        }
        int sz_odd = odd_indices.size();
        vector<long long> odd_lengths(sz_odd);
        for(int q = 0; q < sz_odd; q++) {
            odd_lengths[q] = groups[odd_indices[q]].first;
        }
        vector<long long> suffix_odd(sz_odd + 1, 0);
        for(int q = sz_odd - 1; q >= 0; q--) {
            suffix_odd[q] = suffix_odd[q + 1] + odd_lengths[q];
        }
        long long ans = 0;
        for(int start = 0; start < d; start++) {
            long long S_full = suffix_total[start];
            int m_full = suffix_num[start];
            if(m_full < 3) continue;
            long long MX = groups[start].first;
            auto it = lower_bound(odd_indices.begin(), odd_indices.end(), start);
            int p_odd = it - odd_indices.begin();
            int cur_odd_n = sz_odd - p_odd;
            long long rem = 0;
            int numrem = 0;
            if(cur_odd_n > 2) {
                rem = suffix_odd[p_odd + 2];
                numrem = cur_odd_n - 2;
            }
            long long this_S = S_full - rem;
            int this_m = m_full - numrem;
            if(this_m >= 3 && this_S > 2LL * MX) {
                ans = max(ans, this_S);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}