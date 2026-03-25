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
// TC: O(N*LogN)
// SC: O(N)
class Solution {
public:
    bool detectLoop(ListNode* head) {
        // Initialize a pointer at head
        ListNode* temp = head;
        // Create a map to keep track of visited nodes
        unordered_map<ListNode*, int> nodeMap;
        // Traverse the linked list
        while (temp != nullptr) {
            // If node already exists in map, loop detected
            if (nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }
            // Store the current node in the map
            nodeMap[temp] = 1;

            // Move to the next node
            temp = temp->next;
        }
        // If traversal completes, no loop detected
        return false;
    }
};


// Optimal Approach 1
// TC: O(N)
// SC: O(1)
class Solution3 {
public:
    bool detectLoop(ListNode* head) {
        // Initialize a pointer at head
        ListNode* temp = head;
        // Create a map to keep track of visited nodes
        unordered_map<ListNode*, int> nodeMap;
        // Traverse the linked list
        while (temp != nullptr) {
            // If node already exists in map, loop detected
            if (nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }
            // Store the current node in the map
            nodeMap[temp] = 1;
            // Move to the next node
            temp = temp->next;
        }
        // If traversal completes, no loop detected
        return false;
    }
};


// Optimal Approach
// TC: O(N)
// SC: O(1)
class Solution3 {
public:
    bool detectLoop(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};



// Driver code
int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);
    ListNode* temp =  new ListNode(7);
    list1->next->next->next = temp;
    list1->next->next->next->next = new ListNode(9);
    // Create a loop for testing
    list1->next->next->next->next->next = temp;
    // traverseLL(list1);
    Solution sol;
    cout << sol.detectLoop(list1);
};