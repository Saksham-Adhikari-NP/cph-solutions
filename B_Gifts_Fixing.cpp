#include <bits/stdc++.h>
using namespace std;

int main() {
   

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int minA = *min_element(a.begin(), a.end());
        int minB = *min_element(b.begin(), b.end());

        int  moves = 0;
        for (int i = 0; i < n; i++) {
            moves += max(a[i] - minA, b[i] - minB);
        }
        cout << moves << "\n";
    }
    return 0;
}
