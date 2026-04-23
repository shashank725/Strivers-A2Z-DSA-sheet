#include <iostream>
#include <unordered_set>
using namespace std;



// Brute Force Approach
// TC: O(N)
// SC: O(1)
class Solution {
public:

};


// Better Approach
// TC: O(3N)
// SC: O(N)
class Solution2 {
public:
   
};


// Optimal Approach
// TC: O(N)
// SC: O(1)
class Solution3 {
public:
    
};



// Driver code
int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution sol;
    int k = sol.removeDuplicates(nums);
    cout << "Unique count = " << k << "\n";
    cout << "Array after removing duplicates: ";
    for (int x = 0; x < k; x++) {
        cout << nums[x] << " ";
    }
    cout << endl;
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