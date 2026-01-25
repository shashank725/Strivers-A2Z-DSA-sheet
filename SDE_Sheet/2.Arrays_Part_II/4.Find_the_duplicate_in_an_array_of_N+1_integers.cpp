#include <iostream>
using namespace std;

// Brute Force Approach
// TC: O(N2)
// SC: O(1)
int findDuplicate(vector<int>& arr) {
  int n = arr.size();
  // sort array in-place
  sort(arr.begin(), arr.end());
  // scan adjacent pairs
  for (int i = 0; i < n - 1; i++) {
    // return when a duplicate is found
    if (arr[i] == arr[i + 1]) {
      return arr[i];
    }
  }
  // fallback if no duplicate found
  return -1;
}


// Better Approach
// TC: O(N)
// SC: O(N)
int findDuplicate2(vector<int>& arr) {
  int n = arr.size();
  // allocate frequency array initialized to 0
  vector<int> freq(n + 1, 0);
  // scan elements
  for (int i = 0; i < n; i++) {
    // return current value if already seen
    if (freq[arr[i]] == 0) {
      // mark as seen
      freq[arr[i]] += 1;
    } else {
      // duplicate found
      return arr[i];
    }
  }
  // fallback if none (per original)
  return 0;
}


// Optimal Approach
// TC: O(N)
// SC: O(1)
// Floyd's Tortoise and Hare cycle detection
int findDuplicate3(vector<int>& nums) {
  // initialize pointers at the start
  int slow = nums[0];
  int fast = nums[0];
  // move slow by 1 step and fast by 2 steps until they meet
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  // reset fast to start to find the entrance to the cycle
  fast = nums[0];
  // move both by 1 step until they meet at the duplicate
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  // return the duplicate value
  return slow;
}



int main() {
  vector<int> arr = {1, 3, 4, 2, 3};
  cout << "The duplicate element is " << findDuplicate3(arr) << endl;
  return 0;
}