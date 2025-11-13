#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> angles(n);
    for (int i = 0; i < n; i++) cin >> angles[i];

    // try all  combination 
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {    // it shifts the 1 by i bits ; and only the ith mask bit is imp cause all the shifted bits are set to 0 so dont matter in and operation 
                sum += angles[i];
            } else {                  
                sum -= angles[i];
            }
        }
        if (sum % 360 == 0) {       
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
