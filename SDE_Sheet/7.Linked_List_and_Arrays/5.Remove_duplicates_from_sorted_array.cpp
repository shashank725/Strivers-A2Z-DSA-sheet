#include <iostream>
#include <unordered_set>
using namespace std;



// Brute Force Approach
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Unordered set to store elements we have already seen
        unordered_set<int> seen;
        // Index where the next unique element will be written
        int index = 0;
        // Loop over each element in the array
        for (int num : nums) {
            // If num is not in seen, it's unique
            if (seen.find(num) == seen.end()) {
                // Add this num to the set of seen numbers
                seen.insert(num);
                // Overwrite nums[index] with this unique num
                nums[index] = num;
                // Move index forward
                index++;
            }
        }
        // Return count of unique elements
        return index;
    }
};


// Optimal Approach
// TC: O(N)
// SC: O(1)
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        // If array is empty, return 0 directly
        if (nums.empty()) return 0;
        // Pointer for the position of last unique element
        int i = 0;
        // Traverse the array starting from the second element
        for (int j = 1; j < nums.size(); j++) {
            // If current element is different from last unique element
            if (nums[j] != nums[i]) {
                // Move pointer for unique element forward
                i++;
                // Place the new unique element at the next position
                nums[i] = nums[j];
            }
        }
        // i is index of last unique element, count = i + 1
        return i + 1;
    }
};



// Driver code
int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution sol;
    int k = sol.removeDuplicates(nums);
    cout << "Unique count = " << k << "\n";
    cout << "Array after removing duplicates: ";
    for (int x = 0; x < k; x++) {
        cout << nums[x] << " ";
    }
    cout << endl;
} 