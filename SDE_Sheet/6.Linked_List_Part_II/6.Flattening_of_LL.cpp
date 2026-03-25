#include <iostream>
#include<unordered_set>
using namespace std;

// Class representing a Node in a doubly linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode *child;
    ListNode() : val(0), next(nullptr), child(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), child(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next), child(nullptr) {}
};
void traverseLL(ListNode* head) {
    ListNode* temp = head;
    while(temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->child;
    }
    cout << "\n";
}
void printOriginalLinkedList(ListNode* head, int depth) {
    while (head != nullptr) {
        cout << head->val;
        /* If child exists, recursively
         print it with indentation */
        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }
        // Add vertical bars for each level in the grid
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}
ListNode* convertArrToLinkedList(vector<int>& arr) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        for (int i=0; i < arr.size(); i++) {
            temp->child = new ListNode(arr[i]);
            temp = temp->child;
        }
        return dummyNode->child;
    }


// Brute Force Approach
// TC: O(N x M) + O(N x M log(N x M)) + O(N x M)
// SC: O(N x M) + O(N x M)
class Solution {
public:
    ListNode* flattenLinkedList(ListNode* head) {
        vector<int> arr;
        // Traverse through the linked list
        while (head != nullptr) {
            /* Traverse through the child
             nodes of each head node */
            ListNode* t2 = head;
            while (t2 != nullptr) {
                // Store each node's data in the array
                arr.push_back(t2->val);
                
                // Move to the next child node
                t2 = t2->child;
            }
            // Move to the next head node
            head = head->next;
        }
        // Sort the array containing node values
        sort(arr.begin(), arr.end());
        // Convert the sorted array back to a linked list
        return convertArrToLinkedList(arr);
    }
};



// Optimal Approach
// TC: O(N x (2M)) ~ O(2N x M)
// SC: O(1)
class Solution2 {
public:
    ListNode* flattenLinkedList(ListNode* head) {
        // If head is null or there is no next node
        if(head == NULL || head->next == NULL){
            return head; // Return head
        }
        // Recursively flatten the rest of the linked list
        ListNode* mergedHead = flattenLinkedList(head->next);
        // Merge the lists
        head = merge(head, mergedHead);
        return head;
    }
    ListNode* merge(ListNode* list1, ListNode* list2){
        /* Create a dummy node as a 
        placeholder for the result */
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;
        // Merge the lists based on data values
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                res->child = list1;
                res = list1;
                list1 = list1->child;
            }
            else{
                res->child = list2;
                res = list2;
                list2 = list2->child;
            }
            res->next = NULL;
        }
        // Connect the remaining elements if any
        if(list1){
            res->child = list1;
        } else {
            res->child = list2;
        }
        // Break the last node's link to prevent cycles
        if(dummyNode->child){
            dummyNode->child->next = NULL;
        }
        return dummyNode->child;
    }
};



int main() {
    // Create a linked list with child pointers
    ListNode* head = new ListNode(5);
    head->child = new ListNode(14);

    head->next = new ListNode(10);
    head->next->child = new ListNode(4);

    head->next->next = new ListNode(12);
    head->next->next->child = new ListNode(20);
    head->next->next->child->child = new ListNode(13);

    head->next->next->next = new ListNode(7);
    head->next->next->next->child = new ListNode(17);

    // Print the original linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);
    // Creating an instance of Solution class
    Solution2 sol;
    // Function call to flatten the linked list
    ListNode* flattened = sol.flattenLinkedList(head);
    // Printing the flattened linked list
    cout << "\nFlattened linked list: ";
    traverseLL(flattened);

    return 0;
}