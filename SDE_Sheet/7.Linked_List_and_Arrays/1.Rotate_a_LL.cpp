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
// TC:  O(k * N)
// SC: O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // If list is empty or has only one node or no rotation needed
        if (!head || !head->next || k == 0) return head;
        // Repeat the rotation process k times
        for (int i = 0; i < k; i++) {
            // Initialize two pointers to traverse the list
            ListNode* curr = head;
            ListNode* prev = NULL;
            // Traverse to the last node
            while (curr->next) {
                prev = curr;
                curr = curr->next;
            }
            // Detach the last node and place it at the beginning
            prev->next = NULL;
            curr->next = head;
            head = curr;
        }
        // Return the rotated head
        return head;
    }
};



// Optimal Approach
// TC: O(N)
// SC: O(1)
class Solution2 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // If list is empty or has only one node, or no rotation is needed
        if (!head || !head->next || k == 0)
            return head;
        // Initialize length and tail pointer
        int length = 1;
        ListNode* tail = head;
        // Traverse to find the tail and length
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        // Make it a circular linked list
        tail->next = head;
        // Effective rotations needed
        k = k % length;
        // Traverse to the new tail (length - k - 1 steps from head)
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }
        // Set the new head
        ListNode* newHead = newTail->next;
        // Break the circle
        newTail->next = NULL;
        return newHead;
    }
};



int main() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(3);
    list->next->next = new ListNode(5);
    list->next->next->next = new ListNode(9);
    // Print the original linked list
    traverseLL(list);
    // Rotate the linked list to the right by 2 positions
    Solution2 sol;
    ListNode* rotatedList = sol.rotateRight(list, 2);
    // Print the rotated linked list
    traverseLL(rotatedList);

    return 0;
};