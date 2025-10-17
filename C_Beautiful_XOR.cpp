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
        int a, b;
        cin >> a >> b;

        if (a == b) {
            cout << 0 << endl;
        } else {
            int x = a ^ b; // xor to b 
            if (x <= a) {
                cout << 1 << endl;
                cout << x << endl;
            } else {
                if (b <= a) {
                    cout << 2 << endl;
                    cout << a << " " << b << endl;
                } else {
                    cout << 2 << endl;
                    cout << a << " " << (a ^ b) << endl;
                }
            }
        }
    }
    
    return 0;
}
