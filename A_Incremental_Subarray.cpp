#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    
     if(!(cin >> t)) return 0;
    while (t--) {
        // solve here
        
         int n; cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];        
        vector<bool> seen(n+1, false); // 1 <= bi <= n
        int distinct = 0;
        for (int x : b) if (!seen[x]) { seen[x] = true; ++distinct; }
        cout << distinct << '\n';

    }
    
    return 0;
}
