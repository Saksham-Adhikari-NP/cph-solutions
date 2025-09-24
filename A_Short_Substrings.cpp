#include<bits/stdc++.h>
using namespace std; 
int main () 
{
     int t;
     cin >> t;
    while(t--)
    {
        string b; 
        cin >> b;
        for(int i=0 ; i < b.size(); i++)

        {
            if( (i>1) && (i%2 == 1))  
            {
                continue;
            }
            else {
                cout << b[i];
            }
        }
    }
}