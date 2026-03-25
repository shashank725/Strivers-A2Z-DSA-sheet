#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data, Node* next) // Can also do this Node* next = nullptr
    : data(data), next(next) {}
    // Altenative way to define constructor
    //{
    //     this->data = data;
    //     this->next = next;
    //}
    Node(int data)
    : data(data), next(nullptr) {}
};

Node* convertArrToLL(int arr[], int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i=0; i<n; i++) {
        Node* newNode = new Node(arr[i]);
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

void traverseLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int lengthOfLL(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != nullptr) {
        len++;
        temp = temp->next;
    }
    return len;
}

int checkIfPresent(Node* head, int key) {
    Node* temp = head;
    while(temp) {  // Similar to (temp!=nullptr)
        if(temp->data == key) return 1;
        temp = temp->next;
    }
    return 0; // Key not found
}

Node* insertAtHead(Node* head, int newData) {
    // Create a new node whose next points to current head
    Node* newNode = new Node(newData, head);
    return newNode;
}
Node* insertAtTail(Node* head, int newData) {
    Node* newNode = new Node(newData);
    if(head == nullptr) {
        return newNode; // If list is empty, new node becomes head
    }
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode; // Link the last node to new node
    return head;
}
Node* insertAtPosition(Node* head, int position, int newData) {
    if(position == 0) {
        return insertAtHead(head, newData);
    }
    Node* newNode = new Node(newData);
    Node* temp = head;
    int count = 0;
    while(temp != nullptr && count < position - 1) {
        temp = temp->next;
        count++;
    }
    if(temp == nullptr) {
        // Position is greater than the length of the list
        return head; // No insertion
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
Node* insertAtKey(Node* head, int key, int newData) {
    if(head == nullptr) {
        return head; // Empty list
    }
    if(head->data == key) {
        return insertAtHead(head, newData);
    }
    Node* temp = head;
    while(temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if(temp == nullptr) {
        // Key not found
        return head; // No insertion
    }
    Node* newNode = new Node(newData);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}



Node* removeHead(Node* head) {
    if(head == nullptr) return head; // Empty list
    Node* temp = head;
    head = head->next;
    // In Java or Python, we don't need to explicitly free memory. It happens automatically through Garbage Collection.
    delete temp; // Free the memory. Can also use free(temp) if malloc was used.
    return head;
}
Node* removeTail(Node* head) {
    if(head == nullptr) return head; // Empty list
    if(head->next == nullptr) { // Only one node
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next; // Free memory of last node
    temp->next = nullptr; // Update second last node's next to nullptr
    return head;
}
Node* removePosition(Node* head, int position) {
    if(head == nullptr) return head; // Empty list
    if(position == 0) { // Remove head
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* curr = head;
    Node* prev = nullptr;
    int count = 0;
    while(curr != nullptr && count < position) {
        prev = curr;
        curr = curr->next;
        count++;
    }
    if(curr == nullptr) return head; // Position out of bounds
    prev->next = curr->next; // Bypass the node to be deleted
    delete curr; // Free memory
    return head;
}
Node* removeNodeWithKey(Node* head, int key) {
    if(head == nullptr) return head; // Empty list
    if(head->data == key) { // Key is at head
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* curr = head;
    Node* prev = nullptr;
    while(curr != nullptr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if(curr == nullptr) return head; // Key not found
    prev->next = curr->next; // Bypass the node to be deleted
    delete curr; // Free memory
    return head;
}

int main() {
    Node x = Node(10);
    cout << x.data << endl;
    cout << x.next << endl;fgjnncmm
    Node* y = new Node(20, &x);
    cout << y << endl;
    cout << y->data << endl;
    cout << y->next << endl;
    cout<< y->next->data << endl;

    vector<int> arr = {25, 11, 3, 4, 5, 10};
    Node* head = convertArrToLL(arr.data(), arr.size());
    cout << head->data << endl;
    cout << head->next->data << endl;

    // Traversal in Linked List  O(N)
    traverseLL(head);

    // Length of Linked List  O(N)
    cout << "Length of Linked List: " << lengthOfLL(head) << endl;

    // Search in Linked List  O(N)
    int key = 10;
    cout << "Is " << key << " present in Linked List? " 
         << (checkIfPresent(head, key) ? "Yes" : "No") << endl;


    // Insert at Head (Inserting a node in LinkedList)  O(1)
    head = insertAtHead(head, 5);
    cout << "After inserting 5 at head: ";
    traverseLL(head);
    // Insert at Tail (Inserting a node in LinkedList)  O(N)
    head = insertAtTail(head, 15);
    cout << "After inserting 15 at tail: ";
    traverseLL(head);
    // Insert at Position (Inserting a node in LinkedList)  O(N)
    int position = 3;
    head = insertAtPosition(head, position, 2002);
    cout << "After inserting 2002 at position " << position << ": ";
    traverseLL(head);
    // Insert at Key (Inserting a node in LinkedList)  O(N)
    key = 4;
    head = insertAtKey(head, key, 3003);
    cout << "After inserting 3003 after key " << key << ": ";
    traverseLL(head);


    // Remove Head (Deleting a node from LinkedList)  O(1)
    head = removeHead(head);
    cout << "After removing head: ";
    traverseLL(head);
    // Remove Tail (Deleting a node from LinkedList)  O(N)B
    head = removeTail(head);
    cout << "After removing tail: ";
    traverseLL(head);
    // Remove at Position (Deleting a node from LinkedList)  O(N)
    int position_2 = 2;
    head = removePosition(head, position_2);
    cout << "After removing node at position " << position_2 << ": ";
    traverseLL(head);
    // Remove Node with Key (Deleting a node from LinkedList)  O(N)
    key = 2;
    head = removeNodeWithKey(head, key);
    cout << "After removing node with key " << key << ": ";
    traverseLL(head);

    return 0;
}