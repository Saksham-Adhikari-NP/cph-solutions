#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair

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
        string s;
        cin >> s;
        int n = s.size();

        vector<int> s_pos;
        s_pos.PB(-1);

        for (int i = 0; i < n; i++) {
            if (s[i] == 's') {
                s_pos.PB(i);
            }
        }
        s_pos.PB(n);
        int ans = 0;

        for (int i = 0; i + 1 < s_pos.size(); i++) {
            int left = s_pos[i];
            int right = s_pos[i + 1];
            int u_len = right - left - 1;
            if (u_len == 0) continue;

            int borders = 0;
            if (left != -1) borders++; 
            if (right != n) borders++;

            int max_keep = (u_len + borders - 1) / 2;
            ans += u_len - max_keep;
        }

        cout << ans << endl;
    }

    return 0;
}