#include <bits/stdc++.h>
using namespace std;

bool canDivide(const vector<int>& a, int n, int k, long long limit) {
    int parts = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + a[i] <= limit) {
            sum += a[i];
        } else {
            parts++;
            sum = a[i];
        }
    }
    return parts <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long low = *max_element(a.begin(), a.end());
    long long high = accumulate(a.begin(), a.end(), 0LL);

    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (canDivide(a, n, k, mid)) high = mid;
        else low = mid + 1;
    }

    cout << low << "\n";
}
