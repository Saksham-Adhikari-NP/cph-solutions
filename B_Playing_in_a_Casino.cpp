#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair

const int INF = 1e9;
const int MOD = 1e9+7; 

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
    
    int t;
    cin >> t;
    while (t--) {
        // solve here
        int a, b;
        cin >> a >> b;

        vector<vector<int>> arr(a, vector<int>(b));
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                cin >> arr[i][j];

        int ans = 0;

        for (int col = 0; col < b; col++) {
            vector<int> v(a);
            for (int i = 0; i < a; i++)
                v[i] = arr[i][col];

            sort(v.begin(), v.end());

            int pref = 0;
            for (int i = 0; i < a; i++) {
                ans += v[i] * i - pref;
                pref += v[i];
            }
        }

        cout << ans << '\n';
    }
    
    return 0;
}
