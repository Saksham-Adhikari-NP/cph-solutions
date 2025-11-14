#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        // solve here

        int n, a; 
        cin >> n >> a;
        vector<int> v(n);
        for(int i=0;i<n;++i) cin >> v[i];

        int smaller = lower_bound(v.begin(), v.end(), a) - v.begin(); 
        int bigger = v.end() - upper_bound(v.begin(), v.end(), a); 
        if(bigger >= smaller) {
            cout << (a + 1) << endl;
        } else {
            cout << (a - 1) << endl;
        }

    }
    
    return 0;
}
