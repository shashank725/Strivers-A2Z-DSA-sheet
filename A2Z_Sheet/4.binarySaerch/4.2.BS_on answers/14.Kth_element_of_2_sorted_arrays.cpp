#include <iostream>
using namespace std;

// Problem Statement: Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array. 
// Same as previous problem but here we are using optimal approach to solve the problem.

// Optimal Approach
// TC: O(log(min(m, n)))
// SC: O(1)
class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int m = a.size();
        int n = b.size();

        // Ensure a is smaller array for optimization
        if (m > n) {
            // Swap a and b
            return kthElement(b, a, k); 
        }
        
        // Length of the left half
        int left = k; 

        // Apply binary search
        int low = max(0, k - n), high = min(k, m);
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            // Initialize l1, l2, r1, r2
            int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < m) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < n) ? b[mid2] : INT_MAX;

            // Check if we have found the answer
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } 
            else if (l1 > r2) {
                // Eliminate the right half
                high = mid1 - 1;
            } 
            else {
                // Eliminate the left half
                low = mid1 + 1;
            }
        }
        
         // Dummy return statement 
        return -1;
    }
};



int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    
    //Create an instance of Solution class
    Solution solution;
    
    //Print the answer
    cout << "The " << k << "-th element of two sorted arrays is: "
         << solution.kthElement(a, b, k) << '\n';

    return 0;
}
