#include <iostream>
using namespace std;


// Memoization Approach
// TC: O(n*m)
// SC: O(n*m) + O(n+m)
class Solution {
public:
    // Function to find the maximum number of content students
    int findContentChildren(vector<int>& student, vector<int>& cookie) {
        // Sort both arrays to apply the greedy strategy
        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());
        // Initialize DP table with -1
        vector<vector<int>> memo(student.size(), vector<int>(cookie.size(), -1));
        // Start recursion from index 0 for both arrays
        return helper(0, 0, student, cookie, memo);
    }

private:
    // Recursive helper function with memoization
    int helper(int studentIndex, int cookieIndex, vector<int>& student, vector<int>& cookie, vector<vector<int>>& memo) {
        // Base case: if we reach end of either list
        if (studentIndex >= student.size() || cookieIndex >= cookie.size())
            return 0;
        // Return memoized result if already computed
        if (memo[studentIndex][cookieIndex] != -1)
            return memo[studentIndex][cookieIndex];
        int result = 0;
        // If the cookie satisfies the student's greed
        if (cookie[cookieIndex] >= student[studentIndex]) {
            // Option 1: assign this cookie and move to next student and cookie
            result = max(result, 1 + helper(studentIndex + 1, cookieIndex + 1, student, cookie, memo));
        }
        // Option 2: skip this cookie and try the next one for the same student
        result = max(result, helper(studentIndex, cookieIndex + 1, student, cookie, memo));
        // Store the result in memo table
        return memo[studentIndex][cookieIndex] = result;
    }
};


// Tabulation Approach
// TC: O(n*m)
// SC: O(n*m)
class Solution2 {
public:
    // Function to find the maximum number of content students using tabulation
    int findContentChildren(vector<int>& student, vector<int>& cookie) {
        int n = student.size();
        int m = cookie.size();
        // Sort both arrays to prepare for DP
        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());
        // Create a 2D DP table
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // Fill DP table from bottom up
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                // Skip current cookie
                int skip = dp[i][j + 1];
                // Take current cookie if it satisfies student's greed
                int take = 0;
                if (cookie[j] >= student[i]) {
                    take = 1 + dp[i + 1][j + 1];
                }
                // Take the best of both choices
                dp[i][j] = max(skip, take);
            }
        }
        return dp[0][0];
    }
};


// Can directly use this
// Optimal Approach
// TC: O(n*logn + m*logm)
// SC: O(1)
class Solution3 {
public:
    // Function to find the maximum number of content students
    int findContentChildren(vector<int>& student, vector<int>& cookie) {
        // Sort both arrays to apply the greedy strategy
        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());
        int studentIndex = 0; 
        int cookieIndex = 0;  
        // Try to assign cookies until any one list is fully processed
        while (studentIndex < student.size() && cookieIndex < cookie.size()) {
            // If the cookie satisfies the student's greed
            if (cookie[cookieIndex] >= student[studentIndex]) {
                studentIndex++; 
            }
            // Move to next cookie in both cases
            cookieIndex++; 
        }
        return studentIndex;
    }
};




int main() {
    vector<int> student = {1, 2, 3};
    vector<int> cookie = {1, 1};
    // Create Solution object
    Solution3 solver;
    // Get the number of content students and print it
    int result = solver.findContentChildren(student, cookie);
    cout << "Maximum number of content students: " << result << endl;
    return 0;
}