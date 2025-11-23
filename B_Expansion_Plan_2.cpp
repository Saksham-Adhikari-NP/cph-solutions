#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        // solve here
    int n;
    long long x, y;
    cin >> n >> x >> y;   // <-- FIXED ORDER

    string s;
    cin >> s;


    long long abs_x = llabs(x);
    long long abs_y = llabs(y);

    long long eight = 0, four = 0;
    for (char c : s) {
        if (c == '8') eight++;
        else four++;
    }

    long long used_no_eight = min({abs_x, abs_y, eight});
    abs_x -= used_no_eight;
    abs_y -= used_no_eight;
    eight -= used_no_eight;

    long long remaining = abs_x + abs_y;

    long long available = four + eight;

    if (remaining <= available) cout << "YES"<< endl;
    else cout << "NO" << endl;

    }
    
    return 0;
}
