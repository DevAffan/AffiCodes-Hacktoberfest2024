// Program that implements a stack using a linked list
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a stack node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if the stack is empty
int isEmpty(struct Node* root) {
    return !root;
}

// Function to push an element onto the stack
void push(struct Node** root, int data) {
    struct Node* node = newNode(data);
    node->next = *root;  // Point the new node to the old root
    *root = node;  // Update the root to the new node
    printf("%d pushed to stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Node** root) {
    if (isEmpty(*root)) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);  // Free the popped node
    return popped;
}

// Function to peek at the top element of the stack
int peek(struct Node* root) {
    if (isEmpty(root)) {
        printf("Stack is empty\n");
        return -1;
    }
    return root->data;
}

// Driver code
int main() {
    struct Node* stack = NULL;  // Initialize an empty stack

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("%d popped from stack\n", pop(&stack));
    printf("Top element is %d\n", peek(stack));

    return 0;
}
