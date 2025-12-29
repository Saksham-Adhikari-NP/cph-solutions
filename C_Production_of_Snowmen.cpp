#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        rep(i,0,n) cin >> a[i];
        rep(i,0,n) cin >> b[i];
        rep(i,0,n) cin >> c[i];

        vector<int> aa = a, bb = b, cc = c;
        aa.insert(aa.end(), a.begin(), a.end());
        bb.insert(bb.end(), b.begin(), b.end());
        cc.insert(cc.end(), c.begin(), c.end());

        long long ans = 0;
        rep(i,0,n) {
            vector<int> valid_j;
            rep(j,0,n) {
                bool ok = true;
                rep(t,0,n) {
                    if(aa[i+t] >= bb[j+t]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) valid_j.push_back(j);
            }

            for(int j : valid_j) {
                rep(k,0,n) {
                    bool ok = true;
                    rep(t,0,n) {
                        if(bb[j+t] >= cc[k+t]) {
                            ok = false;
                            break;
                        }
                    }
                    if(ok) ans++;
                }
            }
        }

        cout << ans << "\n";
    }
}
