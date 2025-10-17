#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        string n = bitset<64>(x).to_string();
        n.erase(0, n.find('1')); 
        if (n.empty()) n = "0";

        string ans = "NO";
        for (int i = 1; i < 64; i++) {
            if ((int)n.size() <= i) {
                string w = string(i - n.size(), '0') + n;
                bool B = equal(w.begin(), w.begin() + i/2, w.rbegin());
                if (i % 2 && w[i/2] != '0') B = false;
                if (B) ans = "YES";
            }
        }
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
// should be after 15 sec