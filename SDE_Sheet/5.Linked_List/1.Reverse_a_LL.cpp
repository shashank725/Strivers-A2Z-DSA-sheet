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
// TC: O(2N)
// SC: O(1)
class Solution {
public:
    // Function to reverse a linked list using stack
    ListNode* reverseList(ListNode* head) {
        // Stack to store values of nodes
        stack<int> st;
        // Temporary pointer to traverse the list
        ListNode* temp = head;
        // Traverse and push all node values to stack
        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }
        // Reset temp back to head
        temp = head;
        // Reassign values from stack in reverse order
        while (temp != NULL) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        // Return the modified head
        return head;
    }
};


// Optimal Approach
// TC: O(N)
// SC: O(1)
class Solution2 {
public:
    // Function to reverse a linked list iteratively
    ListNode* reverseList(ListNode* head) {
        // Initialize previous pointer to NULL
        ListNode* prev = NULL;
        // Start from the head of the list
        ListNode* temp = head;
        // Traverse the list
        while (temp != NULL) {
            // Save the next node
            ListNode* front = temp->next;
            // Reverse the current node's pointer
            temp->next = prev;
            // Move prev to current node
            prev = temp;
            // Move to the next node
            temp = front;
        }
        // Return new head (last node becomes first)
        return prev;
    }
};


// Recursive Approach 
// TC: O(N)
// SC: O(N) - due to recursion stack
class Solution3 {
public:
    // Function to reverse a linked list recursively
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head; // Base case: empty list or single node
        }
        // Recursively reverse the rest of the list
        ListNode* newHead = reverseList(head->next);
        // Store the next node
        ListNode* front = head->next;
        // Make the next node point back to current
        front->next = head;
        // Break the current node's forward link
        head->next = NULL;
        // Return the new head of the reversed list
        return newHead;
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
    // Reversing the list
    ListNode* newHead = sol.reverseList(head);
    // Printing the reversed list
    while (newHead != NULL) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}