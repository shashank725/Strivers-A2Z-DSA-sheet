#include <iostream>
using namespace std;

// Brute Force Approach
// TC: O(N^2)
// SC: O(1) 
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    // Iterate through each element of the array
    for (int i = 0; i < n; i++) {
        // Counter to count occurrences of nums[i]
        int cnt = 0; 
        // Count the frequency of nums[i] in the array
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) {
                cnt++;
            }
        }
        // Check if frequency of nums[i] is greater than n/2
        if (cnt > (n / 2)) {
            // Return the majority element
            return nums[i]; 
        }
    }
    
    // Return -1 if no majority element is found
    return -1; 
}


// Better Approach
// TC: O(N)
// SC: O(N)
int majorityElement2(vector<int>& nums) {
    int n = nums.size();
    // Hash map to store element counts
    unordered_map<int, int> mp;
    // Count occurrences of each element
    for (int num : nums) {
        mp[num]++;
    }
    /* Iterate through the map to
    find the majority element*/
    for (auto& pair : mp) {
        if (pair.second > n / 2) {
            return pair.first;
        }
    }
    // Return -1 if no majority element is found
    return -1;
}


// Optimal Approach
// TC: O(N)
// SC: O(1)
// Moore's Voting Algorithm
int majorityElement3(vector<int>& nums) {
    int n = nums.size();
    // Count
    int cnt = 0;
    // Element
    int el; 
    // Applying the algorithm
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = nums[i];
        } else if (el == nums[i]) {
            cnt++;
        } else {
            cnt--;
        }
    }
    /* Checking if the stored element
        is the majority element*/
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el) {
            cnt1++;
        }
    }
    //return element if it is a majority element
    if (cnt1 > (n / 2)) {
        return el;
    }
    //return -1 if no such element found
    return -1;
}



int main() {
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}