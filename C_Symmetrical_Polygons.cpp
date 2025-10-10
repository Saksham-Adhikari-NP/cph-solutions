#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.rbegin(), a.rend()); // descending
        vector<long long> sides;
        unordered_map<long long,int> freq;
        for(auto x : a) freq[x]++;

        // collect all pairs for symmetry
        vector<long long> pairSides;
        vector<long long> leftovers;
        for(auto x : a) {
            if(freq[x] >= 2) {
                int pairs = freq[x]/2;
                for(int i=0;i<pairs;i++){
                    pairSides.push_back(x);
                    pairSides.push_back(x);
                }
                freq[x] -= pairs*2;
            }
        }
        for(auto x : a) {
            if(freq[x] > 0) leftovers.push_back(x);
        }

        // take largest leftover as middle if exists
        if(!leftovers.empty()) pairSides.push_back(leftovers[0]);

        if(pairSides.size() < 3) {
            cout << 0 << "\n";
            continue;
        }

        sort(pairSides.begin(), pairSides.end());
        long long sum = accumulate(pairSides.begin(), pairSides.end(),0LL);
        long long longest = pairSides.back();

        // check convexity, if fails remove smallest pair iteratively
        int idx = 0;
        while(longest >= sum - longest && pairSides.size()>=3){
            if(pairSides.size()>=4){
                sum -= pairSides[idx] + pairSides[idx+1];
                idx += 2;
            } else break;
            longest = pairSides.back();
        }

        if(longest >= sum - longest) cout << 0 << "\n";
        else cout << sum << "\n";
    }
}
