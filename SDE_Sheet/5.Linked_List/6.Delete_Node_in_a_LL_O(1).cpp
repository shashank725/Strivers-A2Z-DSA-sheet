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


// TC: O(1)
// SC: O(1)
class Solution {
public:
    // Function to delete a given node (not the tail node)
    void deleteNode(ListNode* node) {
        // Copy the value from the next node into the current node
        node->val = node->next->val;
        // Bypass the next node (unlink it from the list)
        node->next = node->next->next;
    }
};



int main() {
    // Create a linked list: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    // Suppose we want to delete node with value 5
    Solution sol;
    sol.deleteNode(head->next);  
    // Print updated list: expected output is 4 -> 1 -> 9
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}