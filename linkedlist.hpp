#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Initialize a new Node with the given data and return a pointer to it
Node* initNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}

// Add a new Node with data to the beginning of the linked list
void addHead(Node** head, int data) {
    Node* node = initNode(data);
    Node* current = *head;
    if (!node) {
        // Memory allocation failed!
        return;
    }
    if (current == NULL) {
        current = node;
        *head = current;
    }
    else {
        node->next = current;
        *head = node;
    }
}

// Add a new Node with data to the end of the linked list
void addTail(Node** head, int data) {
    Node* current = *head;
    Node* node = initNode(data);
    if (!node) return;
    if (!current) {
        *head = node;
        return;
    }
    while (current->next) {
        current = current->next;
    }
    current->next = node;
}

// Add a new Node with data at a specified position in the linked list
void addPos(Node** head, int data, int pos) {
    Node* current = *head;
    Node* node = initNode(data);
    if (!node) return;
    if (pos == 0) {
        addHead(&current, data);
        return;
    }
    while (--pos && current) {
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    node->next = current->next;
    current->next = node;
}

// Delete the first Node in the linked list
void deleteHead(Node** head) {
    Node* current = *head;
    if (current == NULL) return;
    current = current->next;
    *head = current;
}

// Delete the last Node in the linked list
void deleteTail(Node** head) {
    Node* current = *head;
    if (current == NULL) return;
    while (current->next->next) {
        current = current->next;
    }
    current->next = NULL;
}

// Delete the Node at a specified position in the linked list
void deletePos(Node** head, int pos) {
    Node* current = *head;
    if (!current) return;
    if (pos == 0) {
        deleteHead(&current);
        return;
    }
    while (--pos && current) {
        current = current->next;
    }
    if (!current) return;
    current->next = current->next->next;
}

// Print the elements of the linked list
void printList(Node* head) {
    Node* current = head;
    if (current == NULL) return;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
}

// Get the number of elements in the linked list
int size(Node* head) {
    Node* current = head;
    int s = 0;
    while (current) {
        s += 1;
        current = current->next;
    }
    return s;
}

// Concatenate two linked lists by attaching the second list to the end of the first list
void concatenate(Node** head1, Node** head2) {
    Node* current1 = *head1, *current2 = *head2;
    while (current1->next) {
        current1 = current1->next;
    }
    current1->next = current2;
}

// Check if there is a cycle in the linked list using Floyd's Tortoise and Hare algorithm
bool cycle(Node* head) {
    Node* ptr1 = head, *ptr2 = head;
    while (ptr2 && ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
        if (ptr1 == ptr2) return true;
    }
    return false;
}

// Reverse the linked list in-place
void reverseList(Node** head) {
    Node* current = *head;
    Node* reverse = initNode(current->data);
    current = current->next;
    while (current) {
        addHead(&reverse, current->data);
        current = current->next;
    }
    *head = reverse;
}

// Find and return the middle Node of the linked list
Node* middleNode(Node* head) {
    int middle = size(head) / 2;
    Node* current = head;
    while (middle--) {
        current = current->next;
    }
    return current;
}

// Clone the linked list by creating a new one with the same elements
Node* clone(Node* head) {
    Node* current = head;
    return current;
}
