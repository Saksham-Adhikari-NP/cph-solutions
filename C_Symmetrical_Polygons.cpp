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
        
        sort(a.rbegin(), a.rend()); // largest first
        vector<long long> sides;
        unordered_map<long long,int> freq;
        for(auto x : a) freq[x]++;
        
        for(auto &p : freq) {
            while(p.second >= 2) {
                sides.push_back(p.first);
                sides.push_back(p.first);
                p.second -= 2;
            }
        }
        
        long long middle = 0;
        for(auto &p : freq) {
            if(p.second == 1) {
                middle = max(middle, p.first);
            }
        }
        
        if(middle) sides.push_back(middle);
        
        if(sides.size() < 3) {
            cout << 0 << "\n";
            continue;
        }
        
        sort(sides.begin(), sides.end());
        long long sum = accumulate(sides.begin(), sides.end(), 0LL);
        long long longest = sides.back();
        if(longest >= sum - longest) {
            cout << 0 << "\n"; 
        } else {
            cout << sum << "\n"; 
        }
    }
}
