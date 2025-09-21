#include <bits/stdc++.h>
using namespace std;
int main (){
int n,x,sum=0;
bool found = false;
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
    found = true;
cout << l+1 << " " << r+1 << endl;
}
r++ ;
}
if (!found)
{
cout << "IMPOSSIBLE" << endl;
}
}
