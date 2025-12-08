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
    
    int n;
    cin >> n;
    vector<int>dice(6);
    iota(dice.begin(),dice.end(),1);
    vector<int> ways(n+1,0);
    ways[0] = 1;

    for(int i=1; i<=n ; i++)
    {
      for(auto num:dice){
        if(i - num >= 0)
        ways[i] += ways[i- num];
        ways[i] %= MOD;

      }
    }
    cout << ways[n];
    
    return 0;
}
