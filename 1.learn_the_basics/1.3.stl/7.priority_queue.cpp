#include <bits/stdc++.h>
using namespace std;

// 'priority_queue' is of two 2 types: "Max Heap" & "Min Heap"
// push & pop : O(logn)
// top : O(1)  


int main() {
    // Also called Max Heap
    priority_queue<int> pq;
    pq.push(25);
    pq.emplace(11);
    pq.emplace(2000);

    cout << "Top: " << pq.top() << endl;

    pq.pop();
    cout << "Top: " << pq.top() << endl;



    // Also called Min Heap
    priority_queue<int, vector<int>, greater<int>> min_heap;
    min_heap.push(25);
    min_heap.emplace(11);
    min_heap.emplace(2000);

    cout << "Top: " << min_heap.top() << endl;

    return 0;    
}