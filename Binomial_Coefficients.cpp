#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 1e6;

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

    static long long fact[MAXN+1], invfact[MAXN+1];
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = fact[i-1] * i % MOD;

    invfact[MAXN] = modpow(fact[MAXN], MOD-2, MOD); // Fermat inverse
    for (int i = MAXN; i >= 1; i--) invfact[i-1] = invfact[i] * i % MOD;

    while (n--) {
        int a, b;
        cin >> a >> b;
        if (b < 0 || b > a) {
            cout << 0 << "\n";
        } else {
            long long ans = fact[a];
            ans = ans * invfact[b] % MOD;
            ans = ans * invfact[a-b] % MOD;
            cout << ans << "\n";
        }
    }
}
