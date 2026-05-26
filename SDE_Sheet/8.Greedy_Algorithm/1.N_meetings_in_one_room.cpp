#include <iostream>
using namespace std;


// Optimal Approach
// TC: O(N*logN) + O(N)
// SC: O(N)
class Solution {
public:
    vector<int> maxMeetings(vector<int>& start, vector<int>& end) {
        // Store meetings as (end_time, start_time, original_index)
        vector<tuple<int, int, int>> meetings;
        for (int i = 0; i < start.size(); i++) {
            meetings.push_back({end[i], start[i], i + 1});
        }
        sort(meetings.begin(), meetings.end());
        
        vector<int> result;
        int last_end_time = -1; // Initialize to a time before any meeting starts
        for(auto& meeting : meetings) {
            int end_time = get<0>(meeting);
            int start_time = get<1>(meeting);
            int original_index = get<2>(meeting);
            // If meeting starts after last one ends
            if (start_time > last_end_time) {
                result.push_back(original_index);
                last_end_time = end_time;
            }
        }
        return result;
    }
};

// Main driver code
int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};
    Solution sol;
    vector<int> res = sol.maxMeetings(start, end);
    for (int idx : res) cout << idx << " ";
}