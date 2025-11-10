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
        vector<int> p(n+1);
        for(int i = 1; i <= n; i++) cin >> p[i];
        string x;
        cin >> x;

        vector<int> targets;
        for(int i = 1; i <= n; i++)
            if(x[i-1] == '1') targets.push_back(i);

        if(targets.empty()) {
            cout << "0\n";
            continue;
        }

        vector<pair<int,int>> ops;
        int i = 0;
        while(i < (int)targets.size()) {
            int start = targets[i];
            int end = start;

            // Extend end minimally to cover a small valid range
            while(i+1 < (int)targets.size() && targets[i+1] == targets[i]+1) {
                i++;
                end = targets[i];
            }

            // Ensure we have at least one position strictly between l and r
            if(end - start == 1) {
                // expand r by 1 if possible
                if(end < n) end++;
                else start--;
            }

            ops.push_back({start, end});
            i++;
        }

        if((int)ops.size() > 5) {
            cout << -1 << "\n";
        } else {
            cout << ops.size() << "\n";
            for(auto &[l,r] : ops)
                cout << l << " " << r << "\n";
        }
    }
}
