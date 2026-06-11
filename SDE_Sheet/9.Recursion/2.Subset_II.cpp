#include <iostream>
#include <set>
using namespace std;


// Brute Force Approach
// TC: O(N² * 2^N)
// SC: O(N * 2^N)
class Solution {
public:
    // Recursive helper to generate all subsets
    void findSubsets(int ind, vector<int>& nums, vector<int>& ds, set<vector<int>>& result) {
        // Base case: if we've considered all elements, add the current subset to the result set
        if (ind == nums.size()) {
            result.insert(ds);
            return;
        }
        // Choice 1: Include the element at the current index
        ds.push_back(nums[ind]);
        findSubsets(ind + 1, nums, ds, result);
        // Backtrack to explore the other choice
        ds.pop_back();
        // Choice 2: Do not include the element at the current index
        findSubsets(ind + 1, nums, ds, result);
    }

    // Main function to find all unique subsets
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> ds;
        // Sort the array to handle duplicates consistently
        sort(nums.begin(), nums.end());
    
        findSubsets(0, nums, ds, result);
        // Convert the set of unique subsets to a vector for the final answer
        vector<vector<int>> ans(result.begin(), result.end());
        return ans;
    }
};


// Optimal Approach
// TC: O(N^2)
// SC: O(N log N) due to sorting
class Solution2 {
public:
    // Function to generate all unique subsets
    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to result
        result.push_back(current);
        // Iterate over the array from 'start' index
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates: if current number is same as previous and not at the start index
            if (i > start && nums[i] == nums[i - 1]) continue;
            // Include nums[i] in current subset
            current.push_back(nums[i]);
            // Recurse for next index
            backtrack(i + 1, nums, current, result);
            // Backtrack: remove last added element
            current.pop_back();
        }
    }

    // Main function to get unique subsets
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort the array to handle duplicates
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        // Start backtracking from index 0
        backtrack(0, nums, current, result);
        return result;
    }
};


// Driver code to test the solution
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = sol.subsetsWithDup(nums);
    cout << "[ ";
    for (const auto& subset : ans) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;
    return 0;
}