#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> a(n);
    set<int> used_values;
    int next_value = 1;

    for (int i = 0; i < n; i++) {
        if (b[i] > (i == 0 ? 0 : b[i - 1])) {
            // Assign a new value if a new distinct element is introduced
            a[i] = next_value++;
            used_values.insert(a[i]);
        } else {
            // Reuse an existing value
            for (int val : used_values) {
                a[i] = val;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
