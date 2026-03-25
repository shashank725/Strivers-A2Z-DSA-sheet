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
void traverseLL(ListNode* head) {
    ListNode* temp = head;
    while(temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Brute Force Approach
// TC: O(N+N/2)
// SC: O(1)
class Solution {
public:
    ListNode* deleteNthNodeFromEnd(ListNode* head) {
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
        while (temp != NULL) {
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
    ListNode* deleteNthNodeFromEnd(ListNode* head, int N) {
        // Create a dummy node before head to handle edge cases
        ListNode* dummy = new ListNode(0, head);
        // Initialize slow and fast pointers at dummy
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        // Move fast pointer N+1 steps ahead to create a gap
        for (int i = 0; i <= N; i++) {
            fast = fast->next;
        }
        // Move both pointers until fast reaches the end
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        // Slow is now at node before target → delete target node
        slow->next = slow->next->next;
        // Return updated head
        return dummy->next;
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
    ListNode* deleteNthNodeFromEnd = sol.deleteNthNodeFromEnd(head, 2);
    traverseLL(deleteNthNodeFromEnd);
    return 0;
}