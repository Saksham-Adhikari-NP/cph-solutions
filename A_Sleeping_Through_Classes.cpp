#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

template<typename T>
istream& operator>>(istream& s, vector<T>& v){
    for(auto &x : v) s >> x;
    return s;
}

template<typename T>
ostream& operator<<(ostream& s, const vector<T>& v){
    for(auto &x : v) s << x << ' ';
    return s;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> awake(n, 0);

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                for(int j = i; j < n && j <= i + k; j++){
                    awake[j] = 1;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0' && awake[i] == 0) ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
