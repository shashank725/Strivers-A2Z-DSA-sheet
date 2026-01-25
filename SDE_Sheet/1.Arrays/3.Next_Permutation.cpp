#include <iostream>
using namespace std;

// Brute Force Approach
// TC: O(N!*N)
// SC: O(1)
void recurPermute(int index, vector<int>& nums, vector<vector<int>>& ans){
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i = index; i < nums.size(); i++){
        swap(nums[i], nums[index]);
        recurPermute(index + 1, nums, ans);
        swap(nums[i], nums[index]);
    }
}
void nextPermutation(vector<int>& nums){
    vector<vector<int>> ans;
    recurPermute(0, nums, ans);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == nums){
            if(i == ans.size() - 1){
                nums = ans[0];
                return;
            }
            else{
                nums = ans[i + 1];
                return;
            }
        }
    }
}


// Using in-built function
// next_permutation(arr,arr+n);


// Optimal Approach
// TC: O(3N)
// SC: O(1)
vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); // size of the array.
    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }
    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }
    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }
    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

int main() {
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    //nextPermutation(A);
    nextGreaterPermutation(A);
    cout << "The next permutation is: [";
    for (auto it : A) {
        cout << it << " ";
    }
    cout << "]";
    return 0;
}