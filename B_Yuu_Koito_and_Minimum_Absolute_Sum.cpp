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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int start = a[0];
        int end = a[n-1];

        if (start == -1 && end == -1)
        {
            start = 0 ;
            end = 0;

        }
        else if(start == -1) {
            start = end;
        }
        else if(end == -1)
        {
            end = start;
        }

        a[0] = start;
        a[n-1] = end;
        
        for(int i = 1 ; i<n-1 ; i++)
        {
            if(a[i] == -1)
            {
                a[i] = 0;
            }
        }

        cout << llabs(a[n-1] - a[0]) << endl;
        for( int i = 0 ; i<n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    
    }

    
    
    return 0;
}
