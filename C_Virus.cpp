#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
#define endl '\n'

const int INF = 1e9;
const int MOD = 1e9 + 7;

template<typename T>
istream& operator >> (istream& s, vector<T> & v) {
    for (auto &x : v) s >> x;
    return s;
}

template<typename T>
ostream& operator << (ostream& s, vector<T> & v) {
    for (auto &x : v) {
        s << x << " ";
    }
    s << endl;
    return s;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> infected(m);
        for (int i = 0; i < m; i++) cin >> infected[i];

        sort(infected.begin(), infected.end());

        vector<int> gaps;
        for (int i = 1; i < m; i++)
            gaps.PB(infected[i] - infected[i-1] - 1);
        gaps.PB(n - infected[m-1] + infected[0] - 1);

        sort(gaps.rbegin(), gaps.rend());

        int saved = 0;
        int cnt = 0;
        for (int i = 0; i < gaps.size(); i++) {
            if (gaps[i] - 2*cnt > 0) {
                int remainder = max(1LL, gaps[i] - 2*cnt - 1);
                saved += remainder;
            }
            cnt += 2;
        }

        cout << n - saved << endl;
    }

    return 0;
}
