#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to check if the linked list has a cycle
bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
        if (slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main() {
    // Create a linked list with a cycle
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);
    
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; // Creates a cycle

    // Test the hasCycle function
    if (hasCycle(head)) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    // Cleaning up memory (optional, only useful if there's no cycle)
    // In this example, since there's a cycle, freeing the nodes would require special handling.
    return 0;
}
