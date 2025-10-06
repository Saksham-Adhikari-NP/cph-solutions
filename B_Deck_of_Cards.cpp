#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define int long long
    #define endl '\n'

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        int top = count(s.begin(), s.end(), '0');
        int bottom = count(s.begin(), s.end(), '1');
        int unknown = count(s.begin(), s.end(), '2');

        int min_top = top, max_top = top + unknown;
        int min_bottom = bottom, max_bottom = bottom + unknown;

        string res(n, '+');
        for (int i = 1; i <= n; i++) {
            if (i <= min_top || i > n - min_bottom)
                res[i-1] = '-';
            else if (i <= max_top || i > n - max_bottom)
                res[i-1] = '?';
        }
        cout << res << endl ;
    }
}
