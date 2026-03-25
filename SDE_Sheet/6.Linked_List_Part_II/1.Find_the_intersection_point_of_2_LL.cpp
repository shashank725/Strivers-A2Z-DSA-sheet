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
// TC: O(M × N)
// SC: O(1)
class Solution {
public:
    ListNode* intersectionPresent(ListNode* head1, ListNode* head2) {
        while (head2 != NULL) {
            ListNode* temp = head1;
            while (temp != NULL) {
                // If both nodes are the same (intersection point)
                if (temp == head2) return head2;
                temp = temp->next;
            }
            head2 = head2->next;
        }
        // Intersection is not present between the lists, return NULL
        return NULL;
    }
};


// Better Approach
// TC: O(N + M)
// SC: O(N)
class Solution2 {
public:
    ListNode* intersectionPresent(ListNode* head1, ListNode* head2) {
        unordered_set<ListNode*> st;  // Set to store visited nodes from the first list
        while (head1 != NULL) {
            st.insert(head1);  // Insert nodes of the first list into the set
            head1 = head1->next;
        }
        while (head2 != NULL) {
            if (st.find(head2) != st.end()) return head2;  // If node is found in set, it's the intersection point
            head2 = head2->next;
        }
        return NULL;  // Return NULL if no intersection is found
    }
};


// Optimal Approach 1
// TC: O(2 × max(length of list1, length of list2)) + O(abs(length of list1 − length of list2)) + O(min(length of list1, length of list2))
// SC: O(1)
class Solution3 {
public:
    int getDifference(ListNode* head1, ListNode* head2) {
        int len1 = 0, len2 = 0;
        while (head1 != NULL || head2 != NULL) {
            if (head1 != NULL) {
                ++len1;
                head1 = head1->next;
            }
            if (head2 != NULL) {
                ++len2;
                head2 = head2->next;
            }
        }
        return len1 - len2;  // If negative, length of list2 > length of list1, else vice-versa
    }
    ListNode* intersectionPresent(ListNode* head1, ListNode* head2) {
        int diff = getDifference(head1, head2);
        
        if (diff < 0) 
            while (diff++ != 0) head2 = head2->next;
        else 
            while (diff-- != 0) head1 = head1->next;
        
        // Traverse both lists and compare node by node
        while (head1 != NULL) {
            if (head1 == head2) return head1;  // Intersection point found
            head2 = head2->next;
            head1 = head1->next;
        }
        return head1;  // Return NULL if no intersection
    }

};


// Optimal Approach 2
// TC: O(2 × max(length of list1, length of list2)) O(N + M)
// SC: O(1)
class Solution4 {
public:
    ListNode* intersectionPresent(ListNode* head1, ListNode* head2) {
        ListNode* d1 = head1;
        ListNode* d2 = head2;
        // Traverse both lists, when one reaches the end, redirect it to the head of the other list
        while (d1 != d2) {
            d1 = d1 == NULL ? head2 : d1->next;
            d2 = d2 == NULL ? head1 : d2->next;
        }
        return d1;  // If they meet, return the intersection node, otherwise NULL
    }
};


// Driver code
int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    ListNode* temp = new ListNode(5);
    list1->next->next = temp;
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = temp;

    traverseLL(list1);
    traverseLL(list2);
    Solution3 sol;
    ListNode* intersection = sol.intersectionPresent(list1, list2);
    traverseLL(intersection);
};