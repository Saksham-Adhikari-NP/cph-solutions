#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    // Use vector of strings to store the grid (0-based indexing for grid)
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    // 2D prefix sum array (1-based indexing for simplicity)
    vector<vector<int>> ps(n + 1, vector<int>(n + 1, 0));

    // Build prefix sum matrix
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int tree = (grid[i - 1][j - 1] == '*') ? 1 : 0;
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + tree;
        }
    }

    // Answer queries
    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        int result = ps[y2][x2]
                   - ps[y1 - 1][x2]
                   - ps[y2][x1 - 1]
                   + ps[y1 - 1][x1 - 1];

        cout << result << '\n';
    }

    return 0;
}
