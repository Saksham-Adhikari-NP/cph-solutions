#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> freq(102,0);
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            freq[x]++;
        }

        int first_missing = 0, second_missing = 0;

        // first pass: count mex considering 0 or 1 occurrence
        for(int i=0;i<=101;i++){
            if(freq[i]==0){
                first_missing = i;
                break;
            } else {
                freq[i]--; // take one occurrence for first multiset
            }
        }

        for(int i=0;i<=101;i++){
            if(freq[i]==0){
                second_missing = i;
                break;
            }
        }

        cout << first_missing + second_missing << endl;
    }
    return 0;
}
