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

// check if there exists x such that x ^ f(x) = n
bool exists(int n) {
    for (int x = 1; x <= (1 << 20); x++) { // 2^20 is safe for small n
        if ((x ^ reverseBinary(x)) == n) return true;
    }
    return false;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (exists(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
