#include <iostream>
using namespace std;

// Brute Force Approach
// TC: O(N2)
// SC: O(1)
vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
    int n = nums.size(); 
    int repeating = -1, missing = -1;
    // Find the repeating and missing number:
    for (int i = 1; i <= n; i++) {
        // Count the occurrences:
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == i) cnt++;
        }
        // Check if i is repeating or missing
        if (cnt == 2) repeating = i;
        else if (cnt == 0) missing = i;
        /* If both repeating and missing
        are found, break out of loop*/
        if (repeating != -1 && missing != -1)
            break;
    }
    // Return {repeating, missing}
    return {repeating, missing};
}


// Better Approach
// TC: O(2*N)
// SC: O(N)
vector<int> findMissingRepeatingNumbers2(vector<int>& nums) {
    int n = nums.size(); 
    // Hash array to count occurrences
    // int hash[n + 1] = {0}; C++ does not allow variable length arrays
    vector<int> hash(n + 1, 0);
    // Update the hash array:
    for (int i = 0; i < n; i++) {
        hash[nums[i]]++;
    }
    int repeating = -1, missing = -1;
    // Find the repeating and missing number:
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) {
            repeating = i;
        } else if (hash[i] == 0) {
            missing = i;
        }
        /* If both repeating and missing 
        are found, break out of loop*/
        if (repeating != -1 && missing != -1) {
            break;
        }
    }
    return {repeating, missing};
}


// Optimal Approach I
// TC: O(N)
// SC: O(1)
vector<int> findMissingRepeatingNumbers3(vector<int>& nums) {
    long long n = nums.size(); 
    // Sum of first n natural numbers
    long long SN = (n * (n + 1)) / 2;
    // Sum of squares of first n natural numbers
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    /*Calculate actual sum (S) and sum 
    of squares (S2) of array elements*/
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += nums[i];
        S2 += (long long)nums[i] * (long long)nums[i];
    }
    //Compute the difference values
    long long val1 = S - SN; 
    // S2 - S2n = X^2 - Y^2
    long long val2 = S2 - S2N; 
    //Calculate X + Y using X + Y = (X^2 - Y^2) / (X - Y)
    val2 = val2 / val1;
    /* Calculate X and Y from X + Y and X - Y
        X = ((X + Y) + (X - Y)) / 2
        Y = X - (X - Y)*/
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
}


// Optimal Approach II
// TC: O(N)
// SC: O(1)
vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
    int n = nums.size(); 
    int xr = 0;
    for (int i = 0; i < n; i++) {
        // XOR of all elements in nums
        xr = xr ^ nums[i]; 
        // XOR of numbers from 1 to n
        xr = xr ^ (i + 1);  
    }
    // Get the rightmost set bit in xr
    int number = (xr & ~(xr - 1));
    //Group the numbers based on the differentiating bit
    // Number that falls into the 0 group
    int zero = 0; 
    // Number that falls into the 1 group
    int one = 0;  
    for (int i = 0; i < n; i++) {
        /* Check if nums[i] belongs to the 1 group
        based on the differentiating bit*/
        if ((nums[i] & number) != 0) {
            // XOR operation to find numbers in the 1 group
            one = one ^ nums[i];
        } else {
            // XOR operation to find numbers in the 0 group
            zero = zero ^ nums[i]; 
        }
    }
    // Group numbers from 1 to n based on differentiating bit
    for (int i = 1; i <= n; i++) {
        /* Check if i belongs to the 1 group 
        based on the differentiating bit*/
        if ((i & number) != 0) {
            // XOR operation to find numbers in the 1 group
            one = one ^ i; 
        } else {
            // XOR operation to find numbers in the 0 group
            zero = zero ^ i; 
        }
    }
    // Count occurrences of zero in nums
    int cnt = 0; 
    for (int i = 0; i < n; i++) {
        if (nums[i] == zero) {
            cnt++;
        }
    }
    if (cnt == 2) {
        /*zero is the repeating number,
        one is the missing number*/
        return {zero, one}; 
    }
    /* one is the repeating number, 
    zero is the missing number*/
    return {one, zero}; 
}



int main() {
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> result = findMissingRepeatingNumbers2(nums);
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    return 0;
}
