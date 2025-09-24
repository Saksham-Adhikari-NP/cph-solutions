#include<bits/stdc++.h>
using namespace std;
int main () 
{
     int t; 
     cin>> t ;
      while (t --)
      {
         int n; 
        string s;
        cin >> n >> s; 
        int count = 0 , result = 0 ; 

        for (int i = 0 ; i < n ; i++ )
        {
            if (s[i] == (')'))
            {
                count--;

            }
            else count --; 

            result = min(result , count);

        } 

        cout << abs(result) << "\n";
}