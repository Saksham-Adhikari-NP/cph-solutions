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
    while(t--) {
        // solve here

        int n;
        string s;
        cin >> n >> s;

        string target = "2026";
        int min_operation_2026 = INF;
        for(int i=0; i<=n-4; i++) {
            int ops = 0;
            for(int j=0; j<4; j++) 
                if(s[i+j] != target[j]) ops++;
            min_operation_2026 = min(min_operation_2026, ops);
        }

        int min_operation_wo_2025 = 0;
        int i = 0;
        while(i <= n-4) {
            if(s.substr(i,4) == "2025") {
                min_operation_wo_2025++;
                i += 4;
            } else i++;
        }

        cout << min(min_operation_2026, min_operation_wo_2025) << endl;
    }

    return 0;
}
