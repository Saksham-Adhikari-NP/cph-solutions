#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> desired_sizes(n);
    for (int i = 0; i < n; i++) {
        cin >> desired_sizes[i];
    }

    multiset<ll> apartment_sizes;
    for (int i = 0; i < m; i++) {
        ll size;
        cin >> size;
        apartment_sizes.insert(size);
    }

    sort(desired_sizes.begin(), desired_sizes.end());

    int matched = 0;

    for (int i = 0; i < n; i++) {
        ll desired = desired_sizes[i];
        ll min_acceptable = desired - k;
        ll max_acceptable = desired + k;

        auto it = apartment_sizes.lower_bound(min_acceptable);
        if (it != apartment_sizes.end() && *it <= max_acceptable) {
            matched++;
            apartment_sizes.erase(it);
        }
    }

    cout << matched << "\n";
}
