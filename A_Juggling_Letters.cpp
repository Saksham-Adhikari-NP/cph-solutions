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
        // solve here
        int n; cin >> n;
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (char c : s) freq[c - 'a']++;
        }
        bool ok = true;
        for (int f : freq)
            if (f % n != 0) ok = false;
        cout << (ok ? "YES\n" : "NO\n");
    }


    }
    
    return 0;
}
