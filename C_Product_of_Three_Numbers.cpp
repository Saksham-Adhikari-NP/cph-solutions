#include<bits/stdc++.h>
using namespace std;
int main () 
{
    int t,n ;
    int a ,b=0 ,c,d,m; 
    int i; 

    cin >> t ;
        while (t --)
        {
             cin >> n ; 
            for ( i = 1 ; i*i <= n ; i++ )
            { if (n%i != 0)
                {
                     a = i ; 
                     break ; 
                } 
                
            }   

            if ( a == 0 )
            {
                 cout << "NO" << endl;

            }
            else { 
                m = n / a ;
                for ( i = a+1 ; i*i <= m ; i++ ) 
                {
                     if ( n%i == 0)
                     {
                        b = i;
                     }
                }

                c = n / (a*b) ;

                if ((b>1) && (c>1)) 
                {
                    cout << "YES" << endl;
                    cout << a << " " << b << " " << c << endl;
                }
                else 
                {
                    cout << "NO" << endl;
                }
            }

            return 0 ;
        }

}