#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long modpow(long long a, long long b, long long m) {
    if (b == 0) return 1;      
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        long long a, b;
        cin >> a >> b;
        cout << modpow(a, b, MOD) << "\n";
    }
    return 0;
}
