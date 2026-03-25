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
// TC: 
// SC: 


// Better Approach
// TC: 
// SC: 


// Optimal Approach
// TC: O(max(m,n))
// SC: O(max(m,n))
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       //Initialize a dummy node as a new node
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        //Carry will be carried to the next new node created
        int carry = 0;
        //Iterate till the end of both the lists
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            //Repeat the same process for l2 as l1
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            //Carry gets added to sum in the node (carry=sum/10)
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
    }
};


int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);
    traverseLL(list1);
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);
    traverseLL(list2);
    Solution sol;
    ListNode* mergedList = sol.addTwoNumbers(list1, list2);
    traverseLL(mergedList);
}