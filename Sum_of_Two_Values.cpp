#include <bits/stdc++.h>
using namespace std;
int main (){

    int n;
    int x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int, int> mp; // value -> index (1-based)

    for (int i = 0; i < n; i++) {
        int need = x - a[i];
        if (mp.count(need)) {
            cout << mp[need] << " " << i+1 << "\n";
            return 0;
        }
        mp[a[i]] = i+1;
    }

    cout << "IMPOSSIBLE\n";
}