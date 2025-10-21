#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    double l;
    cin >> n >> l;

    vector<double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    double max_gap = 0;
    for (int i = 0; i < n - 1; i++)
        max_gap = max(max_gap, a[i + 1] - a[i]);

    double ans = max({a[0], l - a[n - 1], max_gap / 2.0});
    cout << fixed << setprecision(10) << ans << endl;
    
    return 0;
}
