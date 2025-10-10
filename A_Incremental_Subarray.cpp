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
        
        int maxApples = 0;
        
        // Try each starting position
        for (int start = 0; start < n; start++) {
            int count = 1;
            int lastEaten = b[start];
            int pos = start;
            int stepsWithoutEating = 0;
            
            // Keep going until we complete a full cycle without eating
            while (stepsWithoutEating < n) {
                pos = (pos + 1) % n;
                if (b[pos] > lastEaten) {
                    lastEaten = b[pos];
                    count++;
                    stepsWithoutEating = 0;  // Reset counter
                } else {
                    stepsWithoutEating++;
                }
            }
            
            maxApples = max(maxApples, count);
        }
        
        cout << maxApples << endl;
    }
    return 0;
}