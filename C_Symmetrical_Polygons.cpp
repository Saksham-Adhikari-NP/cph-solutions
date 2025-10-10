#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        sort(a.begin(), a.end()); // ascending

        vector<long long> pairs; // store symmetric pairs
        long long middle = 0;

        for(int i=n-1;i>0;i--) {
            if(a[i] == a[i-1]) {
                pairs.push_back(a[i]);
                pairs.push_back(a[i-1]);
                i--; // skip used pair
            }
        }

        // check for largest leftover as middle
        for(int i=n-1;i>=0;i--) {
            if(i==0 || a[i] != a[i-1]) {
                bool used = false;
                for(auto x : pairs) {
                    if(x == a[i]) { used = true; break; }
                }
                if(!used) {
                    middle = a[i];
                    break;
                }
            }
        }

        if(middle) pairs.push_back(middle);
        if(pairs.size() < 3) {
            cout << 0 << "\n";
            continue;
        }

        sort(pairs.begin(), pairs.end());
        long long sum = accumulate(pairs.begin(), pairs.end(), 0LL);
        long long longest = pairs.back();

        if(longest >= sum - longest) cout << 0 << "\n";
        else cout << sum << "\n";
    }
}
