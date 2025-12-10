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
    
    int n ;
    cin >> n ;
    vector<int> coins(n);
    int max_sum =0;
    vector<bool> can(INF,false);
    can[0] = true;

    for (int i = 0 ; i< n ; i++)
    {
      cin >> coins [i];
      max_sum += coins[i];
      can[coins [i]] == true;
      
    }
    
    for ( int coin : coins)
    {
      for(int s = max_sum -  coin ; s>= 0 ; s-- )
      {
        if (can[s] ==true) can[s+coin] = true ;
      }
    } 
      vector<int> results;
    for(int i = 1 ; i <= max_sum ; i++)
    {
      if (can[i]) results.push_back(i); 
    }

    cout << results.size() << endl;
    for(auto x:results)
    {
      cout << x << " ";
    }
    return 0;
}
