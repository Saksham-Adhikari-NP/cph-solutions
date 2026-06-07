#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'
#define vi vector<int>  
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Max(x) (*max_element(all(x)))
#define Min(x) (*min_element(all(x)))
#define Sum(x) (accumulate(all(x), 0LL))
#define sz(x) ((int)x.size())
#define Unique(x) sort(all(x)); (x).erase(unique(all(x)),x.end())

// bitmanip shortcuts 
int hsetbit (int a ) { return (63 - __builtin_clzll(a)) ; } 
int lsetbit (int n ) { return (n & -n) ; }
int setbit (int n) { return __builtin_popcountll(n); } 


#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define trav(a,x) for (auto& a : x)

const int INF = 1e18;
const int MOD = 1e9+7; 

// Modular operations
int modpow(int x, int n, int m = MOD) {
    if (n == 0) return 1%m;
    int u = modpow(x, n/2, m);
    u = (u * 1LL * u) % m;
    if (n%2 == 1) u = (u * 1LL * x) % m;
    return u;
}
int add(int a, int b, int m = MOD) { return (a + b) % m; }
int sub(int a, int b, int m = MOD) { return (a - b + m) % m; }
int mul(int a, int b, int m = MOD) { return (a * 1LL * b) % m; }
int modinv(int a, int m = MOD) { return modpow(a, m-2, m); }
int moddiv(int a, int b, int m = MOD) { return mul(a, modinv(b,m), m); }
int norm(int x, int m = MOD) { x %= m; if(x < 0) x += m; return x; }

// nCr
const int MAXN = 1e6+5;
int fact[MAXN], invfact[MAXN];
void init_fact() {
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++) fact[i] = mul(fact[i-1], i);
    invfact[MAXN-1] = modinv(fact[MAXN-1]);
    for(int i = MAXN-2; i >= 0; i--) invfact[i] = mul(invfact[i+1], i+1);
}
int nCr(int n, int r) {
    if(r<0 || r>n) return 0;
    return mul(fact[n], mul(invfact[r], invfact[n-r]));
}

// vector io
template<typename T>
istream& operator >> (istream& s, vector<T> & v){
    for(auto &x: v) s >> x;
    return s;
}
template<typename T>
ostream& operator << (ostream& s, vector<T> & v){
    for(auto &x: v) s << x << " ";
    s << endl;
    return s;
}
inline void printYN(bool t) { cout << (t ? "YES" : "NO" ) << endl; }

struct Edge {
    int to;
    long long weight;
};

using Graph = std::vector<std::vector<int>>;
using WeightedGraph = std::vector<std::vector<Edge>>;

 int dx[]={0,0,1,-1};
 int dy[]={1,-1,0,0};
 string ds="RLDU";
using pii = pair<int, int>;

int get_dir_idx(char c) {
    if (c == 'R') return 0;
    if (c == 'L') return 1;
    if (c == 'D') return 2;
    if (c == 'U') return 3;
    return -1;
}

void solve () 
{
    // solve here
    int h, w; cin >> h >> w; 
    vector<vi> mape(1000, vi(1000, MAXN));
    vector<vector<char>> moves(1000, vector<char>(1000, '#'));
    vector<vector<char>> lab(h);  
    pair<int, int> start;
    vector<pii> monster; 
    
    FOR(i, 0, h) 
    {
        FOR(j, 0, w) 
        {
            char a; cin >> a; 
            lab[i].pb(a); 
            if(a == 'A') { start.first = i; start.second = j; }
            else if (a == 'M') { monster.pb({i, j}); } 
        }
    }

    queue<pair<int, int>> q;

    function<void(bool)> map_closest = [&](bool hum) 
    {
        while(!q.empty()) 
        {
            auto cur = q.front();
            q.pop();

            FOR(i, 0, 4) 
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                 if(nx >= 0 && nx < h && ny >= 0 && ny < w && lab[nx][ny] != '#') 
                {
                    if (!hum) 
                    { 
                        if(mape[cur.first][cur.second] + 1 < mape[nx][ny]) 
                        {
                            mape[nx][ny] = mape[cur.first][cur.second] + 1;
                            q.push({nx, ny});
                        }
                    }
                    else 
                    { 
                        int next_dis = mape[cur.first][cur.second] + 1; 
                        if(next_dis < mape[nx][ny] && moves[nx][ny] == '#') 
                        {
                            mape[nx][ny] = next_dis;
                            moves[nx][ny] = ds[i]; 
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    };

    FOR(i, 0, monster.size()) 
    {
        mape[monster[i].first][monster[i].second] = 0;
        q.push({monster[i].first, monster[i].second});
    }
    map_closest(false); 

    if (start.first == 0 || start.first == h - 1 || start.second == 0 || start.second == w - 1) {
        cout << "YES\n0\n";
        return;
    }

    mape[start.first][start.second] = 0; 
    q.push({start.first, start.second});
    map_closest(true); 

    pair<int, int> escape_cell = {-1, -1};
    
    FOR(i, 0, h) {
        FOR(j, 0, w) {
            if((i == 0 || i == h - 1 || j == 0 || j == w - 1) && moves[i][j] != '#') {
                escape_cell = {i, j};
                break;
            }
        }
        if(escape_cell.first != -1) break;
    }

    if(escape_cell.first == -1) {
        cout << "NO\n";
    } 
    else {
        cout << "YES\n";
        string path = "";
        int cr = escape_cell.first;
        int cc = escape_cell.second;

        while(cr != start.first || cc != start.second) {
            char move = moves[cr][cc];
            path += move;
            int idx = get_dir_idx(move);
            cr -= dx[idx]; 
            cc -= dy[idx];
        }
        
        reverse(path.begin(), path.end());
        cout << path.size() << endl ;
        cout << path << endl ; 
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);   // debug

    // init_fact(); // Uncomment if nCr needed

solve() ; 
    return 0;
}

