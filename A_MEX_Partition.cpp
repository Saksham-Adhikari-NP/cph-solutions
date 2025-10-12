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
        // first pass: take one of each element
        for(int i = 0; i <= 101; i++) {
            if(freq[i] == 0) {
                mex1 = i;
                break;
            }
            freq[i]--; // remove one for first multiset
        }

        int mex2 = 0;
        // second pass: take one of remaining elements
        for(int i = 0; i <= 101; i++) {
            if(freq[i] == 0) {
                mex2 = i;
                break;
            }
        }

        cout << mex1 + mex2 << endl;
    }

    return 0;
}
