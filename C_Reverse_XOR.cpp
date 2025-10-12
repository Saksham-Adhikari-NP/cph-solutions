#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

bool isPowerOfTwo(unsigned long long x) {
    return x && ((x & (x - 1)) == 0);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        cin >> n;
        if (n == 0 || !isPowerOfTwo(n + 1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
