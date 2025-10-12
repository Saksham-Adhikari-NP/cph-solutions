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
        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        
        vector<int> a(n + 1);
        map<int, int> last_pos; // last_pos[value] = last position where this value appeared
        int next_new = 1;
        
        for (int i = 1; i <= n; i++) {
            int diff = b[i] - b[i - 1];
            int required_last = i - diff;
            
            if (required_last == 0) {
                // Need a completely new value
                a[i] = next_new;
                last_pos[next_new] = i;
                next_new++;
            } else {
                // Need to reuse value from position required_last
                a[i] = a[required_last];
                last_pos[a[i]] = i;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            cout << a[i];
            if (i < n) cout << " ";
        }
        cout << endl;
    }
    return 0;
}