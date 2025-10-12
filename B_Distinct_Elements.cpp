#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> b(n);
        for(int i=0;i<n;i++) cin >> b[i];

        vector<int> a(n);
        set<int> used;
        int next_new = 1;
        long long last = 0;

        for(int i=0;i<n;i++){
            long long delta = b[i] - last;
            last = b[i];
            if(delta > 0){
                a[i] = next_new;
                used.insert(next_new);
                next_new++;
            } else {
                // repeat any previously used number
                a[i] = *used.begin();
            }
        }

        for(int i=0;i<n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
