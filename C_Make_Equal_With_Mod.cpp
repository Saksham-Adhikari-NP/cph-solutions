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
		vector<int> arr(n);
		cin >> arr;
		sort(arr.begin(), arr.end());
		bool Has_one = false , One_after = false;
		for(int i=0; i < n; i++)
    {
			if(arr[i] == 1) Has_one = true;
			if(i < n-1 && arr[i]+1 == arr[i+1]) One_after = true;
		}
 
		cout << ((Has_one && One_after) ? "no" : "yes") << endl;

    }
    
    return 0;
}
