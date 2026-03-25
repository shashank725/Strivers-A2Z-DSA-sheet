#include <iostream>
using namespace std;

// Class representing a Node in a doubly linked list
class Node {
public:
    // Data stored in the node
    int data;
    // Pointer to the next node
    Node* next;
    // Pointer to the previous node
    Node* back;
    // Constructor with data, next, and back references
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
    // Constructor with only data, next and back are null
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert a vector into a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    // Create head node using the first array element
    Node* head = new Node(arr[0]);
    // Initialize previous node as head
    Node* prev = head;
    // Iterate through the remaining elements
    for (int i = 1; i < arr.size(); i++) {
        // Create new node with current value and back link to prev
        Node* temp = new Node(arr[i], nullptr, prev);
        // Set the next pointer of previous node to new node
        prev->next = temp;
        // Move prev to the new node
        prev = temp;
    }
    // Return the head of the DLL
    return head;
};

// Function to print elements of a doubly linked list
void print(Node* head) {
    // Traverse till the end of the list
    while (head != nullptr) {
        // Print current node's data
        cout << head->data << " ";
        // Move to the next node
        head = head->next;
    }
};



// Brute Force Approach
// TC: O(2N)
// SC: O(1)
Node* reverseDLL(Node* head) {
    // If list is empty or has only one node, return as-is
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    stack<int> st;
    Node* temp = head;
    // Push all node values to stack
    while (temp != nullptr) {
        st.push(temp->data);
        temp = temp->next;
    }
    // Reset temp to head for second pass
    temp = head;
    // Replace node values with those from stack
    while (temp != nullptr) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    // Return head of reversed list
    return head;
}


// Optimal Approach
// TC: O(N)
// SC: O(1)
Node* reverseDLL2(Node* head) {
    // If list is empty or has one node, nothing to reverse
    if (head == nullptr || head->next == nullptr) return head;
    // Pointer to track the current node
    Node* curr = head;
    // Traverse the DLL
    while (curr != nullptr) {
        // Swap next and back pointers of current node
        Node* temp = curr->next;
        curr->next = curr->back;
        curr->back = temp;
        // Move to the next node in original order
        head = curr;          
        curr = temp;          
    }
    // Return new head after full reversal
    return head;
}



// Driver code
int main() {
    // Input array
    vector<int> arr = {12, 5, 8, 7, 4};
    // Convert array to doubly linked list
    Node* head = convertArr2DLL(arr);
    // Print original DLL
    cout << endl << "Doubly Linked List Initially: " << endl;
    print(head);
    // Reverse the DLL̆
    head = reverseDLL2(head);
    // Print reversed DLL
    cout << endl << "Doubly Linked List After Reversing: " << endl;
    print(head);
    return 0;
}