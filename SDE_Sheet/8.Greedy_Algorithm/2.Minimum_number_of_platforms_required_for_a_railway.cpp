#include <iostream>
using namespace std;

// Brute Force Approach
// TC: O(N^2)
// SC: O(1)
class Solution {
public:
    // Function to count minimum platforms needed
    int countPlatforms(int n, int arr[], int dep[]) {
        // Initialize answer to 1
        int ans = 1;
        // Loop over all arrival times
        for (int i = 0; i < n; i++) {
            // Initialize count of overlapping intervals
            int count = 1;
            // Check overlap with every other train
            for (int j = i + 1; j < n; j++) {
                // Check if there is overlap between train i and j
                if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                    (arr[j] >= arr[i] && arr[j] <= dep[i])) {
                    count++;
                }
            }
            // Update maximum platform count
            ans = max(ans, count);
        }
        return ans;
    }
};


// Optimal Approach
// TC: O(N)
// SC: O(1)
class Solution2 {
    public:
    int countPlatforms(int n, int arr[], int dep[]) {
        // Sort arrival and departure times
        sort(arr, arr + n);
        sort(dep, dep + n);
        // Initialize pointers and platform count
        int i = 0, j = 0, platforms = 0, maxPlatforms = 0;

        // Traverse through arrival and departure arrays
        while (i < n && j < n) {
            // If next event is arrival, increment platform count
            if (arr[i] < dep[j]) {
                platforms++;
                maxPlatforms = max(maxPlatforms, platforms);
                i++;
            } else { // If next event is departure, decrement platform count
                platforms--;
                j++;
            }
        }
        return maxPlatforms;
    }
};



int main() {
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create Solution object and call function
    Solution obj;
    cout << "Minimum number of Platforms required "
         << obj.countPlatforms(n, arr, dep) << endl;

    return 0;
}