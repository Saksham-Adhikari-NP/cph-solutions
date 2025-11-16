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
        string s;
        int n;
        cin>>n>>s;
        int c = 0;
        
        for(int vars = 0; vars<n; vars++)
        {
            if (s[n-1] == s[vars]) c++;
        }
        cout << n - c << endl;
}

   

    
    
    return 0;
}
