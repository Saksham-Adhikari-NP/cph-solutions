#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

bool isPowerOfTwo(int n) {
    return n && ((n & (n - 1)) == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        unsigned int n;
        cin >> n;
        if (n == 0 || !isPowerOfTwo(n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
