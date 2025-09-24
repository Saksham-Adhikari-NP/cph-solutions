#include<bits/stdc++.h>
using namespace std;
int main () 
{
     int t; 
     cin>> t ;
      while (t --)
      {
         int a , b , ans, d  ; 
         cin >> a >> b ; 
        ans = a%b ;
        d = min(ans , b-ans);
        cout << d << "\n";
      } 

}