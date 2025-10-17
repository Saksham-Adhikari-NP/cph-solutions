#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

void dfs(const string &s, int idx, vector<int> &cur, vector<vector<int>> &all) {
    if (idx == s.size()) {
        all.push_back(cur);
        return;
    }
    // Option 1: skip current character
    dfs(s, idx + 1, cur, all);
    // Option 2: include current character if non-decreasing
    if (cur.empty() || s[cur.back()] <= s[idx]) {
        cur.push_back(idx);
        dfs(s, idx + 1, cur, all);
        cur.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        // already palindrome
        if (isPalindrome(s)) {
            cout << 0 << "\n\n";
            continue;
        }

        vector<vector<int>> all;
        vector<int> cur;
        dfs(s, 0, cur, all);

        // longest ans
        sort(all.begin(), all.end(), [](const vector<int> &a, const vector<int> &b){
            return a.size() > b.size();
        });

        bool found = false;
        for (auto &indices : all) {
            string x = "";
            set<int> toRemove(indices.begin(), indices.end());
            for (int i = 0; i < n; i++) {
                if (!toRemove.count(i)) x += s[i];
            }
            if (isPalindrome(x)) {
                cout << indices.size() << "\n";
                for (int i = 0; i < indices.size(); i++) {
                    if (i) cout << " ";
                    cout << indices[i] + 1;
                }
                cout << "\n";
                found = true;
                break;
            }
        }

        if (!found) cout << -1 << "\n";
    }
    return 0;
}
