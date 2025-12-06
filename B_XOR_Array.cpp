#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

template<typename T>
istream& operator >> (istream& s, vector<T> & v){
    for(auto &x: v) s >> x;
    return s;
}
template<typename T>
ostream& operator << (ostream& s, vector<T> & v){
    for(auto &x: v) s << x << " ";
    s << endl;
    return s;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n + 1); 

        int dist_count = 1;
        for(int i = l; i < r; i++) {
            a[i] = dist_count++;
        }

        int xor_val = 0;
        for(int i = l; i < r; i++) xor_val ^= a[i];
        a[r] = xor_val;

        int offset = 1e6; 
        for(int i = 1; i <= n; i++) {
            if(i < l || i > r) {
                a[i] = offset++;
            }
        }

        for(int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
}
