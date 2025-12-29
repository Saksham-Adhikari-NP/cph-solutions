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
    
    int  n , q ; 
    cin >> n >> q ;
    vector<int> arr (n);
    cin >> arr ;
    int sum = accumulate(arr.begin() , arr.end() , 0LL) ;     
    bool type_2_has_hit_the_building = false ;
    unordered_map<int,int> changed_var ; 


      int rep_all;

    while ( q--)
    {
       int type ; 
       cin >> type ;

       if ( type == 1) 
       {

        int rep_idx , rep_val ;
        cin >> rep_idx >> rep_val ;
        rep_idx -- ; // to 0 based 

        if (!type_2_has_hit_the_building)
        {

        sum = sum - arr[rep_idx] + rep_val ; 

        arr[rep_idx] = rep_val ;
        }
        else 
        {
            auto changed_before = changed_var.find(rep_idx) ;
            if(changed_before != changed_var.end()) 
            {
               sum = sum - changed_before->second + rep_val;
               changed_before->second = rep_val ;
            }
            else {
              sum = sum - rep_all + rep_val;
              changed_var[rep_idx] = rep_val ;
            }

        }
       }
       if(type == 2) 
       {
        cin >> rep_all ;
        sum = n*rep_all;
        changed_var.clear(); 
        type_2_has_hit_the_building = true ;
      }
       cout << sum << endl; 
    }
    
    return 0;
}
