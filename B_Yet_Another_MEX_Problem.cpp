#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {

        int n , k ;
        cin >> n >> k ;

        vector<int> arr (n) ;
        unordered_map<int,int> present ; 
        for(int i = 0 ; i< n  ; i++ ) {
            {
                cin >> arr[i] ;
                present[arr[i]] = 1 ;
            }

        }

         int ans = 0 ;
         for ( int i = 0 ; i < k-1; i++) 
            {
                if (present[i] )  ans ++ ;
                else break ; 
            }
            cout << ans << endl ; 

    }
    return 0 ; 
}
