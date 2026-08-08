#include <iostream>
using namespace std;

// Problem Statement: You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis. You are also given an integer ‘k’. You have to place 'k' new gas stations on the X-axis. You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions. Let 'dist' be the maximum value of the distance between adjacent gas stations after adding k new gas stations. Find the minimum value of ‘dist’.

// Brute Force Approach
// TC : O(k*n) + O(n)
// SC : O(n-1)
class GasStationSolver {
public:
    // Function to minimize the maximum distance after placing k gas stations
    long double minimiseMaxDistance(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> howMany(n - 1, 0); // howMany[i]: extra stations between arr[i] and arr[i+1]
        // Place k gas stations one at a time
        for (int gasStations = 1; gasStations <= k; gasStations++) {
            long double maxSection = -1;
            int maxInd = -1;
            // Find the segment with the current largest section length
            for (int i = 0; i < n - 1; i++) {
                long double diff = arr[i + 1] - arr[i];
                long double sectionLength = diff / (howMany[i] + 1.0);
                if (sectionLength > maxSection) {
                    maxSection = sectionLength;
                    maxInd = i;
                }
            }
            // Add a gas station in the largest segment
            howMany[maxInd]++;
        }
        // Find the final maximum distance after placing all gas stations
        long double maxAns = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (howMany[i] + 1.0);
            maxAns = max(maxAns, sectionLength);
        }
        return maxAns;
    }
};


// Better Approach
// TC: O(k*log(n-1)) + O(n)
// SC: O(n-1)+O(n-1).
class Solution2 {
public:
    // Function to minimize the maximum distance between gas stations
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> howMany(n - 1, 0); // Tracks how many stations in each segment
        priority_queue<pair<long double, int>> pq; // Max-heap
        // Initially insert all segments into the heap with their lengths
        for (int i = 0; i < n - 1; i++) {
            long double length = arr[i + 1] - arr[i];
            pq.push({length, i});
        }
        // Place k additional gas stations
        for (int gasStations = 1; gasStations <= k; gasStations++) {
            auto top = pq.top();
            pq.pop();
            int segmentIndex = top.second;

            // Add a station to the segment and recompute its length
            howMany[segmentIndex]++;
            long double totalDist = arr[segmentIndex + 1] - arr[segmentIndex];
            long double newLen = totalDist / (howMany[segmentIndex] + 1);
            pq.push({newLen, segmentIndex});
        }
        // Final answer is the max segment length at the top of the heap
        return pq.top().first;
    }
};


// Optimal Approach
// TC: O(n*log(Len)) + O(n)
// SC: O(1)
class GasStationOptimizer {
public:
    // Function to calculate number of gas stations required such that
    // no segment exceeds the max allowed distance `dist`
    int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
        int n = arr.size();
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            // Number of stations needed between arr[i-1] and arr[i]
            int numberInBetween = (arr[i] - arr[i - 1]) / dist;
            // If perfectly divisible, reduce one to avoid extra placement
            if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
                numberInBetween--;
            }
            cnt += numberInBetween;
        }
        return cnt;
    }

    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        long double low = 0, high = 0;
        // Determine max initial distance between stations
        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }
        long double diff = 1e-6;
        // Binary search to find minimum possible maximum distance
        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, arr);
            if (cnt > k) low = mid;
            else high = mid;
        }
        return high;
    }
};



int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    GasStationOptimizer optimizer;
    long double ans = optimizer.minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
