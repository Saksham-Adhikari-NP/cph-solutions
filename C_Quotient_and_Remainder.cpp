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
        int n, k;
        cin >> n >> k;
        vector<int> q(n), r(n);
        for (int i = 0; i < n; i++) cin >> q[i];
        for (int i = 0; i < n; i++) cin >> r[i];

        sort(r.begin() , r.end() ) ;
        sort(q.begin() , q.end() ) ; 

        int count = 0 , i = 0 , j = n-1 ;
        while (i < q.size() and j >= 0) 
        {
            if ((q[i]+1)*(r[j]+1) <= k+1)
                {
                count++;
                i++;
                j--;   
                } 
            else
            {
                j--;
            }

        }
        cout << count << endl  ;
    }
    return 0 ;

}
                