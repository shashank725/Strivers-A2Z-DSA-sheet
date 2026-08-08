#include <iostream>
#include <numeric>
using namespace std;

// Problem Statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split. A subarray is a contiguous part of the array. 

// Brute Force Approach
// TC: O(N^2 * log(sum(A))) where sum(A) is the sum of all elements in the array
// SC: O(1)
class SubarrayPartitioner {
public:
    int countPartitions(vector<int> &a, int maxSum) {
        int n = a.size(); // size of the array
        int partitions = 1; // always have at least 1 partition
        long long subarraySum = 0; // sum of the current subarray
        for (int i = 0; i < n; i++) {
            // If adding this element doesn't exceed maxSum, keep adding to current subarray
            if (subarraySum + a[i] <= maxSum) {
                subarraySum += a[i];
            }
            else {
                // Otherwise, start a new subarray
                partitions++;
                subarraySum = a[i];
            }
        }
        return partitions;
    }
    int largestSubarraySumMinimized(vector<int> &a, int k) {
        // Lower bound: max element in array (can't be smaller than that)
        int low = *max_element(a.begin(), a.end());
        // Upper bound: sum of entire array (only one subarray)
        int high = accumulate(a.begin(), a.end(), 0);

        // Brute-force: test each possible maxSum from low to high
        for (int maxSum = low; maxSum <= high; maxSum++) {
            // If we can form exactly k partitions with this maxSum, return it
            if (countPartitions(a, maxSum) == k)
                return maxSum;
        }
        return low; // fallback
    }
};


// Optimal Approach
// TC: O(N * log(sum(A))) where sum(A) is the sum of all
// SC: O(1)
class SubarrayPartitioner {
public:
    int countPartitions(vector<int>&a, int maxSum) {
        int partitions = 1; // at least one partition
        long subarraySum = 0; // sum of current subarray

        for (int num : a) {
            if (subarraySum + num <= maxSum) {
                subarraySum += num;
            } else {
                partitions++;
                subarraySum = num;
            }
        }
        return partitions;
    }

    int largestSubarraySumMinimized(vector<int>& a, int k) {
        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);
        // Binary search for the smallest maxSum
        while (low <= high) {
            int mid = (low + high) / 2;
            int partitions = countPartitions(a, mid);

            if (partitions > k) {
                low = mid + 1; // too many partitions → increase maxSum
            } else {
                high = mid - 1; // valid but try smaller maxSum
            }
        }
        return low;
    }
};



int main() {
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    SubarrayPartitioner sp; // Create object
    int ans = sp.largestSubarraySumMinimized(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}