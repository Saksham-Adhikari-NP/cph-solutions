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
    for(size_t i = 0; i < v.size(); ++i){
        if(i) s << ' ';
        s << v[i];
    }
    return s;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        cin >> a >> b;

        long long mx = 0, mn = 0;
        for(int i = 0; i < n; ++i){
            long long red_card = mx - a[i];
            long long blue_card = b[i] - mn;
            long long new_mx = max(red_card, blue_card);

            long long cand3 = mn - a[i]; 
            long long cand4 = b[i] - mx;
            long long new_mn = min(cand3, cand4);

            mx = new_mx;
            mn = new_mn;
        }

        cout << mx << endl;
    }

    return 0;
}
