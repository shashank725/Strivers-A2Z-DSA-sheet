#include <iostream>
using namespace std;

// Brute Force Approach
// TC: O(N),
// SC: O(1) 
double myPow(double x, int n) {
    // Base case: any number to the power of 0 is 1
    if (n == 0 || x == 1.0) return 1; 
    long long temp = n; // to avoid integer overflow
    // Handle negative exponents
    if (n < 0) { 
        x = 1 / x;
        temp = -1*1LL*n;
    }
    double ans = 1;
    for (long long i = 0; i < temp; i++) {
        // Multiply ans by x for n times
        ans *= x; 
    }
    return ans;
}


// Optimal Approach
// TC: O(log N)
// SC: O(log N)
double power(double x, long n) {
    // Base case: anything raised to 0 is 1
    if (n == 0) return 1.0;
    // Base case: anything raised to 1 is itself
    if (n == 1) return x;
    // If 'n' is even
    if (n % 2 == 0) {
        // Recursive call: x * x, n / 2
        return power(x * x, n / 2);
    }
    // If 'n' is odd
    // Recursive call: x * power(x, n-1)
    return x * power(x, n - 1);
}
// Function to calculate x raised to n
double myPow2(double x, int n) {
    // Store the value of n in a separate variable
    long num = n;
    // If n is negative
    if (num < 0) {
        // Calculate the power of -n and take reciprocal
        return (1.0 / power(x, -1 * num));
    }
    // If n is non-negative
    return power(x, num);
}

// OR (Without recursion)
double myPow(double x, int n) {
    double ans = 1;
    long nn = n;
    if(nn<0) nn=-1*nn;
    while(nn){
        if(nn%2){
            ans=ans*x;
            nn=nn-1;
        } else {
            x=x*x;
            nn=nn/2;
        }
    }
    if(n<0) ans = (double) 1.0 / (double) ans;
    return ans;
}



int main() {
    double x = 2.0;
    int n = 10;
    double result = myPow(x, n);
    // Print the result
    cout << x << "^" << n << " = " << result << endl;

}