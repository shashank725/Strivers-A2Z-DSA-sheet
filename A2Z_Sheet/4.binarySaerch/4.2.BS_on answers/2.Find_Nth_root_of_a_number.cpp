#include <iostream>
using namespace std;

// Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1

// Brute Force Approach
// TC: O(N)
// SC: O(1)
class Solution {
public:
    // Function to find Nth root of M
    int nthRoot(int n, int m) {
        // Loop from 1 to m
        for (int i = 1; i <= m; i++) {
            // Compute i^n
            long long power = pow(i, n);
            // If equal to m, return i
            if (power == m) return i;
            // If exceeds m, break
            if (power > m) break;
        }
        // If not found, return -1
        return -1;
    }
};


// Optimal Approach
// TC: O(log M)
// SC: O(1)
class Solution {
public:
    // Function to find N-th root of M using binary search
    int nthRoot(int n, int m) {
        // Set low and high for binary search
        int low = 1, high = m;
        // Start binary search
        while (low <= high) {
            // Calculate mid
            int mid = (low + high) / 2;
            // Store result of mid^n
            long long ans = 1;
            for (int i = 0; i < n; i++) {
                ans *= mid;
                if (ans > m) break;
            }
            // If mid^n equals m
            if (ans == m) return mid;
            // If mid^n is less than m
            if (ans < m) low = mid + 1;
            // If mid^n is more than m
            else high = mid - 1;
        }
        // Return -1 if not found
        return -1;
    }
};



int main() {
    Solution sol;
    int n = 3, m = 27;

    // Find nth root
    cout << "Nth Root: " << sol.nthRoot(n, m) << endl;

    return 0;
}