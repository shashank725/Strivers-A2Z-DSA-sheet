#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

// Brute Force Approach
// TC: O(N4)
// SC: O(2 * no. of the quadruplets)
vector<vector<int>> fourSum(vector<int>& arr, int target) {
    // Get size of array
    int n = arr.size();
    // Use set to avoid duplicate quadruplets
    set<vector<int>> st;
    // First loop - pick first element
    for (int i = 0; i < n; i++) {
        // Second loop - pick second element
        for (int j = i + 1; j < n; j++) {
            // Third loop - pick third element
            for (int k = j + 1; k < n; k++) {
                // Fourth loop - pick fourth element
                for (int l = k + 1; l < n; l++) {
                    // Calculate sum of four chosen numbers
                    long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];
                    // Check if sum matches target
                    if (sum == target) {
                        // Store quadruplet in sorted order
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        // Insert into set to ensure uniqueness
                        st.insert(temp);
                    }
                }
            }
        }
    }
    // Convert set into vector of quadruplets
    return vector<vector<int>>(st.begin(), st.end());
}


// Better Approach
// TC: O(N3*log(M))
// SC: O(2 * no. of the quadruplets)+O(N)
vector<vector<int>> fourSum2(vector<int>& arr, int target) {
        int n = arr.size();
        set<vector<int>> st;  
        // First loop - pick first number
        for (int i = 0; i < n; i++) {
            // Second loop - pick second number
            for (int j = i + 1; j < n; j++) {
                // HashSet to store numbers between j and k
                unordered_set<int> seen;
                // Third loop - pick third number
                for (int k = j + 1; k < n; k++) {
                    // Find required fourth number
                    long long required = (long long)target - arr[i] - arr[j] - arr[k];
                    // If required number is already in set, we found a quadruplet
                    if (seen.count(required)) {
                        vector<int> temp = {arr[i], arr[j], arr[k], (int)required};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    // Add current third number into set
                    seen.insert(arr[k]);
                }
            }
        }
        // Convert set into vector and return
        return vector<vector<int>>(st.begin(), st.end());
    }


// Optimal Approach
// TC: O(N3)
// SC: O(no. of quadruplets)
vector<vector<int>> fourSum3(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> ans;
    // Step 1: Sort array
    sort(arr.begin(), arr.end());
    // Step 2: First loop for first number
    for (int i = 0; i < n; i++) {
        // Skip duplicates for first number
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        // Step 3: Second loop for second number
        for (int j = i + 1; j < n; j++) {
            // Skip duplicates for second number
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
            // Step 4: Two pointers for remaining two numbers
            int left = j + 1, right = n - 1;
            while (left < right) {
                long long sum = (long long)arr[i] + arr[j] +
                                arr[left] + arr[right];
                if (sum == target) {
                    ans.push_back({arr[i], arr[j],
                                    arr[left], arr[right]});
                    // Move left pointer skipping duplicates
                    while (left < right && arr[left] == arr[left + 1])
                        left++;
                    // Move right pointer skipping duplicates
                    while (left < right && arr[right] == arr[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (sum < target) left++;
                else right--;
            }
        }
    }
    return ans;
}



int main() {
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ans = fourSum3(arr, target);
    for (auto quad : ans) {
        for (int num : quad) cout << num << " ";
        cout << endl;
    }
    return 0;
}