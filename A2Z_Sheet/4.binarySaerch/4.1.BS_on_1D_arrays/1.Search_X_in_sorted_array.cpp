#include <iostream>
using namespace std;


// Iterative Implementation 
// TC: O(log N)
// SC: O(1)
class Solution {
public:
    // Function to perform Binary Search on sorted array
    int binarySearch(vector<int>& nums, int target) {
        int n = nums.size(); // size of the array
        int low = 0, high = n - 1;
        // Keep searching until low crosses high
        while (low <= high) {
            int mid = (low + high) / 2; // Find the middle index
            if (nums[mid] == target) return mid;       // Target found
            else if (target > nums[mid]) low = mid + 1; // Search in right half
            else high = mid - 1;                        // Search in left half
        }
        return -1; // Target not found
    }
};


// Recursive Approach 
// TC: O(log N)
// SC: O(1)
class Solution2 {
public:
    // Recursive Binary Search function
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        if (low > high) return -1; // Base case: target not found
        // Find middle index
        int mid = (low + high) / 2;
        // If target is found at mid
        if (nums[mid] == target) return mid;
        // If target is greater, search right half
        else if (target > nums[mid])
            return binarySearch(nums, mid + 1, high, target);
        // Otherwise, search left half
        return binarySearch(nums, low, mid - 1, target);
    }
    // Public function to initiate search
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};



int main() {
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17}; // sorted array
    int target = 6; // target element to search
    Solution obj; // Create object of Solution class
    int ind = obj.binarySearch(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << ind << endl;
    return 0;
}
