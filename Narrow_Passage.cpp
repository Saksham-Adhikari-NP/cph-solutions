#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define vi vector<int>
#define all(a) (a).begin(), (a).end()

template<typename T>
istream& operator>>(istream& s, vector<T>& v) {
    for (auto& x : v) s >> x;
    return s;
}

struct Fenwick {
    int n;
    vi bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int i) {
        for (; i <= n; i += i & -i)
            bit[i]++;
    }

    // Number of inserted values <= i
    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};

void solve() {
    int n;
    cin >> n;

    vi a(n), b(n);
    cin >> a >> b;

    int total_distance = 0;
    for (int i = 0; i < n; i++)
        total_distance += llabs(a[i] - b[i]);

    // Rank each person's target coordinate.
    vi by_target(n), target_rank(n);
    iota(all(by_target), 0);

    sort(all(by_target), [&](int x, int y) {
        return b[x] < b[y];
    });

    for (int rank = 0; rank < n; rank++)
        target_rank[by_target[rank]] = rank + 1;

    // Count inversions in target ranks, reading people by starting coordinate.
    vi by_start(n);
    iota(all(by_start), 0);

    sort(all(by_start), [&](int x, int y) {
        return a[x] < a[y];
    });

    Fenwick fw(n);
    int inversions = 0;
    int seen = 0;

    for (int person : by_start) {
        int rank = target_rank[person];
        inversions += seen - fw.sum(rank);
        fw.add(rank);
        seen++;
    }

    cout << total_distance - inversions << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}