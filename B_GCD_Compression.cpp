#include <bits/stdc++.h>
using namespace std;
int main (){


    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(2*n);
        vector<int> odd, even;

        for (int i = 0; i < 2*n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) even.push_back(i+1);
            else odd.push_back(i+1);
        }

        // we need to discard 2 elements
        if (odd.size() % 2 == 1) {
            // discard one odd and one even
            odd.pop_back();
            even.pop_back();
        } else {
            // discard two odds (if possible) or two evens
            if (odd.size() >= 2) {
                odd.pop_back();
                odd.pop_back();
            } else {
                even.pop_back();
                even.pop_back();
            }
        }

        vector<pair<int,int>> ans;
        for (int i = 0; i+1 < odd.size(); i += 2)
            ans.push_back({odd[i], odd[i+1]});
        for (int i = 0; i+1 < even.size(); i += 2)
            ans.push_back({even[i], even[i+1]});

        for (auto &p : ans) cout << p.first << " " << p.second << "\n";
    }
}
