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
    
    int n , x ,t,max_willing;
    cin >> n >> t;
    multiset<int> tickets;
    for (int i = 0 ; i<n ; i++)
    {
      cin >> x;
      tickets.insert(x);

    }

    for(int i =0 ; i<t ; i++)
    {
      cin >> max_willing;
      auto it = tickets.upper_bound(max_willing);
      
      if(it != tickets.begin())
      {
        cout << *--it << endl;
        tickets.erase(it);


      }
      else
      {
        cout << "-1" << endl;
      }
    }
}
