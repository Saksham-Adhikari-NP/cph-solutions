#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> freq(102, 0);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }

        int mex1 = 0;
        while(freq[mex1] > 0) mex1++;

        int mex2 = 0;
        while(freq[mex2] > 1) mex2++;

        cout << mex1 + mex2 << endl;
    }

    return 0;
}
