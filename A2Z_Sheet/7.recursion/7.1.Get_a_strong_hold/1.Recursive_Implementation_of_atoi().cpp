#include <iostream>
using namespace std;

// TC: O(N)
// SC: O(N) due to recursion stack
const int INT_MIN_VAL = -2147483648;
const int INT_MAX_VAL = 2147483647;

// Recursive helper
int helper(const string &s, int i, long long num, int sign) {
    // If we are out of bounds or at a non-digit, return
    if (i >= s.size() || !isdigit(s[i]))
        return (int)(sign * num);
    // Update num with current digit
    num = num * 10 + (s[i] - '0');
    // Clamp if overflow
    if (sign * num <= INT_MIN_VAL) return INT_MIN_VAL;
    if (sign * num >= INT_MAX_VAL) return INT_MAX_VAL;
    // Recurse for next character
    return helper(s, i + 1, num, sign);
}

int myAtoi(string s, int i = 0) {
    int n = s.size();
    int i = 0;
    // skip spaces
    while (i < n && s[i] == ' ')
        i++;
    // default sign
    int sign = 1;
    // check sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '+') ? 1 : -1;
        i++;
    }
    // skip leading zeros
    while (i < n && s[i] == '0')
        i++;
    return helper(s, i, 0LL, sign);
}



// Optimal Approach
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) {
            return 0;
        }
        
        // Use standard library constants
        const long long MAX_INT = INT_MAX;
        const long long MIN_INT = INT_MIN;
        
        int i = 0;
        int n = s.length();
        
        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Check if we've reached the end
        if (i == n) {
            return 0;
        }
        
        // Step 2: Check for sign
        int sign = 1;
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }
        
        // Step 3: Read digits and convert
        long long res = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            res = res * 10 + digit;
            
            if (sign * res <= INT_MIN) {
                return INT_MIN;
            }
            if (sign * res >= INT_MAX) {
                return INT_MAX;
            }
            
            i++;
        }
        return static_cast<int>(res * sign);  
    }
};



int main() {
    string s = "  -12345";
    cout << myAtoi(s) << endl;  // Output: -12345
    return 0;
}