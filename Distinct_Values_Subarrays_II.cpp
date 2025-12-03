#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

template<typename T>
istream& operator >> (istream& s, vector<T> & v){
  for(auto &x: v)
    s >> x;
  return s;
}
template<typename T>
ostream& operator << (ostream& s, vector<T> & v){
  for(auto &x: v){
    s << x << " ";
  }
  s << endl;
  return s;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    cin >> a;

    unordered_map<long long, long long> f;
    long long l = 0, distinct = 0, ans = 0;

    for (long long r = 0; r < n; r++) {
        if (f[a[r]] == 0) distinct++;
        f[a[r]]++;

        while (distinct > k) {
            f[a[l]]--;
            if (f[a[l]] == 0) distinct--;
            l++;
        }

        ans += (r - l + 1);
    }

    cout << ans << "\n";
}
