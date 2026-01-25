#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

// Brute Force Approach
// TC: O(N2)
// SC: O(1)
bool linearSearch(vector<int>& a, int num) {
    int n = a.size(); 
    // Traverse through the array 
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
// Function to find the longest consecutive sequence
int longestConsecutive(vector<int>& nums) {
    // If the array is empty
    if (nums.size() == 0) {
        return 0;
    }
    int n = nums.size();
    // Initialize the longest sequence length
    int longest = 1; 
    // Iterate through each element in the array
    for (int i = 0; i < n; i++) {
        // Current element
        int x = nums[i]; 
        // Count of the current sequence
        int cnt = 1; 
        // Search for consecutive numbers
        while (linearSearch(nums, x + 1) == true) {
            // Move to the next number in the sequence
            x += 1; 
            // Increment the count of the sequence
            cnt += 1; 
        }
        // Update the longest sequence length found so far
        longest = max(longest, cnt);
    }
    return longest;
}


// Better Approach
// TC: O(N log N)
// SC: O(1)
int longestConsecutive2(vector<int>& nums) {
    int n = nums.size();
    // Return 0 if array is empty
    if (n == 0) return 0; 
    sort(nums.begin(), nums.end()); 
    // Track last smaller element
    int lastSmaller = INT_MIN; 
    // Count current sequence length
    int cnt = 0; 
    // Track longest sequence length
    int longest = 1; 
    for (int i = 0; i < n; i++) {
        // If consecutive number exists
        if (nums[i] - 1 == lastSmaller) {
            // Increment sequence count
            cnt += 1; 
            // Update last smaller element
            lastSmaller = nums[i]; 
        } 
        // If consecutive number doesn't exits
        else if (nums[i] != lastSmaller) {
            // Reset count for new sequence
            cnt = 1; 
            // Update last smaller element
            lastSmaller = nums[i]; 
        }
        // Update longest if needed
        longest = max(longest, cnt); 
    }
    return longest;
}


// Optimal Approach
// TC: O(N)
// SC: O(N)
int longestConsecutive3(vector<int>& a) {
    int n = a.size();
    // If the array is empty
    if (n == 0) return 0; 
    // Initialize the longest sequence length
    int longest = 1; 
    unordered_set<int> st;
    // Put all the array elements into the set
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }
    /* Traverse the set to 
        find the longest sequence  */
    for (auto it : st) {
        // Check if 'it' is a starting number of a sequence
        if (st.find(it - 1) == st.end()) {
            // Initialize the count of the current sequence
            int cnt = 1; 
            // Starting element of the sequence
            int x = it; 
            // Find consecutive numbers in the set
            while (st.find(x + 1) != st.end()) {
                // Move to the next element in the sequence
                x = x + 1; 
                // Increment the count of the sequence
                cnt = cnt + 1; 
            }
            // Update the longest sequence length
            longest = max(longest, cnt);
        }
    }
    return longest;
}



int main() {
    vector<int> a = {100, 4, 200, 1, 3, 2}; 
    // Function call for finding longest consecutive sequence
    int ans = longestConsecutive3(a); 
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}