#include <iostream>
using namespace std;

// TC: Exponential
// SC: Exponential
int func0(int i,int j, int m,int n){
    // Base case
    if (i == 0 && j == 0)  return 1;
    if (i >= m || j >= n)  return 0;
    else return func0(i+1,j, m,n) + func0(i,j+1, m,n);
}
int uniquePaths0(int m, int n) {
    return func0(0,0, m,n);
}

// Brute Force Approach
// TC: O(M*N)
// SC: O(M*N)
// Memoization Approach 
int func1(int i, int j, vector<vector<int>>& dp){
    // Base case
    if (i == 0 && j == 0)  return 1;
    /* If we go out of bounds or reach 
    a blocked cell, there are no ways.*/
    if (i < 0 || j < 0)  return 0;
    /* If we have already computed the number 
    of ways for this cell, return it.*/
    if (dp[i][j] != -1)  return dp[i][j];
    /* Calculate the number of ways by
    moving up and left recursively.*/
    int up = func1(i - 1, j, dp);
    int left = func1(i, j - 1, dp);
    // Store the result in dp table and return it.
    return dp[i][j] = up + left;
}
int uniquePaths1(int m, int n) {
    /* Initialize a memoization table (dp) to
    store the results of subproblems.*/
    vector<vector<int>> dp(m, vector<int>(n, -1));
    //Return the total count(0 based indexing)
    return func1(m-1,n-1, dp);
}


// Brute Force Approach
// TC: O(M*N)
// SC: O(M*N)
// Tabulation Approach 
int func2(int m, int n, vector<vector<int>>& dp){
    // Loop through the grid using two nested loops
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Base condition
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                /* Skip the rest of the loop and 
                continue with the next iteration.*/
                continue; 
            }
            /* Initialize variables to store the number 
            of ways from cell above (up) and left (left)*/
            int up = 0;
            int left = 0;
            /* If we are not at first row (i > 0), update 
            'up' with the value from the cell above.*/
            if (i > 0)
                up = dp[i - 1][j];
            /* If we are not at the first column (j > 0),
            update 'left' with value from the cell to left.*/
            if (j > 0)
                left = dp[i][j - 1];
            /* Calculate the number of ways to reach the 
            current cell by adding 'up' and 'left'.*/
            dp[i][j] = up + left;
        }
    }   
    // The result is stored in bottom-right cell (m-1, n-1).
    return dp[m - 1][n - 1];
}
int uniquePaths2(int m, int n) {
    /* Initialize a memoization table (dp) to
    store the results of subproblems.*/
    vector<vector<int>> dp(m, vector<int>(n, -1));
    //Return the total count(0 based indexing)
    return func2(m, n, dp);
}


// Better Approach
// TC: O(M*N)
// SC: O(N)
int func3(int m, int n){
    /* Initialize a vector to represent 
    the previous row of the grid.*/
    vector<int> prev(n, 0);
    // Iterate through the rows of the grid.
    for (int i = 0; i < m; i++) {
        /* Create a temporary vector to
        represent the current row.*/
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++) {
            // Base case
            if (i == 0 && j == 0) {
                temp[j] = 1;
                continue;
            }
            /* Initialize variables to store the number
            of ways from the cell above (up) and left (left).*/
            int up = 0;
            int left = 0;
            /* If we are not at the first row (i > 0), update
            'up' with the value from the previous row.*/
            if (i > 0)
                up = prev[j];
            /* If we are not at the first column (j > 0),
            update 'left' with the value from current row.*/
            if (j > 0)
                left = temp[j - 1];
            /* Calculate the number of ways to reach the
            current cell by adding 'up' and 'left'.*/
            temp[j] = up + left;
        }
        /* Update the previous row with values 
        calculated for the current row.*/
        prev = temp;
    }
    /* The result is stored in the last
    cell of the previous row (n-1).*/
    return prev[n - 1];
}
int uniquePaths3(int m, int n) {
    //Return the total count(0 based indexing)
    return func3(m, n);
}


// Optimal Approach
// TC: O(M-1) or O(N-1)
// SC: O(1)
int uniquePaths4(int m, int n) {
    int N = m+n-2;
    int r = m-1; // or n-1
    double ans = 1;
    // Calculate the combination C(N, r) using the formula
    // 10C3 = 10*9*8/(3*2*1) [n!/r!(n-r)!]
    for(int i=1;i<=r;i++){
        ans = ans * (N-r+i)/i;
    }
    return (int) ans;
}



int main() {
    int m = 3;
    int n = 2;
    // Call the countWays function and print the result.
    cout << "Number of ways: " << uniquePaths4(m, n) << endl;
    return 0;
}