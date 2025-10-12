#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to convert an integer to its binary string representation.
string toBinary(int n) {
    if (n == 0) {
        return "0";
    }
    string binaryString = "";
    while (n > 0) {
        binaryString = (n % 2 == 0 ? "0" : "1") + binaryString;
        n /= 2;
    }
    return binaryString;
}

// Function to check if a string is a palindrome.
bool isPalindrome(const string& s) {
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
}

void solve() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "YES" << endl;
        return;
    }

    string s = toBinary(n);

    // Scenario 1: n's binary representation can be made a palindrome
    // by adding zeros to the left.
    bool possible = false;
    string temp_s = s;
    while (temp_s.length() > 0 && temp_s.back() == '0') {
        temp_s.pop_back();
        if (isPalindrome(temp_s)) {
            possible = true;
            break;
        }
    }
    
    // Scenario 2: n's binary representation can be made a palindrome
    // by adding zeros to the right.
    if (!possible) {
        temp_s = s;
        while (temp_s.length() > 0 && temp_s.front() == '0') {
             // This case is unlikely for n > 0 but included for completeness.
            temp_s.erase(0, 1);
            if (isPalindrome(temp_s)) {
                possible = true;
                break;
            }
        }
    }
    
    if (isPalindrome(s)) {
        possible = true;
    }


    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}