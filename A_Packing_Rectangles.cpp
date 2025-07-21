#include<std/c++.h>
using namespace std;
using ll = long long;
   ll w,h,n; 

int main() {
    // Example code to demonstrate the use of C++17 features
    cin >> w >> h >> n;
    // min mo of and area 

    int upper_bound = maxvalue(w, h) * n;
    ll x = -1;
    for (ll b = upper_bound; b >= 1; b /= 2) {
    while (!ok(x+b)) x += b;
    }
    int k = x+1;
    cout << k ; 
} 
bool ok (ll s) {
    return (s / w) * (s / h) >= n;
} 


   