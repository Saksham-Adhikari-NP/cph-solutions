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
        int n;
        cin >> n;
        int count = 0;
        while (n) {
            n = n & (n - 1); // removes the lowest set bit
            count ^= 1;       // toggle count parity
        }
        if (count == 0)
            cout << "Even\n";
        else
            cout << "Odd\n";
    }

    return 0;
}
