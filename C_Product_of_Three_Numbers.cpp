#include<bits/stdc++.h>
using namespace std;
int main () 
{
     int t,n ;
    int a ,b=0 ,c; 
    int i; 

    cin >> t ;
        while (t --)
        [
             cin >> n ; 
            for ( i = 1 ; i*i <= n ; i++ )
            { if (n%i != 0)
                {
                     b = i ; 
                     break ; 
                } 
                
            }   

            if ( b == 0 )
            {
                 cout << NO << endl;

            }
            else { 

                a*a = n 
                c = n / ( a*b);
                if ( (a>1_) && ( b >1 )) 
                {
                     cout << YES << endl;
                        cout << a << " " << b << " " << c << endl;
                }
                else cout << NO << endl;
            }


        ]

}