#include <iostream>
#include <vector>
#include <set>

// The solve function contains the logic for a single test case.
void solve() {
    int n;
    std::cin >> n;
    
    // A set is an ideal data structure here because it automatically
    // stores only unique elements.
    std::set<int> unique_beauties;
    
    // Read each beauty value and insert it into the set.
    for (int i = 0; i < n; ++i) {
        int b;
        std::cin >> b;
        unique_beauties.insert(b);
    }
    
    // The size of the set gives us the number of distinct beauty values.
    // This is the maximum number of apples we can eat, as we can always
    // pick one apple of each unique beauty in increasing order.
    std::cout << unique_beauties.size() << '\n';
}

int main() {
    // Fast I/O operations.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}