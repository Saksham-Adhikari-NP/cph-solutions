#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n), b(n), d(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    for (int i = 0; i < n; i++)
        d[i] = a[i] - b[i];
    
    sort(d.begin(), d.end());
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (d[i] <= 0)
        {
            int j = upper_bound(d.begin() + i + 1, d.end(), -d[i]) - d.begin();
            ans += n - j;
        } 
        else 
        {
            ans += n - i - 1;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
