#include <iostream>
using namespace std;

// Problem Statement: A monkey Koko is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.
// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
// Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours. 

// Brute Force Approach
// TC: O(N * max(a[i]))
// SC: O(1)
class Solution {
public:
    // Function to calculate total hours for given speed
    int calculateTotalHours(vector<int>& a, int hourly) {
        int totalHours = 0;
        for (int pile : a) {
            // Add hours using ceil
            totalHours += (pile + hourly - 1) / hourly;
        }
        return totalHours;
    }

    // Function to find minimum eating speed
    int minEatingSpeed(vector<int>& a, int h) {
        // Find maximum pile size
        int maxVal = *max_element(a.begin(), a.end());
        // Try every possible speed
        for (int i = 1; i <= maxVal; i++) {
            int hours = calculateTotalHours(a, i);
            // If hours fit within h
            if (hours <= h) {
                return i;
            }
        }
        return maxVal;
    }
};


// Better Approach
// TC: O(N * log(max(a[i])))
// SC: O(1)
class Solution2 {
public:
    // Function to calculate total hours at given speed
    int calculateTotalHours(vector<int>& piles, int speed) {
        int totalH = 0;
        for (int bananas : piles) {
            totalH += ceil((double)bananas / speed);
        }
        return totalH;
    }

    // Function to find minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        // Find maximum element
        int maxPile = *max_element(piles.begin(), piles.end());
        // Initialize low and high pointers
        int low = 1, high = maxPile;
        int ans = maxPile;
        // Binary search on answer space
        while (low <= high) {
            int mid = (low + high) / 2;
            int totalH = calculateTotalHours(piles, mid);
            // If possible, try smaller speed
            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            }
            // Otherwise, try larger speed
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};


// Optimal Approach
// TC: O(N * log(max(a[i])))
class Solution3 {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxPile;
        int ans = maxPile;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = 0;

            for (int pile : piles) {
                totalH += (pile + mid - 1) / mid; // Equivalent to ceil(pile / mid)
            }

            if (totalH <= h) {
                ans = mid;
                high = mid - 1; // Try to find a smaller speed
            } else {
                low = mid + 1; // Increase speed
            }
        }
        return ans;
    }
};



int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    Solution obj;
    cout << obj.minEatingSpeed(piles, h);
    return 0;
}