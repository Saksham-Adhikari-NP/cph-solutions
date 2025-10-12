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
        queue<int> repeat_pool;
        int last = 0;
        int next_new = 1;

        for(int i=0;i<n;i++){
            int delta = b[i] - last;
            last = b[i];
            if(delta > 0){
                // pick delta new numbers
                for(int j=0;j<delta;j++){
                    while(used.count(next_new)) next_new++;
                    a[i] = next_new;
                    used.insert(next_new);
                }
            } else {
                // pick any number already used
                if(!used.empty()) a[i] = *used.begin();
                else a[i] = 1;
            }
        }

        for(int i=0;i<n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
