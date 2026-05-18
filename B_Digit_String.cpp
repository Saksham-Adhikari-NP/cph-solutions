#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// Standard direction arrays for 4-directional movement
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void solve() {
    int height, width; 
    if (!(cin >> height >> width)) return;       

    vector<string> st(height); 
    for(int i = 0; i < height; ++i) {
        cin >> st[i]; // Read row by row explicitly
    }

    // Using vector<vector<char>> to avoid vector<bool> proxy reference issues if needed,
    // though vector<bool> works perfectly here for space optimization.
    vector<vector<bool>> visited(height, vector<bool>(width, false)); 
    int ans = 0;

    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            if (st[i][j] == '.' && !visited[i][j]) {
                ans++;                                 
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                                   
                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();
                    
                    for(int d = 0; d < 4; ++d) {
                        int nr = r + dx[d];
                        int nc = c + dy[d];
                                                
                        if (nr >= 0 && nr < height && nc >= 0 && nc < width) {
                            if (st[nr][nc] == '.' && !visited[nr][nc]) {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}