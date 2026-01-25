#include <iostream>
using namespace std;

// Brute Force Approach
// TC: O(N^2)
// SC: O(1)
int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
            maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
        }

    return maxPro;
}


// Optimal Approach
// TC: O(N)
// SC: O(1)
int maxProfit2(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
}



int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit2(arr);
    cout << "Max profit is: " << maxPro << endl;
}
