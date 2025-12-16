#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> h(n);
    for (auto &x : h) cin >> x;

    vector<int> L(n), R(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] < h[i]) st.pop();
        L[i] = st.empty() ? 1 : L[st.top()] + 1;
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && h[st.top()] < h[i]) st.pop();
        R[i] = st.empty() ? 1 : R[st.top()] + 1;
        st.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, L[i] + R[i] - 1);
    }

    cout << ans << '\n';
}
