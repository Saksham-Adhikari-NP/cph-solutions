#include <bits/stdc++.h>
using namespace std;
int main (){
int n,x,sum=0;
cin >> n >> x;
vector<int> a(n);
for (int i=0;i<n;i++){
    cin >> a[i];
}
int l=0 ,r =0;
while( r<n ) 
{ 
sum += a[r];
while( sum > x  && l<=r ) 
{
sum -= a[l];
l++;          
}
if( sum == x ) 
{
cout << l << " " << r << endl;
}
r++ ;
}
}

