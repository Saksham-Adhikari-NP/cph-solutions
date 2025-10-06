#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int total_a = 0, total_b = 0;
        for (char c : s) {
            if (c == 'a') total_a++;
            else total_b++;
        }
        
        if (total_a == total_b) {
            cout << 0 << "\n";
            continue;
        }
        
        if (total_a == 0 || total_b == 0) {
            cout << -1 << "\n";
            continue;
        }
        
        int target_diff = total_a - total_b;
        int min_len = n + 1;
        
        for (int i = 0; i < n; i++) {
            int cnt_a = 0, cnt_b = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'a') cnt_a++;
                else cnt_b++;
                
                int diff = cnt_a - cnt_b;
                
                if (diff == target_diff) {
                    int len = j - i + 1;
                    int rem_a = total_a - cnt_a;
                    int rem_b = total_b - cnt_b;
                    if (rem_a == rem_b && rem_a > 0) min_len = min(min_len, len);
                }
            }
        }
        
        if (min_len == n + 1) cout << -1 << "\n";
        else cout << min_len << "\n";
    }
    
    return 0;
}
