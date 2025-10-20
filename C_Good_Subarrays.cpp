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
        int n ;
        cin >> n ;
        string s ;
        cin >> s;
        int ans = 0; 
        map<int,int> freq;
        int prefix = 0; 
        freq[0] = 1; 
        for (int i = 0; i < n; i++)
            {
                prefix += (s[i] - '0');
                long long v = prefix - (i + 1);
                ans += freq[v];
                freq[v]++;
            }
        
        cout << ans << "\n";
    }


    
    
    return 0;
}
