#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// reverse binary without leading zeros
int reverseBinary(int x) {
    int y = 0;
    while (x) {
        y = (y << 1) | (x & 1);
        x >>= 1;
    }
    return y;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // precompute all possible x ^ f(x) for x < 65536
    unordered_set<int> possible;
    for (int x = 1; x < (1 << 16); x++) {
        possible.insert(x ^ reverseBinary(x));
    }
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (possible.count(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
