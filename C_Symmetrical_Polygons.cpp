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

        vector<long long> pairs;
        vector<long long> leftover;

        for (int i = 0; i < n; ) {
            long long len = a[i];
            int count = 0;
            while (i < n && a[i] == len) { count++; i++; }
            int numPairs = count / 2;
            for (int j = 0; j < numPairs * 2; j++) pairs.push_back(len);
            if (count % 2 == 1) leftover.push_back(len);
        }

        sort(leftover.rbegin(), leftover.rend());
        if (!leftover.empty()) pairs.push_back(leftover[0]);

        if (pairs.size() < 3) {
            cout << 0 << "\n";
            continue;
        }

        sort(pairs.begin(), pairs.end());
        long long sum = accumulate(pairs.begin(), pairs.end(), 0LL);
        long long longest = pairs.back();

        if (longest >= sum - longest) cout << 0 << "\n";
        else cout << sum << "\n";
    }
}
