#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> b(n + 1);
        b[0] = 0;
        for (int i = 1; i <= n; ++i) cin >> b[i];

        vector<int> res;
        res.reserve(n);

        for (int i = 0; i < n; ++i) {
            long long diff = b[i + 1] - b[i];
            if (i - diff >= 0)
                res.push_back(res[i - diff]);
            else
                res.push_back(i + 1);
        }

        for (int x : res) cout << x << " ";
        cout << endl;
    }

    return 0;
}
