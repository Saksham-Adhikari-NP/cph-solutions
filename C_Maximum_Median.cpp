#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());
    int m = n / 2; // median index
    int low = a[m], high = a[m] + k + 1; // +1 for binary search boundary

    while (low < high) {
        int mid = (low + high) / 2;
        long long need = 0;
        for (int i = m; i < n; i++) {
            if (a[i] < mid) need += mid - a[i];
            if (need > k) break; // early stop for efficiency
        }

        if (need <= k) low = mid + 1;
        else high = mid;
    }

    cout << low - 1 << endl;
    return 0;
}
