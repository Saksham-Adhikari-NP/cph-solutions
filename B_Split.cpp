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
        vector<int> a(2*n);
        map<int,int> freq;
        for(int i = 0; i < 2*n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        // Step 1: count frequency-1 elements
        int distinct_freq_one = 0;
        vector<int> rem_array;
        for(auto &[val,c] : freq) {
            if(c == 1) distinct_freq_one++;
            else rem_array.push_back(c);
        }

        int ans = distinct_freq_one; // initial contribution to f(p)+f(q)

        // Step 2: determine how many elements we still need in each array
        int p_needed, q_needed;
        if(distinct_freq_one % 2 == 0) {
            p_needed = q_needed = (2*n - distinct_freq_one) / 2;
        } else {
            p_needed = (2*n + 1 - distinct_freq_one) / 2;
            q_needed = (2*n - 1 - distinct_freq_one) / 2;
        }

        int fp = 0, fq = 0;       // contributions to f(p) and f(q)
        int p_size = 0, q_size = 0; // actual elements assigned
        int can_be_given = 0;     // extra pairs that can fill arrays

        for(int occ : rem_array) {
            if(occ % 2 == 0) {
                // 1 goes to p, rest (occ-1) even → contribute 1 odd to q
                fp++;
                fq++;
                p_size++;
                q_size += occ-1;
                can_be_given += floor((occ-1)/2);
            } else {
                // 1 goes to p, remaining even → only fp increments
                fp++;
                p_size++;
                q_size += occ-1;
                can_be_given += floor((occ-1)/2);
            }
        }

        // Step 3: fill remaining p to meet p_needed
        int needed = p_needed - p_size;
        if(needed <= can_be_given * 2) {
            ans += fp + fq;
        } else {
            ans += fp + fq - (needed - can_be_given*2)*2;
        }

        cout << ans << "\n";
    }

    return 0;
}
