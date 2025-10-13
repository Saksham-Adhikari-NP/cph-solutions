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
        int n;
        cin >> n;
        vector<long long> b(n + 1);
        for (int i = 1; i <= n; ++i) cin >> b[i];

        vector<int> a(n + 1);
        int next_new = 1; 

        a[1] = 1; 
        for (int i = 2; i <= n; ++i) {
            long long diff = b[i] - b[i - 1];

            if (diff == i) {
                
                ++next_new;
                a[i] = next_new;
            } else {
               
                a[i] = a[i - diff];
            }
        }

        for (int i = 1; i <= n; ++i)
            cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}
