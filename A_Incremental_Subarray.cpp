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
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        
        int maxApples = 0;
        
        // Try each possible first apple to eat
        for (int start = 0; start < n; start++) {
            int count = 1;
            int lastEaten = b[start];
            
            // Keep going in cycles until we complete a full cycle without eating
            bool ateInLastCycle = true;
            int cycles = 0;
            while (ateInLastCycle && cycles < n) {  // Limit cycles to prevent infinite loop
                ateInLastCycle = false;
                cycles++;
                for (int i = 0; i < n; i++) {
                    int idx = (start + 1 + i) % n;
                    if (b[idx] > lastEaten) {
                        lastEaten = b[idx];
                        count++;
                        ateInLastCycle = true;
                    }
                }
            }
            
            maxApples = max(maxApples, count);
        }
        
        cout << maxApples << endl;
    }
    return 0;
}