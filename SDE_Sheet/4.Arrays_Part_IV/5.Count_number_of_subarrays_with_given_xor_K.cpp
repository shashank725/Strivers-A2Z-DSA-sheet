#include <iostream>
using namespace std;

// Brute Force Approach
// TC: O(N^2)
// SC: O(1)
int countSubarraysXOR(vector<int>& A, int B) {
    // Initialize count of valid subarrays
    int count = 0;
    // Traverse all starting points
    for (int i = 0; i < A.size(); i++) {
        // Maintain xor of current subarray
        int xorVal = 0;
        // Extend subarray till end
        for (int j = i; j < A.size(); j++) {
            // Update xor
            xorVal ^= A[j];
            // If xor equals B, increment count
            if (xorVal == B) {
                count++;
            }
        }
    }
    return count;
}


// Optimal Approach
// TC: O(N)
// SC: O(N)
int countSubarraysXOR2(vector<int>& A, int k) {
    // Store frequency of prefix XORs
    unordered_map<int, int> freq;
    // Initialize with prefix XOR 0
    freq[0] = 1;
    // Current prefix XOR
    int prefixXorSum = 0;
    // Answer count
    int count = 0;
    // Traverse array
    for (int num : A) {
        // Update prefix XOR
        prefixXorSum ^= num;
        // Compute required XOR
        int target = prefixXorSum ^ k;
        // If target exists in map, add its frequency
        if (freq.find(target) != freq.end()) {
            count += freq[target];
        }
        // Store current prefix XOR in map
        freq[prefixXorSum]++;
    }
    return count;
}



int main() {
    // Input array
    vector<int> A = {4, 2, 2, 6, 4};
    // Target xor
    int B = 6;
    cout << countSubarraysXOR(A, B) << endl;
    cout << countSubarraysXOR2(A, B) << endl;
    return 0;
}