#include <iostream>
using namespace std;

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// Brute Force Approach
// TC: O((m + n)log(m + n))
// SC: O(m + n)
class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        for (int x : nums1) merged.push_back(x);
        for (int x : nums2) merged.push_back(x);
        // Sort the merged array
        sort(merged.begin(), merged.end());
        int n = merged.size();
        // If even: average of two middle elements
        if (n % 2 == 0) {
            return (merged[n/2 - 1] + merged[n/2]) / 2.0;
        }
        // If odd: middle element
        else {
            return merged[n/2];
        }
    }
};


// Better Approach
// TC: O(m + n)
// SC: O(1)
class Solution2 {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> merged;
        int i = 0, j = 0;
        // Merge both sorted arrays
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        // Copy remaining elements of nums1
        while (i < m) {
            merged.push_back(nums1[i]);
            i++;
        }
        // Copy remaining elements of nums2
        while (j < n) {
            merged.push_back(nums2[j]);
            j++;
        }
        int total = m + n;
        // Odd length
        if (total % 2 == 1) {
            return merged[total / 2];
        }
        // Even length
        return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
    }
};


// Optimal Approach
// TC: O(log(min(m, n)))
// SC: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        while(low <= high) {
            // int cut1 = (low + high) / 2; // Midpoint
            int cut1 = (low+high) >> 1; // Right Shift operator
            int cut2 = (m+n+1)/2 - cut1;
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            int right1 = cut1 == m ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n ? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1) {
                if((m+n)%2 == 0){
                    return (max(left1, left2) + min(right1, right2)) / 2.0 ;
                } else {
                    return max(left1, left2);
                }
            } else if (left1 > right2){
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};