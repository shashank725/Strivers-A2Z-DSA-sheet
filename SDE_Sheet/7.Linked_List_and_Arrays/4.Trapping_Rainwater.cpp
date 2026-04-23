#include <iostream>
using namespace std;



// Brute Force Approach
// TC: O(n²)
// SC: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // Variable to store total trapped water
        int totalWater = 0;
        // Iterate over each bar in the elevation map
        for (int i = 0; i < n; i++) {
            // Initialize max heights to the left and right of current bar
            int maxLeft = 0;
            int maxRight = 0;
            // Find maximum height to the left of current bar
            for (int j = 0; j <= i; j++) {
                if (height[j] > maxLeft) {
                    maxLeft = height[j];
                }
            }
            // Find maximum height to the right of current bar
            for (int j = i; j < n; j++) {
                if (height[j] > maxRight) {
                    maxRight = height[j];
                }
            }
            // Water trapped on current bar is min of maxLeft and maxRight minus current height
            totalWater += min(maxLeft, maxRight) - height[i];
        }
        // Return total trapped water
        return totalWater;
    }
};


// Better Approach
// TC: O(3N)
// SC: O(2N)
class Solution2 {
public:
   int trap(vector<int>& height) {
        int n = height.size();
        // Create two arrays to store the maximum height to the left and right of each bar
        vector<int> leftMax(n), rightMax(n);
        // Fill leftMax array
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        // Fill rightMax array
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        // Calculate total trapped water
        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            totalWater += min(leftMax[i], rightMax[i]) - height[i];
        }
        // Return total trapped water
        return totalWater;
    }
};


// Optimal Approach
// TC: O(N)
// SC: O(1)
class Solution3 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // Initialize two pointers at both ends of the array
        int left = 0;
        int right = n - 1;
        // Variables to track the maximum height to the left and right
        int maxLeft = 0;
        int maxRight = 0;
        // Variable to store total trapped water
        int totalWater = 0;
        // Iterate until left pointer meets right pointer
        while (left <= right) {
            // If left bar is smaller or equal to right bar
            if (height[left] <= height[right]) {
                // If current left bar is higher than maxLeft, update maxLeft
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    // Water trapped on left is difference between maxLeft and current height
                    totalWater += maxLeft - height[left];
                }
                left++; // Move left pointer to the right
            } else {
                // If current right bar is higher than maxRight, update maxRight
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    // Water trapped on right is difference between maxRight and current height
                    totalWater += maxRight - height[right];
                }
                right--; // Move right pointer to the left
            }
        }
        // Return total trapped water
        return totalWater;
    }
};



// Driver code
int main() {
    // Input elevation map
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // Create Solution object
    Solution sol;
    // Calculate trapped water
    int result = sol.trap(height);
    // Print the result
    cout << "Trapped Rainwater: " << result << endl;
    return 0;
}
