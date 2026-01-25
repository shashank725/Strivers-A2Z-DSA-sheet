#include <iostream>
using namespace std;

// Brute Force Approach
// TC: O(N^2)
// SC: O(1) 
vector<int> majorityElementTwo(vector<int>& nums) {
    int n = nums.size(); 
    // List of answers
    vector<int> result;
    for (int i = 0; i < n; i++) {
        /*Checking if nums[i] is not 
        already part of the answer*/
        if (result.size() == 0 || result[0] != nums[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of nums[i]
                if (nums[j] == nums[i]) {
                    cnt++;
                }
            }
            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                result.push_back(nums[i]);
        }
        //if result size is equal to 2 break out of loop
        if (result.size() == 2) break;
    }
    //return the majority elements
    return result;
}


// Better Approach
// TC: O(N)
// SC: O(N)
vector<int> majorityElementTwo2(vector<int>& nums) {
    int n = nums.size(); 
    // list of answers
    vector<int> result; 
    // declaring a map
    unordered_map<int, int> mpp;
    // least occurrence of the majority element
    int mini = int(n / 3) + 1;
    // storing the elements with its occurrence
    for (int i = 0; i < n; i++) {
        mpp[nums[i]]++;
        // checking if nums[i] is the majority element
        if (mpp[nums[i]] == mini) {
            result.push_back(nums[i]);
        }
        // if result size is equal to 2 break out of loop
        if (result.size() == 2) {
            break;
        }
    }
    // return the majority elements
    return result;
}


// Optimal Approach
// TC: O(N)
// SC: O(1)
// Moore's Voting Algorithm
vector<int> majorityElementTwo3(vector<int>& nums) {
    int n = nums.size(); 
    // Counts for elements el1 and el2
    int cnt1 = 0, cnt2 = 0;
    /*Initialize Element 1 and 
    Element 2 with INT_MIN value*/
    int el1 = INT_MIN, el2 = INT_MIN;
    /*Find the potential candidates using
    Boyer Moore's Voting Algorithm*/
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != nums[i]) {
            cnt1 = 1;
            // Initialize el1 as nums[i]
            el1 = nums[i]; 
        }
        else if (cnt2 == 0 && el1 != nums[i]) {
            cnt2 = 1;
            // Initialize el2 as nums[i]
            el2 = nums[i]; 
        } 
        else if (nums[i] == el1) {
            // Increment count for el1
            cnt1++;
        } 
        else if (nums[i] == el2) {
            // Increment count for el2
            cnt2++; 
        } 
        else {
            // Decrement count for el1
            cnt1--; 
                // Decrement count for el2
            cnt2--;
        }
    }
    //Validate the candidates by counting occurrences in nums
    //Reset counts for el1 and el2
    cnt1 = 0, cnt2 = 0; 
    for (int i = 0; i < n; i++) {
        if (nums[i] == el1) {
            // Count occurrences of el1
            cnt1++; 
        }
        if (nums[i] == el2) {
                // Count occurrences of el2
            cnt2++;
        }
    }
    /* Determine the minimum count
    required for a majority element*/
    int mini = n / 3 + 1;
    // List of answers
    vector<int> result; 
    /*Add elements to the result vector
    if they appear more than n/3 times*/
    if (cnt1 >= mini) {
        result.push_back(el1);
    }
    if (cnt2 >= mini && el1 != el2) {
        // Avoid adding duplicate if el1 == el2
        result.push_back(el2); 
    }
    // Uncomment the following line if you want to sort the answer array
    // sort(result.begin(), result.end()); // TC --> O(2*log2) ~ O(1);
    //return the majority elements
    return result;
}



int main() {
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElementTwo3(arr);
    // Print the majority element̆s found
    cout << "The majority elements are: ";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}