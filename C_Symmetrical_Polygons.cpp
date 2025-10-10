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
        vector<long long> group_sum(d);
        vector<int> group_sides(d);
        for(int j = 0; j < d; j++) {
            group_sum[j] = groups[j].first * (long long)groups[j].second;
            group_sides[j] = groups[j].second;
        }
        vector<long long> suffix_total(d + 1, 0);
        vector<int> suffix_num(d + 1, 0);
        for(int j = d - 1; j >= 0; j--) {
            suffix_total[j] = suffix_total[j + 1] + group_sum[j];
            suffix_num[j] = suffix_num[j + 1] + group_sides[j];
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
        vector<int> even_indices;
        for(int j = 0; j < d; j++) {
            if(groups[j].second % 2 == 0) even_indices.push_back(j);
        }
        int sz_even = even_indices.size();
        vector<long long> even_lengths(sz_even);
        for(int q = 0; q < sz_even; q++) {
            even_lengths[q] = groups[even_indices[q]].first;
        }
        vector<long long> suffix_even(sz_even + 1, 0);
        for(int q = sz_even - 1; q >= 0; q--) {
            suffix_even[q] = suffix_even[q + 1] + even_lengths[q];
        }
        long long ans = 0;
        for(int start = 0; start < d; start++) {
            long long S_full = suffix_total[start];
            int m_full = suffix_num[start];
            if(m_full < 3) continue;
            long long MX = groups[start].first;
            auto it_odd = lower_bound(odd_indices.begin(), odd_indices.end(), start);
            int p_odd = it_odd - odd_indices.begin();
            int cur_odd_n = sz_odd - p_odd;
            auto it_even = lower_bound(even_indices.begin(), even_indices.end(), start);
            int p_even = it_even - even_indices.begin();
            int cur_even_n = sz_even - p_even;
            for(int r = 0; r <= 2; r++) {
                long long this_rem = 0;
                int this_numrem = 0;
                bool possible = true;
                if(cur_odd_n >= r) {
                    int num_flip_odd = cur_odd_n - r;
                    this_rem = (num_flip_odd == 0 ? 0LL : suffix_odd[p_odd + r]);
                    this_numrem = num_flip_odd;
                } else {
                    int delta = r - cur_odd_n;
                    long long rem_odd = (cur_odd_n == 0 ? 0LL : suffix_odd[p_odd]);
                    long long rem_e = 0;
                    if(cur_even_n >= delta) {
                        rem_e = (delta == 0 ? 0LL : suffix_even[sz_even - delta]);
                    } else {
                        possible = false;
                    }
                    this_rem = rem_odd + rem_e;
                    this_numrem = cur_odd_n + delta;
                }
                if(!possible) continue;
                long long this_S = S_full - this_rem;
                int this_m = m_full - this_numrem;
                if(this_m >= 3 && this_S > 2LL * MX) {
                    ans = max(ans, this_S);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}