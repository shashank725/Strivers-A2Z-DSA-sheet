#include <iostream>
using namespace std;


// Brute Force Approach
// TC: O(N! × N) + O(N! log N!)
// SC: O(N)
class Solution {
public:
    // Function to generate all possible permutations of a string
    void permutationHelper(string &s, int index, vector<string> &res) {
        if (index == s.size()) {
            res.push_back(s);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            swap(s[i], s[index]);
            permutationHelper(s, index + 1, res);
            swap(s[i], s[index]);
        }
    }

    string getPermutation(int n, int k) {
        string s;
        vector<string> res;
        // Create string with characters '1' to 'n'
        for (int i = 1; i <= n; i++) {
            s.push_back(i + '0');
        }
        permutationHelper(s, 0, res);  // Generate all permutations
        sort(res.begin(), res.end());  // Sort the generated permutations
        // Make k 0-based indexed to point to kth sequence
        auto it = res.begin() + (k - 1);
        return *it;
    }
};


class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++) {
            fact = fact * i;  // Calculate factorial of n-1
            numbers.push_back(i);
        }
        numbers.push_back(n);  // Add last element (n)
        string ans = "";
        k = k - 1;  // Convert k to 0-based index
        while (true) {
            ans = ans + to_string(numbers[k / fact]);  // Add the digit at the position
            numbers.erase(numbers.begin() + k / fact);  // Remove that number from the list
            
            if (numbers.size() == 0) {
                break;  // Exit when all numbers are used
            }
            k = k % fact;  // Reduce k to fit within the remaining sub-permutation
            fact = fact / numbers.size();  // Update factorial for the remaining numbers
        }
        return ans;  // Return the Kth permutation sequence
    }
};



int main() {
    int n = 3, k = 3;
    Solution obj;
    string ans = obj.getPermutation(n, k);
    cout << "The Kth permutation sequence is " << ans << endl;
    return 0;
}