#include <iostream>
using namespace std;

// Class representing a Node in a doubly linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Brute Force Approach
// TC: O(N+N/2)
// SC: O(1)
class Solution {
public:
    ListNode *findMiddle(ListNode *head) {
        // If the list is empty or has only
        // one element, return the head as
        // it's the middle.
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* temp = head;
        int count = 0;
        // Count the number of nodes in the linked list.
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        // Calculate the position of the middle node.
        int mid = count / 2 + 1;
        temp = head;
        // Traverse to the middle node by moving
        // temp to the middle position.
        while (temp != nullptr) {
            mid = mid - 1;
            // Check if the middle
            // position is reached.
            if (mid == 0){
                // break out of the loop
                // to return temp
                break;
            }
            // Move temp ahead
            temp = temp->next;
        }
        // Return the middle node.
        return temp;
    }
};


// Better Approach
// TC: O(2N)
// SC: O(N)


// Optimal Approach
// TC: O(N/2) 
// SC: O(1)
// The Tortoise and Hare algorithm
class Solution2 {
public:
    ListNode *findMiddle(ListNode *head) {
     // Initialize the slow pointer to the head.
    ListNode *slow = head; 
     // Initialize the fast pointer to the head.
    ListNode *fast = head; 
    // Traverse the linked list using the
    // Tortoise and Hare algorithm.
    while (fast != NULL && fast->next != NULL) {
        // Move slow one step.
        slow = slow->next; 
         // Move fast two steps.
        fast = fast->next->next; 
    }
     // Return the slow pointer,
     // which is now at the middle node.
    return slow; 
}
};



// Driver code
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution2 sol;
     // Find the middle node
    ListNode* middle = sol.findMiddle(head);

    // Display the value of the middle node
    return 0;
}