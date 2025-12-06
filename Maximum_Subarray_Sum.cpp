#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int max_sum = a[0];      
    int current_sum = a[0];  

    for (int i = 1; i < n; i++) {
        current_sum = max(a[i], current_sum + a[i]); 
        max_sum = max(max_sum, current_sum);        
    }

    cout << max_sum << '\n';
    return 0;
}
