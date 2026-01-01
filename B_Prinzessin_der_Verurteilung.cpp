#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define sz(v) v.size()
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forrr(i,b,a) for(ll i=b;i>=a;i--)
#define forrrr(i,a,b,k) for(ll i=a;i<b;i=i+k)



const int INF = 1e9;
const int MOD = 1e9+7; 

template<typename T>
istream& operator >> (istream& s, vector<T> & v){
  for(auto &x: v)
    s >> x;
  return s;
}
template<typename T>
ostream& operator << (ostream& s, vector<T> & v){
  for(auto &x: v){
    s << x << " ";
  }
  s << endl;
  return s;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        // solve here
        int n;
        cin >> n;
        string s;
        cin >> s;

        set<string> st;

        for (int i = 0; i < n; i++) {
            st.insert(s.substr(i, 1));
            if (i + 1 < n) st.insert(s.substr(i, 2));
            if (i + 2 < n) st.insert(s.substr(i, 3));
        }
        for (char c = 'a'; c <= 'z'; c++) {
            string t(1, c);
            if (!st.count(t)) {
                cout << t << '\n';
                goto done;
            }
        }
        for (char a = 'a'; a <= 'z'; a++) {
            for (char b = 'a'; b <= 'z'; b++) {
                string t;
                t.pb(a);
                t.pb(b);
                if (!st.count(t)) {
                    cout << t << '\n';
                    goto done;
                }
            }
        }
        for (char a = 'a'; a <= 'z'; a++) {
            for (char b = 'a'; b <= 'z'; b++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    string t;
                    t.pb(a);
                    t.pb(b);
                    t.pb(c);
                    if (!st.count(t)) {
                        cout << t << '\n';
                        goto done;
                    }
                }
            }
        }

        done:;

    }
    
    return 0;
}
