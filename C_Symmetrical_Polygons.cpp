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

        sort(a.rbegin(), a.rend());

        vector<long long> sides;
        long long middle = 0;
        vector<bool> used(n,false);

        for(int i=0;i<n-1;i++) {
            if(!used[i] && !used[i+1] && a[i] == a[i+1]) {
                sides.push_back(a[i]);
                sides.push_back(a[i+1]);
                used[i] = used[i+1] = true;
                i++;
            }
        }

        for(int i=0;i<n;i++) {
            if(!used[i]) {
                middle = a[i];
                break;
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

        if(longest >= sum - longest) cout << 0 << "\n";
        else cout << sum << "\n";
    }
}
