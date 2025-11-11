#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int gcd_array(const vector<int>& a) {
    int g = a[0];
    for (int x : a) g = gcd(g, x);
    return g;
}

int solve_case(const vector<int>& a) {
    int g = gcd_array(a);
    vector<int> Prime_100 = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
                                53,59,61,67,71,73,79,83,89,97};
    for (int p : Prime_100) {
        if (g % p != 0) return p;
    }
    return -1; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solve_case(a) << endl;
    }
    
    return 0;
}
