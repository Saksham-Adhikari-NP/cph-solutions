#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        
        if (n == 1) {
            cout << 1 << endl;
        } 
        else if (n == 2) {
            cout << 9 << endl;
        } 
        else if (n == 3) {
            cout << 29 << endl;
        } 
        else if (n == 4) {
            cout << 56 << endl;
        } 
        else {
            long long v = n*n - n - 1;
            cout << 5LL * v << endl;
        }
    }
    
    return 0;
}
