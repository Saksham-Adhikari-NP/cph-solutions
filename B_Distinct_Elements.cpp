#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int t;cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> b(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> b[i];
        vector<int> a(n + 1, 0);
        int cur = 1;
        for (int i = 1; i <= n; i++) {
            ll d = b[i] - b[i - 1];
            ll p = i - d;
            if (p == 0) a[i] = cur++;
            else a[i] = a[(int)p];}
        for (int i = 1; i <= n; i++) {
            if (i > 1) cout << ' ';
            cout << a[i];}
        cout << '\n';}}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();}