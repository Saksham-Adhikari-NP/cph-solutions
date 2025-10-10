#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    
    set<int> unique_beauties;
    
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        unique_beauties.insert(b);
    }
    
    cout << unique_beauties.size() << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}