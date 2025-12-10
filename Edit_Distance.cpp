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
    
    string s1 , s2 ;
    int  siz1 , siz2;
    cin >> s1 ;
    cin >> s2 ;
    siz1 = s1.size();
    siz2 = s2.size(); 
    vector<vector<int>> dp (siz1 + 1 , vector<int> ( siz2 + 1, 0));
    for(int i = 0 ; i<= siz1 ; i++ ) dp[i][0] = i;
    for(int i = 0 ; i<= siz2 ; i++ ) dp[0][i] = i;
    
    for(int i = 1 ; i <= siz1 ; i++)
    {
      for(int j =1 ; j<= siz2 ; j++ )
      {
        int cost = (s1[i-1] == s2[j-1] ?0:1) ;
        dp[i][j] = min( {dp[i-1][j] +1 , dp[i][j-1]+1, dp[i-1][j-1] + cost});
      
      }
    }
    cout << dp[siz1][siz2] ; 

      
    return 0;
}
