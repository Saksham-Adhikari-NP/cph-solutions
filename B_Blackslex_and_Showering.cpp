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
        int n;
        cin >> n;
        vector<int> a(n);
        cin >> a;

        long long total = 0;
        for(int i=1;i<n;i++) total += abs(a[i]-a[i-1]);

        long long endsub = max(abs(a[1]-a[0]), abs(a[n-1]-a[n-2]));

        for(int i=1;i<n-1;i++){
            long long currsub = abs(a[i]-a[i-1]) + abs(a[i]-a[i+1]) - abs(a[i+1]-a[i-1]);
            endsub = max(endsub, currsub);
        }

        cout << total - endsub << endl;


    }
    
    return 0;
}
