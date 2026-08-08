#include <iostream>
using namespace std;



// Brute Force Approach
// TC: O(NlogN) + O(N *(max(stalls[])-min(stalls[])))
// SC: O(1)
class Solution {
public:
    bool canPlace(vector<int>& stalls, int cows, int d) {
        // Place the first cow at the first stall
        int count = 1;
        int lastPos = stalls[0];
        // Try placing the remaining cows
        for (int i = 1; i < stalls.size(); i++) {
            // If current stall is at least 'd' away from last cow
            if (stalls[i] - lastPos >= d) {
                // Place a cow here
                count++;
                lastPos = stalls[i];
            }
            // If all cows placed successfully, return true
            if (count >= cows) return true;
        }
        // Not possible to place all cows
        return false;
    }

    // Function to find maximum minimum distance using brute force
    int aggressiveCows(vector<int>& stalls, int cows) {
        // Step 1: Sort stall positions
        sort(stalls.begin(), stalls.end());
        // Step 2: Get the maximum possible distance
        int n = stalls.size();
        int maxDist = stalls[n - 1] - stalls[0];
        // Step 3: Variable to store answer
        int ans = 0;
        // Step 4: Try all possible distances from 1 to maxDist
        for (int d = 1; d <= maxDist; d++) {
            // If cows can be placed with distance d
            if (canPlace(stalls, cows, d)) {
                // Update answer
                ans = d;
            }
        }
        // Step 5: Return the maximum valid distance
        return ans;
    }
};


// Optimal Approach
// TC: O(N)
// SC: O(1)
class Solution3 {
public:
    bool canPlace(vector<int>& stalls, int cows, int d) {
        // Place the first cow at the first stall
        int count = 1;
        int lastPos = stalls[0];
        // Try placing the remaining cows
        for (int i = 1; i < stalls.size(); i++) {
            // If current stall is at least 'd' away from last cow
            if (stalls[i] - lastPos >= d) {
                // Place a cow here
                count++;
                lastPos = stalls[i];
            }
            // If all cows placed successfully, return true
            if (count >= cows) return true;
        }
        // Not possible to place all cows
        return false;
    }

    // Function to find maximum minimum distance using brute force
    int aggressiveCows(vector<int>& stalls, int cows) {
        // Sort the stalls
        sort(stalls.begin(), stalls.end());
        // Define search space
        int low = 1;
        int high = stalls.back() - stalls.front();
        int ans = 0;
        // Apply binary search
        while (low <= high) {
            // Find mid distance
            int mid = low + (high - low) / 2;

            // If placing cows is possible with mid distance
            if (canPlace(stalls, cows, mid)) {
                // Store this as potential answer
                ans = mid;
                // Try to find larger minimum distance
                low = mid + 1;
            }
            else {
                // Otherwise try smaller distance
                high = mid - 1;
            }
        }
        // Return the largest minimum distance
        return ans;
    }
};