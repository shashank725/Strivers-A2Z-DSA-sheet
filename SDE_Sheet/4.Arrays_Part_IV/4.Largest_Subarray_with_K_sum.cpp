#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;

// Brute Force Approach (Both positive nad negative numbers)
// TC: O(N log N) &  O(N) if using unordered_map
// SC: O(N)
int longestSubarrayWithSumK(vector<int>& a, long long k) {
    // store best length found so far
    int maxLen = 0;
    // map prefix sum -> first index seen
    map<long long, int> prefixSumMap;
    // running prefix sum
    long long sum = 0;
    // iterate through the array
    for (int i = 0; i < (int)a.size(); i++) {
        // update running sum
        sum += a[i];
        // if sum is k, subarray [0..i] has sum k
        if (sum == k) {
            // update best length
            maxLen = max(maxLen, i + 1);
        }
        // if this sum seen before, subarray (prevIndex..i] has sum k
        long long rem = sum - k;
        if (prefixSumMap.find(rem) != prefixSumMap.end()) {
            // maximize length using previous index
            maxLen = max(maxLen, i - prefixSumMap[rem]);
        }
        // first time seeing this sum, store its index
        if (prefixSumMap.find(sum) == prefixSumMap.end()) {
            prefixSumMap[sum] = i;
        }
    }
    // return best length
    return maxLen;
}


// Optimal Approach (Only positive & Zero numbers)
// TC: O(2N)
// SC: O(1)
int longestSubarrayWithSumK2(vector<int>& a, long long k) {
    int maxLen = 0;
    int left = 0, right = 0; 
    long long sum = a[0];
    while(left <= right && right < a.size()) {
        if (sum == k){
            maxLen = max(maxLen, right - left + 1);
            right++;
            if (right < a.size()) sum += a[right];
        }
        else if (sum < k){
            right++;
            if (right < a.size()) sum += a[right];
        }
        else {
            sum -= a[left];
            left++;
            if (left > right && left < a.size()){
                right = left;
                sum = a[left];
           } 
        }
    }
    return maxLen;
}



int main() {
    // sample input
    vector<int> a = {9, -3, 3, -1, 6, -5};
    vector<int> b = {4, 1, 1, 1, 1, 0, 2, 3, 5};
    cout << longestSubarrayWithSumK(a, 0) << endl;
    cout << longestSubarrayWithSumK2(b, 0) << endl;

    return 0;
}