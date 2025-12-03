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
    int x;
    cin >> n ;
    vector<int> a(n);
    cin >> a;

    map<int , int> freq;
    freq[0] = 1; 
    int sum = 0, count = 0 , remainder ;

    for(int i = 0; i < n; i++) {
        sum += a[i];
        remainder = sum%n;
        if(remainder<0) remainder += n;
        count += freq[remainder];
        freq[remainder]++;
    }

    cout << count << endl;
    
    return 0;
}
