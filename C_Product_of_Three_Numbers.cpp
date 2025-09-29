#include<bits/stdc++.h>
using namespace std;
int main () 
{
    int t ;
 
   

    cin >> t ;
        while (t --)
        {

            int n , i ;
                int a ,b=0 ,c,d,m;
             cin >> n ; 
            for ( i = 1 ; i*i <= n ; i++ )
            { if (n%i != 0)
                {
                     a = i ; 
                     m = n /a;
                     break ; 

                } 
                
            }   

            if ( a == 0 )
            {
                 cout << "NO" << endl;

            }
            else { 
               
                for ( i = a+1 ; i*i <= m ; i++ ) 
                {
                     if ( m%i == 0)
                     {
                        b = i;
                        break ; 
                     }
                }

                c = n / (a*b) ;

                if ((b>1) && (c>1) && ( (a != b) && (b != c) && (a != c))

                {
                    cout << "YES" << endl;
                    cout << a << " " << b << " " << c << endl;
                }
                else 
                {
                    cout << "NO" << endl;
                }
            }

            
        }
        return 0; 

}