#include <iostream>

void solve() {
    int x, y, z;
    if (!(std::cin >> x >> y >> z)) {
        return;
    }

    bool cond1 = ((x & y) | z) == z;
    bool cond2 = ((y & z) | x) == x;
    bool cond3 = ((x & z) | y) == y;

    if (cond1 && cond2 && cond3) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}