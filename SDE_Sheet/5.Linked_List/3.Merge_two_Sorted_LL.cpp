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

ListNode* convertArrToLL(vector<int> arr) {
    int n = arr.size();
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int i=0; i<n; i++) {
        ListNode* newNode = new ListNode(arr[i]);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}


// Brute Force Approach
// TC: O(N*logN) + O(N)
// SC: O(N)
class Solution {
public:
    ListNode* sortTwoLinkedLists(ListNode* list1, ListNode* list2){
        vector<int> arr;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 != NULL){
            arr.push_back(temp1->val);
            temp1 = temp1->next; 
        }
        while(temp2 != NULL){
            arr.push_back(temp2->val);
            temp2 = temp2->next; 
        }
        sort(arr.begin(), arr.end());
        ListNode* head = convertArrToLL(arr); 
        return head;
    }
};


// Better Approach
// TC: O(2N)
// SC: O(N)


// Optimal Approach
// TC: O(N1+N2)
// SC: O(1)
class Solution2 {
public:
    ListNode* sortTwoLinkedLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to serve
        // as the head of the merged list
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        // Traverse both lists simultaneously
        while (list1 != nullptr && list2 != nullptr) {
            // Compare elements of both lists and
            // link the smaller node to the merged list
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move the temporary pointer
            // to the next node
            temp = temp->next; 
        }

        // If any list still has remaining
        // elements, append them to the merged list
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        // Return the merged list starting 
        // from the next of the dummy node
        return dummyNode->next;
    }
};



// Driver code
int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    cout << "First sorted linked list: ";
    traverseLL(list1);
    cout << "Second sorted linked list: ";
    traverseLL(list2);
    Solution2 sol;
    ListNode* mergedList = sol.sortTwoLinkedLists(list1, list2);
    cout << "Merged sorted linked list: ";
    traverseLL(mergedList);
}