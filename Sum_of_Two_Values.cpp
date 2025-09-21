#include <bits/stdc++.h>
using namespace std;
int main (){

    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<long long, int> mp; // value -> index (1-based)

    for (int i = 0; i < n; i++) {
        long long need = x - a[i];
        if (mp.count(need)) {
            cout << mp[need] << " " << i+1 << "\n";
            return 0;
        }
        mp[a[i]] = i+1;
    }

    cout << "IMPOSSIBLE\n";
}