#include <bits/stdc++.h>
using namespace std;

int main() {
   

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long res = k + (k - 1) / (n - 1);
        cout << res << "\n";
    }
    return 0;
}