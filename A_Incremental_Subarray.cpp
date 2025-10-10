#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    // We use a std::set to store only the unique beauty values.
    // IMPORTANT: This set must be created fresh for each test case.
    // By declaring it here, it's re-created every time solve() is called.
    set<int> unique_beauties;

    // This loop MUST run 'n' times to read all the apple beauties.
    // This is the most likely place where an error might be.
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        unique_beauties.insert(b);
    }

    // The size of the set is the number of distinct beauties, which is our answer.
    cout << unique_beauties.size() << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        // Putting the logic in a separate function like this is clean
        // and helps avoid mistakes like declaring variables outside the loop.
        solve();
    }
    
    return 0;
}