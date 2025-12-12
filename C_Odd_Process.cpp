#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T>
istream& operator >> (istream& s, vector<T> & v){
  for(auto &x: v)
    s >> x;
  return s;
}
template<typename T>
istream& operator >> (istream& s, vector<pair<T,T>> & v){
  for(auto &x: v)
    s >> x.first >> x.second;
  return s;
}
template<typename T>
ostream& operator << (ostream& s, vector<T> & v){
  for(auto &x: v)
    s << x << " ";
  s << endl;
  return s;
}
template<typename T>
ostream& operator << (ostream& s, vector<pair<T,T>> & v){
  for(auto &x: v)
    s << x.first << " " << x.second << endl;
  return s;
}

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;

    vector<ll> odd,even;
    for(int i=0; i<n; i++){
      if(a[i]&1) odd.push_back(a[i]);
      else even.push_back(a[i]);
    }
    if(odd.empty()){
      vector<ll> x(n,0);
      cout << x ;
      return;
    }

    sort(odd.begin(),odd.end(), greater<ll>());
    sort(even.begin(), even.end(), greater<ll> ());
    int e = (int)even.size(), o = (int)odd.size();
    vector<ll> s(e + 1);
    for(int i=1; i<=e; i++){
      s[i] = s[i-1] + even[i-1];
    }

    for(int k=1; k<=n; k++){
      int x = max(k-e,1);
      if(x&1^1) x++;
      if(x > k || x > o){
        cout << 0 << " ";
        continue;
      }
      cout << odd[0] + s[k-x] << " ";
    }
    cout << endl;




}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
        
    return 0;
}