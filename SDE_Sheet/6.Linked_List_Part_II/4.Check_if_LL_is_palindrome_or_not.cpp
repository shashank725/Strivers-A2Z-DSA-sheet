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
    bool isPalindrome(ListNode* head) {
        // Create an empty stack to store values
        stack<int> st;
        // Initialize a temporary pointer to the head of the linked list
        ListNode* temp = head;
        // Traverse the linked list and push values onto the stack
        while (temp != NULL) {
            st.push(temp->val); // Push the data from the current node onto the stack
            temp = temp->next;   // Move to the next node
        }
        // Reset the temporary pointer back to the head of the linked list
        temp = head;
        // Compare values by popping from the stack and checking against linked list nodes
        while (temp != NULL) {
            if (temp->val != st.top()) {
                // If values don't match, it's not a palindrome
                return false;
            }
            st.pop();           // Pop the value from the stack
            temp = temp->next;  // Move to the next node in the linked list
        }
        // If all values match, it's a palindrome
        return true;
    }
};


// Optimal Approach
// TC: O(N)
// SC: O(1)
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        // Check if the linked list is empty or has only one node
        if (head == NULL || head->next == NULL) {
            return true;  // It's a palindrome by definition
        }
        // Initialize two pointers, slow and fast, to find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        // Traverse the linked list to find the middle using slow and fast pointers
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;       // Move slow pointer one step at a time
            fast = fast->next->next; // Move fast pointer two steps at a time
        }
        // Reverse the second half of the linked list starting from the middle
        ListNode* newHead = reverseLinkedList(slow->next);
        // Pointer to the first half
        ListNode* first = head;
        // Pointer to the reversed second half
        ListNode* second = newHead;
        // Compare data values of nodes from both halves
        while (second != NULL) {
            if (first->val != second->val) {
                // If values do not match, the list is not a palindrome
                reverseLinkedList(newHead);  // Reverse the second half back to its original state
                return false;
            }

            first = first->next;  // Move the first pointer
            second = second->next; // Move the second pointer
        }
        // Reverse the second half back to its original state
        reverseLinkedList(newHead);
        // The linked list is a palindrome
        return true;
    }
    ListNode* reverseLinkedList(ListNode* head) {
        // Check if the list is empty or has only one node
        if (head == NULL || head->next == NULL) {
            return head;  // No change is needed; return the current head
        }
        // Recursive step: Reverse the remaining part of the list and get the new head
        ListNode* newHead = reverseLinkedList(head->next);
        // Store the next node in 'front' to reverse the link
        ListNode* front = head->next;
        // Update the 'next' pointer of 'front' to point to the current head
        front->next = head;
        // Set the 'next' pointer of the current head to null to break the original link
        head->next = NULL;
        // Return the new head obtained from the recursion
        return newHead;
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
    // Check if the linked list is a palindrome
    Solution sol;
    if (sol.isPalindrome(list)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
};