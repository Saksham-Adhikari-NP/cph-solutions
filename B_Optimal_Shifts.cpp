#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

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
        
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> lastidx1;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
            {
                lastidx1.push_back(i);
            }
        if ((int)lastidx1.size() == n)
         {
            cout << 0 << endl;
            continue;
         }

        int k = lastidx1.size();
        int ans = 0;

        for (int i = 0; i + 1 < k; i++){
            ans = max(ans, lastidx1[i+1] - lastidx1[i] - 1);}

        ans = max(ans, (lastidx1[0] + n - lastidx1[k-1] - 1));

        cout << ans << endl;    
    }
    
    return 0;
}
