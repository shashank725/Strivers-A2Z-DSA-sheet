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
    ListNode* detectCycle(ListNode* head) {
        // Create a map to store visited nodes
        unordered_set<ListNode*> visited;
        // Start traversing from head
        while (head != NULL) {
            // If current node is already in set, it's the start of loop
            if (visited.find(head) != visited.end()) {
                return head;
            }
            // Otherwise, insert current node into set
            visited.insert(head);
            // Move to the next node
            head = head->next;
        }
        // If loop not found, return NULL
        return NULL;
    }
};



// Optimal Approach
// TC: O(N)
// SC: O(1)
class Solution2 {
public:
    ListNode* detectCycle(ListNode* head) {
        // Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        // Traverse until fast and fast->next are not null
        while (fast != NULL && fast->next != NULL) {
            // Move slow by one step
            slow = slow->next;
            // Move fast by two steps
            fast = fast->next->next;
            // If they meet, loop is detected
            if (slow == fast) {
                // Reset slow to head
                slow = head;
                // Move both one step at a time to find starting point
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                // Return the start node of the loop
                return slow;
            }
        }
        // If no loop found, return NULL
        return NULL;
    }
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