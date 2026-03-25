#include <iostream>
using namespace std;

// struct Node {
//     int data;
//     Node* prev;
//     Node* next;

//     Node (int val, Node* p = nullptr, Node* n = nullptr) {
//         this->data = val;
//         this->prev = p;
//         this->next = n;
//     }
// };
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Node (int val, Node* p = nullptr, Node* n = nullptr) {
    //     this->data = val;
    //     this->prev = p;
    //     this->next = n;
    // }
    // Same as above constructor using initializer list (Better Practice)
    Node(int val, Node* p = nullptr, Node* n = nullptr) 
    : data(val), prev(p), next(n) {}
};

Node* convertArrToDLL(int arr[], int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i=0; i<n; i++) {
        Node* newNode = new Node(arr[i]);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}

Node* traverseDLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}


Node* insertAtHead(Node* head, int newData) {
    Node* newNode = new Node(newData);
    if(head != nullptr) {
        head->prev = newNode; // Update old head's prev to new node
    }
    newNode->next = head; // Link new node to old head
    return newNode; // New node becomes the new head
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
    newNode->prev = temp; // Link new node back to last node
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
    if(temp == nullptr) return head; // Position out of bounds
    newNode->next = temp->next; // Link new node to next node
    if(temp->next != nullptr) {
        temp->next->prev = newNode; // Link next node back to new node
    }
    temp->next = newNode; // Link current node to new node
    newNode->prev = temp; // Link new node back to current node
    return head;
}
Node* insertAtKey(Node* head, int key, int newData) {
    Node* newNode = new Node(newData);
    if(head == nullptr) {
        return newNode; // If list is empty, new node becomes head
    }
    Node* temp = head;
    while(temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if(temp == nullptr) return head; // Key not found
    newNode->next = temp->next; // Link new node to next node
    if(temp->next != nullptr) {
        temp->next->prev = newNode; // Link next node back to new node
    }
    temp->next = newNode; // Link current node to new node
    newNode->prev = temp; // Link new node back to current node
    return head;
}


Node* removeHead(Node* head) {
    if(head == nullptr) return head; // Empty list
    Node* temp = head;
    head = head->next;
    if(head != nullptr) {
        head->prev = nullptr; // Update new head's prev to nullptr
    }
    delete temp; // Free memory of old head
    return head;
}
Node* removeTail(Node* head) {
    if(head == nullptr) return head; // Empty list
    if(head->next == nullptr) { // Only one node
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr; // Update second last node's next to nullptr
    delete temp; // Free memory of last node
    return head;
}
Node* removePosition(Node* head, int position) {
    if(head == nullptr) return head; // Empty list
    if(position == 0) { // Remove head
        return removeHead(head);
    }
    Node* curr = head;
    int count = 0;
    while(curr != nullptr && count < position) {
        curr = curr->next;
        count++;
    }
    if(curr == nullptr) return head; // Position out of bounds
    if(curr->prev != nullptr) {
        curr->prev->next = curr->next; // Bypass the node to be deleted
    }
    if(curr->next != nullptr) {
        curr->next->prev = curr->prev; // Bypass the node to be deleted
    }
    delete curr; // Free memory
    return head;
}
Node* removeNodeWithKey(Node* head, int key) {
    if(head == nullptr) return head; // Empty list
    if(head->data == key) { // Key is at head
        return removeHead(head);
    }
    Node* curr = head;
    while(curr != nullptr && curr->data != key) {
        curr = curr->next;
    }
    if(curr == nullptr) return head; // Key not found
    if(curr->prev != nullptr) {
        curr->prev->next = curr->next; // Bypass the node to be deleted
    }
    if(curr->next != nullptr) {
        curr->next->prev = curr->prev; // Bypass the node to be deleted
    }
    delete curr; // Free memory
    return head;
}


int main() {
    int arr[] = {10, 20, 30, 40, 50};
    Node* head = convertArrToDLL(arr, 5);
    traverseDLL(head);

    // Insert at head
    head = insertAtHead(head, 5);
    cout << "After inserting 5 at head: ";
    traverseDLL(head);
    // Insert at tail
    head = insertAtTail(head, 60);
    cout << "After inserting 60 at tail: ";
    traverseDLL(head);
    // Insert at position
    head = insertAtPosition(head, 3, 25);
    cout << "After inserting 25 at position 3: ";
    traverseDLL(head);
    // Insert at key
    head = insertAtKey(head, 30, 35);
    cout << "After inserting 35 after key 30: ";
    traverseDLL(head);

    // Remove head
    head = removeHead(head);
    cout << "After removing head: ";
    traverseDLL(head);
    // Remove tail
    head = removeTail(head);
    cout << "After removing tail: ";
    traverseDLL(head);
    // Remove at position
    head = removePosition(head, 1);
    cout << "After removing node at position 1: ";
    traverseDLL(head);
    // Remove node with key
    head = removeNodeWithKey(head, 30);
    cout << "After removing node with key 30: ";
    traverseDLL(head);
}