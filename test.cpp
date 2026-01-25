#include <iostream>
#include <unordered_set>
using namespace std;

// Brute Force Approach
// TC: O(N^2)
// SC: O(1)
int longestNonRepeatingSubstring(string &s) {
    // Length of the input string
    int n = s.size(); 
    //Variable to store max length
    int maxLen = 0;    
    /* Iterate through all possible 
    starting points of the substring*/
    for (int i = 0; i < n; i++) {
        /* Hash to track characters in 
        the current substring window*/
        // Assuming extended ASCII characters
        vector<int> hash(256, 0);  
        for (int j = i; j < n; j++) {
            /* If s[j] is already in the
            current substring window*/
            if (hash[s[j]] == 1) break;  
            /* Update the hash to mark s[j]
            as present in the current window*/
            hash[s[j]] = 1;
            /* Calculate the length of
            the current substring*/
            int len = j - i + 1;
            /* Update maxLen if the current
            substring length is greater*/
            maxLen = max(maxLen, len);
        }
    }
    // Return the maximum length
    return maxLen; 
}


// Better Approach
// TC: O(2N)
// SC: O(N)
int longestNonRepeatingSubstring(string& s) {
    int n = s.length();
    if(n==0) return 0;
    int ans = 0;
    unordered_set<int> set;
    int l=0;
    for(int r=0;r<n;r++){
        if(set.find(s[r]) != set.end()){
            while(l<r && set.find(s[r]) != set.end()){
                set.erase(s[l]);
                l++;
            }
        }
        set.insert(s[r]);
        ans = max(ans, r-l+1);
    }
    return ans;
}


// Optimal Approach
// TC: O(N)
// SC: O(N)
int longestNonRepeatingSubstring(string& s) {
        int n = s.size();
        // Assuming all ASCII characters
        int HashLen = 256; 
        /* Hash table to store last
        occurrence of each character*/
        vector<int> hash(HashLen, -1);  // int hash[HashLen];
        int l = 0, r = 0, maxLen = 0;
        while (r < n) {
            /* If current character s[r] 
            is already in the substring*/
            if (hash[s[r]] != -1) {
                /* Move left pointer to the right
                of the last occurrence of s[r]*/
                l = max(hash[s[r]] + 1, l);
            }
            // Calculate the current substring length
            int len = r - l + 1;
            // Update maximum length found so far
            maxLen = max(len, maxLen);
            /* Store the index of the current
            character in the hash table*/
            hash[s[r]] = r;
            // Move right pointer to next position
            r++;
        }
        // Return the maximum length found
        return maxLen;
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



// int main() {
// 	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     int t;
// 	cin>> t;
// 	while(t--) {
//         int n;
// 		cin>>n;
// 	}
// }