#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll w, h, n;

bool ok(ll s) {
    return (s / w) * (s / h) >= n;
}

int main() {
    cin >> w >> h >> n;

    ll upper_bound = 1;
    while (!ok(upper_bound)) upper_bound *= 2;

    ll x = -1;
    for (ll b = upper_bound; b >= 1; b /= 2) {
        while (!ok(x + b)) x += b;
    }

    cout << x + 1;
}
