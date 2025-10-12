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
        deque<int> pool;  // pool of available numbers to repeat
        int next_new = 1; // next new number to assign

        long long last = 0;
        for(int i=0;i<n;i++){
            long long delta = b[i] - last;
            last = b[i];

            if(delta > 0){
                // Assign a new number from the pool of unused numbers
                a[i] = next_new;
                pool.push_back(next_new);
                next_new++;
            } else {
                // Assign the most recently assigned number (from pool)
                a[i] = pool.back();
            }
        }

        for(int i=0;i<n;i++) cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}
