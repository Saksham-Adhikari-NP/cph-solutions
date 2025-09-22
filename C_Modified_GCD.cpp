#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int a , b ;
    int g = __gcd(a, b);
    int n ; 
    cin >> a >> b >> n;


    vector<pair<int , int >> queries(n);
    for (int i = 0; i < n; i++)
    {
        cin >> queries[i].first >> queries[i].second;
    }  

    // divisors 
    vector<int> divisors;
    for( int i = 1 ; i * i <= g ; i++ )
    {
        if ( g % i == 0 ) 
        {
            divisors.push_back(i);
            if ( i != g / i ) 
            {
                divisors.push_back(g / i);
            }
        }
    } 
    sort(divisors.begin(), divisors.end());


// ans 

    for(int i = 0 ; i < n ; i++) 
{

    auto ptr = upper_bound(divisors.begin(),divisors.end(),queries[i].second);
    if ( ptr = divisors.begin())
    {
        cout<< -1 
        continue;

    }
    ptr--
    if (*ptr >= queries[i].first)
    {
        cout<< *ptr << endl;
    }
    else 
    {
        cout<< -1 << endl;
    }



        return 0;
}