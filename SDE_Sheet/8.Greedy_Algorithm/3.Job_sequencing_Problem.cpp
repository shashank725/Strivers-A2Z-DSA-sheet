#include <iostream>
using namespace std;
#include <algorithm>


// Optimal Approach
// TC: O(N log N) + O(N * M)
// SC: O(M) where M is the maximum deadline
// A structure to represent a job 
struct Job {
   // Job Id
   int id; 
   // Deadline of job
   int dead;
   // Profit if job is completed before or on the deadline 
   int profit; 
};

class Solution {
    public:
        // Comparator function to sort jobs in decreasing order of profit
        bool static comparison(Job a, Job b) {
            // Sort by profit in descending order
            return (a.profit > b.profit); 
        }

    // Function to find the maximum profit and the number of jobs done
    pair < int, int > JobScheduling(Job arr[], int n) {
        // Sort the jobs based on decreasing profit
        sort(arr, arr + n, comparison);
        // Find the maximum deadline among all jobs
        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++) {
        // Get the latest deadline
        maxi = max(maxi, arr[i].dead);  
        }
        // Initialize the slot array to track which time slots are taken
        // int slot[maxi + 1];
        // for (int i = 0; i <= maxi; i++)
        // // Mark all slots as unoccupied initially
        //     slot[i] = -1;
        // Using a vector to represent the slots
        vector<int> slot(maxi + 1, -1);

        int countJobs = 0, jobProfit = 0;
        // Iterate through all jobs to find the best possible schedule
        for (int i = 0; i < n; i++) {
            // Find a slot for the current job (starting from its deadline)
            for (int j = arr[i].dead; j > 0; j--) {
            // If the slot is available
            if (slot[j] == -1) {  
                // Assign the job to the slot
                slot[j] = i;  
                // Increment the number of jobs done
                countJobs++;  
                // Add the profit of the job
                jobProfit += arr[i].profit;  
                break;
            }
            }
        }
        // Return the number of jobs done and the total profit
        return make_pair(countJobs, jobProfit);
    }
};

int main() {
    // int n = 4; Variable Length Array is not allowed in C++. Use a constant or dynamic allocation instead.
    const int n = 4;
    // Define jobs with id, deadline, and profit
    Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};
    Solution ob;
    // Function call to find the number of jobs done and total profit
    pair < int, int > ans = ob.JobScheduling(arr, n);
    // Output the number of jobs and the total profit
    cout << ans.first << " " << ans.second << endl;
    return 0;
}