#include <iostream>
using namespace std;

// Problem Description: Given an array arr of distinct integers, print all permutations of the given array. 

// Brute Force Approach
// TC: O(N! * N) 
// SC: O(1)
class Solution {
public:
    void backtrack(int idx, vector<int>& nums, vector<vector<int>>& result) {
        // If current permutation is complete
        if (idx == nums.size()) {
            result.push_back(nums);
            return;
        }
        // Iterate over all elements
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            backtrack(idx+1, nums, result);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, result);
        return result;
    }
};


// Optimal Approach
// TC: O(N! * N)
// SC: O(N! * N) + O(N)
class Solution2 {
public:
    void backtrack(vector<int>& nums, vector<bool>& used,vector<int>& current, vector<vector<int>>& result) {
        // If current permutation is complete
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        // Iterate over all elements
        for (int i = 0; i < nums.size(); i++) {
            // Skip already used elements
            if (used[i]) continue;
            // Include this element
            used[i] = true;
            current.push_back(nums[i]);
            // Recurse for next element
            backtrack(nums, used, current, result);
            // Backtrack: remove element and mark unused
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, current, result);
        return result;
    }
};



int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol;
    // Get all permutations
    vector<vector<int>> permutations = sol.permute(nums);
    // Print all permutations
    for (auto& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}