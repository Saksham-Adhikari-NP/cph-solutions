#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparison function: returns true if movie a ends before movie b
bool compareByEndTime(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> movies;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies.push_back({a, b});
    }

    // Sort using the named comparison function
    sort(movies.begin(), movies.end(), compareByEndTime);

    int count = 0;
    int last_end = 0;

    for (int i = 0; i < n; i++) {
        if (movies[i].first >= last_end) {
            count++;
            last_end = movies[i].second;
        }
    }

    cout << count << endl;
    return 0;
}
