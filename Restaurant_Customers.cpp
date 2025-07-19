#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arrivals(n), departures(n);
    for (int i = 0; i < n; i++) {
        cin >> arrivals[i] >> departures[i];
    }

    // Sort arrival and departure times separately
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());

    int i = 0, j = 0;
    int current = 0, max_customers = 0;

    // Greedily move through events
    while (i < n && j < n) {
        if (arrivals[i] < departures[j]) {
            current++;        // One more customer arrives
            max_customers = max(max_customers, current);
            i++;
        } else {
            current--;        // One customer leaves
            j++;
        }
    }

    cout << max_customers << '\n';
    return 0;
}
