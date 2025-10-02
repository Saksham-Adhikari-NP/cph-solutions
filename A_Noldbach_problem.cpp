#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , k ;
    cin >> n >> k;
     
    bool is_prime[1001] = {false};
    for ( int i =2 ; i<= 1000 ; i++ ) is_prime[i] = true;

    for (int i =2; i<= 1000 ; i++)
    {
        if(is_prime[i]) {
             for (int j = i*i ; j<= n; j += i )
             {
                is_prime[j] = false; 
            
             }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }


    int count = 0;
    for (int i = 0; i < primes.size() - 1; i++) {
        int sum = primes[i] + primes[i+1] + 1;
        if (sum <= n && is_prime[sum]) count++;
    }

    if (count >= k) cout << "YES"<<endl;
    else cout <<"NO" <<  endl;

    return 0;
}
