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
        
        // Create a multiset to store positions of each beauty value
        map<int, vector<int>> beautyPositions;
        for (int i = 0; i < n; i++) {
            beautyPositions[b[i]].push_back(i);
        }
        
        int maxApples = 0;
        
        // Try each starting position
        for (int start = 0; start < n; start++) {
            int count = 1;
            int lastEaten = b[start];
            int currentPos = start;
            
            // Keep searching for next apple with beauty > lastEaten
            bool found = true;
            while (found) {
                found = false;
                int bestPos = -1;
                int bestBeauty = lastEaten;
                
                // Search for the next eatable apple
                for (int lap = 0; lap < n && !found; lap++) {
                    int pos = (currentPos + 1 + lap) % n;
                    if (b[pos] > lastEaten) {
                        lastEaten = b[pos];
                        currentPos = pos;
                        count++;
                        found = true;
                        break;
                    }
                }
            }
            
            maxApples = max(maxApples, count);
        }
        
        cout << maxApples << endl;
    }
    return 0;
}