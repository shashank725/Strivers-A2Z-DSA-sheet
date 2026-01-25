#include <iostream>
using namespace std;

// Brute Force Approach
// TC: O(N2)
// SC: O(1)
// Function to check if any two numbers sum up to target (variant 1)
string twoSumExists(vector<int>& arr, int target) {
    int n = arr.size();
    // Outer loop picks one element at a time
    for (int i = 0; i < n; i++) {
        // Inner loop searches for another element that complements arr[i]
        for (int j = i + 1; j < n; j++) {
            // If sum equals target, return "YES"
            if (arr[i] + arr[j] == target) {
                return "YES";
            }
        }
    }
    // No pair found that sums to target
    return "NO";
}
// Function to return indices of two numbers that sum to target (variant 2)
vector<int> twoSumIndices(vector<int>& arr, int target) {
    int n = arr.size();
    // Outer loop picks one element at a time
    for (int i = 0; i < n; i++) {
        // Inner loop searches for another element that complements arr[i]
        for (int j = i + 1; j < n; j++) {
            // If sum equals target, return the pair of indices
            if (arr[i] + arr[j] == target) {
                return {i, j};
            }
        }
    }
    // No such pair found
    return {-1, -1};
}


// Better Approach
// TC: O(N)   If ordered_map -> O(N log N)
// SC: O(N)
// Variant 1: Check if two numbers sum to target using hashing
string twoSumExists2(vector<int>& arr, int target) {
    unordered_map<int, int> mp;  // Map to store element -> index
    int n = arr.size();
    // Iterate over all elements
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];  // Needed value to reach target sum
        // Check if complement is already in map
        if (mp.find(complement) != mp.end()) {
            return "YES";  // Pair found
        }
        // Store current element with its index for future reference
        mp[arr[i]] = i;
    }
    // No pair found
    return "NO";
}
// Variant 2: Return indices of two numbers that sum to target using hashing
vector<int> twoSumIndices2_2(vector<int>& arr, int target) {
    unordered_map<int, int> mp;  // Map to store element -> index
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        // If complement found, return indices
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }
        // Store current element and index
        mp[arr[i]] = i;
    }
    return {-1, -1};  // No pair found
}


// Optimal Approach
// TC: O(N log N)
// SC: O(1) & O(N) for Variant 1 & 2
// Variant 1: Check if two numbers sum to target using two-pointer approach
    string twoSumExists3(vector<int> arr, int target) {
        int n = arr.size();
        // Sort based on the element values
        sort(arr.begin(), arr.end());
        int left = 0, right = n - 1;
        // Loop until pointers cross
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == target) {
                return "YES";  // Pair found
            } else if (sum < target) {
                left++;  // Need bigger sum, move left pointer right
            } else {
                right--; // Need smaller sum, move right pointer left
            }
        }
        return "NO";  // No pair found
    }
    // Variant 2: Return original indices of two numbers that sum to target
    vector<int> twoSumIndices3_2(vector<int> arr, int target) {
        int n = arr.size();
        vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < n; i++) {
            numsWithIndex.push_back({arr[i], i});
        }
        sort(numsWithIndex.begin(), numsWithIndex.end());

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = numsWithIndex[left].first + numsWithIndex[right].first;
            if (sum == target) {
                // Return original indices
                return {numsWithIndex[left].second, numsWithIndex[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};  // No pair found
    }



int main() {
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    cout << twoSumExists3(arr, target) << "\n";
    vector<int> res = twoSumIndices3_2(arr, target);
    cout << "[" << res[0] << ", " << res[1] << "]\n";

    return 0;
}