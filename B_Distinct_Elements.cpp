#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int reverse_binary(int num) {
    if (num == 0) return 0;
    string s = bitset<64>(num).to_string();
    s = s.substr(s.find('1'));
    reverse(s.begin(), s.end());
    return stoll(s, nullptr, 2);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 0) {
            cout << "YES" << endl;
            continue;
        }

        // --- Check for even n ---
        if (n % 2 == 0) {
            string s1 = '0' + bitset<64>(n).to_string();
            s1 = s1.substr(s1.find('0'));
            string rev1 = s1;
            reverse(rev1.begin(), rev1.end());
            bool is_palindrome1 = (s1 == rev1);
            bool len_s1_is_odd = (s1.size() % 2 != 0);
            if (is_palindrome1 && (!len_s1_is_odd || s1[s1.size() / 2] == '0')) {
                cout << "YES" << endl;
                continue;
            }

            string s2 = '0' + bitset<64>(n).to_string() + '0';
            s2 = s2.substr(s2.find('0'));
            string rev2 = s2;
            reverse(rev2.begin(), rev2.end());
            bool is_palindrome2 = (s2 == rev2);
            bool len_s2_is_odd = (s2.size() % 2 != 0);
            if (is_palindrome2 && (!len_s2_is_odd || s2[s2.size() / 2] == '0')) {
                cout << "YES" << endl;
                continue;
            }

            cout << "NO" << endl;
            continue;
        }

        // --- Check for odd n ---
        if (n == 3) {
            cout << "YES" << endl;
            continue;
        }
        if (n == 11) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }

    return 0;
}
