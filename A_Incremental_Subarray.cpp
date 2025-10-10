#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;
        set<int> unique_beauties;
        for (int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            unique_beauties.insert(b);
        }
        cout << unique_beauties.size() << endl;
    }
    return 0;
}