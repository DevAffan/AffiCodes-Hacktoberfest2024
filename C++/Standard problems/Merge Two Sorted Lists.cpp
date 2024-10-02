#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
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
    // Create two sorted linked lists
    ListNode* l1 = createList({1, 2, 4});
    ListNode* l2 = createList({1, 3, 4});

    // Print the original lists
    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    // Merge the two lists
    ListNode* mergedList = mergeTwoLists(l1, l2);

    // Print the merged list
    cout << "Merged List: ";
    printList(mergedList);

    // Clean up memory (optional)
    // Note: Memory cleanup should be done carefully to avoid memory leaks.
    return 0;
}
