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
        vector<int> array(n);
        cin >> array;
        int ans = 0;
        int localmax = 0;
        for(int i = 0 ; i<n ; i++)
        {
          if(array[i] >= localmax) 
          {
            localmax = array[i];
          }
          else{
            ans++;
          }
        }
        cout << ans<<endl ; 

    }
    
    return 0;
}
