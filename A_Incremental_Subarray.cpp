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
                int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];
        unordered_set<int> s;
        for (int x : b) s.insert(x);
        cout << (int)s.size() << endl;


    }
    
    return 0;
}
