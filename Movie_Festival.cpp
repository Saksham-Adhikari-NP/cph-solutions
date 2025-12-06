#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

template<typename T>
istream& operator>>(istream& in, vector<T> &v){
    for(auto &x : v) in >> x;
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T> &v){
    for(auto x : v) out << x << ' ';
    return out;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int,int>> movies(n);
    for(int i = 0; i < n; i++) cin >> movies[i].first >> movies[i].second;

    sort(movies.begin(), movies.end(), [](auto &a, auto &b){
        return a.second < b.second; // sort by end time
    });

    int count = 0;
    int current_end = 0;

    for(auto &m : movies){
        if(m.first >= current_end){
            count++;
            current_end = m.second;
        }
    }

    cout << count << endl;
}
