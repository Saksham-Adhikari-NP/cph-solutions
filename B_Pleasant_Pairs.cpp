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

        vector<pair<int,int>> arr(n) ;
        
        for( int i = 0 ; i< n ; i++)
        {
          cin >> arr[i].first ;
          arr[i].second = i+1 ;
        } 
        sort (arr.begin() , arr.end()) ;
        int ans = 0 ;
        for(int i = 0 ; i<n-1 ; i++) 
        {
          for(int j = i+1 ; j<n ; j++) 
            {
              if(arr[i].first * arr[j].first > 2*n ) break;
              if (arr[i].first * arr[j].first == arr[i].second+arr[j].second ) ++ans;
            }
        
        }
        cout << ans << endl;
    }
    
    return 0;
}
