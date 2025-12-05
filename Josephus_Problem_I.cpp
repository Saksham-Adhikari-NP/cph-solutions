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
    
      int n;
      int k = 0;
    cin >> n >> k;
    vector<int> people(n);
    iota(people.begin(), people.end(), 1); // fill 1..n

    int idx = 0;
    while(!people.empty()) {
        idx = (idx + k) % people.size(); // find the next element to remove
        cout << people[idx] << " ";
        people.erase(people.begin() + idx);

}
}
