#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    // Create a linked list from an array of values
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    // Print the original linked list
    cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    ListNode* reversedHead = reverseList(head);

    // Print the reversed linked list
    cout << "Reversed List: ";
    printList(reversedHead);

    // Clean up memory (optional)
    // Note: Memory cleanup should be done carefully to avoid memory leaks.
    return 0;
}
