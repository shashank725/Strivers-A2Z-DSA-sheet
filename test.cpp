#include <iostream>
#include<unordered_set>
using namespace std;

// Class representing a Node in a doubly linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void traverseLL(ListNode* head) {
    ListNode* temp = head;
    while(temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
}



// Brute Force Approach
// TC: O(N)
// SC: O(N)
class Solution {
public:
    
};


// Better Approach
// TC: O(N + M)
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
    ListNode* list = new ListNode(1);
    list->next = new ListNode(3);
    list->next->next = new ListNode(5);
    list->next->next->next = new ListNode(9);
    // Print the original linked list
    traverseLL(list);
    // Check if the linked list has a cycle
    Solution sol;
    if (sol.detectCycle(list)) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
};




// int main() {
// 	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     int t;
// 	cin>> t;
// 	while(t--) {
//         int n;
// 		cin>>n;
// 	}
// }