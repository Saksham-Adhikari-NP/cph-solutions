#include<bits/stdc++.h>
using namespace std;
int main () 
{
     int t; 
     cin>> t ;
      while (t --)
      {
          int n;
        cin >> n;
        vector<long long> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        long long sum = 0;
        long long current_max = a[0];

        for(int i=1; i<n; i++) {
            if ((a[i] > 0) == (current_max > 0)) {
                current_max = max(current_max, a[i]);
            } else {
                sum += current_max;
                current_max = a[i];
            }
        }
        sum += current_max;

        cout << sum << "\n";
    }
    return 0;
      }