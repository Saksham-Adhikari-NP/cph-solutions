#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> answer;
        for (int i = 1; answer.size() < k; i++) {
            answer.push_back(i);
            if (i == n) i = 0; 

        for (int i = 0; i < k; i++) {
            cout << answer[i] << " ";
        }
        cout << "\n";
    }
}
}

