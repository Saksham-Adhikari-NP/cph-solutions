#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// check if n is a power of two
bool isPowerOfTwo(int n) {
    return n && ((n & (n - 1)) == 0);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 0 || !isPowerOfTwo(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
