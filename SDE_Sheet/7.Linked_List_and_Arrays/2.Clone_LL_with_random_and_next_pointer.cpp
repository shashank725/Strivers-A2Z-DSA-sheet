#include <iostream>
#include <map>
using namespace std;

class Node {
public:
    // Data stored in the node
    int data;           
     // Pointer to the next node
    Node *next;        
    // Pointer to a random
    // node in the list
    Node *random;       
    // Constructors for Node class
    Node() : data(0), next(nullptr), random(nullptr){}; 
    Node(int x) : data(x), next(nullptr), random(nullptr) {} 
    // Constructor with data,
    // next, and random pointers
    Node(int x, Node *nextNode, Node *randomNode) :
            data(x), next(nextNode), random(randomNode) {}  
};

void traverseLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
};



// Brute Force Approach
// TC:  O(2N)
// SC: O(N)+O(N)
Node *cloneLL(Node *head){
    if (!head) return nullptr; // If the original list is empty, return null
    map<Node*, Node*> nodeMap; // Map to store original nodes and their copies
    Node* temp = head;
    // First pass: Create copies of the nodes and store in the map
    while(temp != NULL){
        nodeMap[temp] = new Node(temp->data); // Create a copy of the current node
        temp = temp->next; // Move to the next node
    }
    temp = head;
    // Second pass: Set the next and random pointers for the copied nodes
    while(temp != NULL){
        nodeMap[temp]->next = nodeMap[temp->next];
        nodeMap[temp]->random = nodeMap[temp->random];
        temp = temp->next;
    }
    return nodeMap[head];
}


// Optimal Approach
// TC: O(3N)
// SC: O(N)
// Function to insert a copy of each
// node in between the original nodes
void insertCopyInBetween(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* nextElement = temp->next;
        // Create a new node with the same data
        Node* copy = new Node(temp->data);  
        
        // Point the copy's next to
        // the original node's next
        copy->next = nextElement;  
        
        // Point the original
        // node's next to the copy
        temp->next = copy;         

        // Move to the next original node
        temp = nextElement;         
    }
}
// Function to connect random
// pointers of the copied nodes
void connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != NULL){
        // Access the copied node
        Node* copyNode = temp->next;    
        
        // If the original node
        // has a random pointer
        if(temp->random){   
             // Point the copied node's random to the
             // corresponding copied random node
            copyNode->random = temp->random->next; 
        }
        else{
             // Set the copied node's random to
             // null if the original random is null
            copyNode->random = NULL;   
        }
        
         // Move to the next original node
        temp = temp->next->next;   
    }
}
// Function to retrieve the
// deep copy of the linked list
Node* getDeepCopyList(Node* head){
    Node* temp = head;
     // Create a dummy node
    Node* dummyNode = new Node(-1);   
    // Initialize a result pointer
    Node* res = dummyNode;             

    while(temp != NULL){
        // Creating a new List by
        // pointing to copied nodes
        res->next = temp->next;
        res = res->next;

        // Disconnect and revert back to the
        // initial state of the original linked list
        temp->next = temp->next->next;
        temp = temp->next;
    }
    
     // Return the deep copy of the
     // list starting from the dummy node
    return dummyNode->next;   
}
// Function to clone the linked list
Node *cloneLL2(Node *head){
    // If the original list
    // is empty, return null
    if(!head) return nullptr;   
     // Step 1: Insert copy of
     // nodes in between
    insertCopyInBetween(head); 
    // Step 2: Connect random
    // pointers of copied nodes
    connectRandomPointers(head);  
    // Step 3: Retrieve the deep
    // copy of the linked list
    return getDeepCopyList(head); 
}




int main() {
    // Example linked list: 7 -> 14 -> 21 -> 28
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    traverseLL(head);

    // Clone the linked list
    Node* clonedList = cloneLL(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    traverseLL(clonedList);

    return 0;
}