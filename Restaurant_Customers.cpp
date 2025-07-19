#include<bits/stdc++.h>
using namespace std; 
bool cmp(pair<int,int>a, pair<int,int>b)
{
    return a.second<b.second;
}
int main() {

    int n;
    vector<pair<int,int>>customer ;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        customer.push_back({a,b});
    }

    // Sort the customers based on their arrival time
    sort(customer.begin(), customer.end(),cmp);

vector<int> count(n,1);
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (customer[j].first <= customer[i].second) {
                count[i]++;
            }
        }
    }
int max = *max_element(count.begin(), count.end());
    cout << max ;
    
    return 0;
}
