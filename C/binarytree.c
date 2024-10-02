#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int d);
  
// Function to delete a node from the binary tree
struct Node* deleteNode(struct Node* root, int val) {
    if (root == NULL) return NULL;

    // Use a queue to perform BFS
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    struct Node* target = NULL;

    // Find the target node
    while (front < rear) {
        struct Node* curr = queue[front++];

        if (curr->data == val) {
            target = curr;
            break;
        }
        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
    if (target == NULL) return root;

    // Find the deepest rightmost node and its parent
    struct Node* lastNode = NULL;
    struct Node* lastParent = NULL;
    struct Node* queue1[100];
    int front1 = 0, rear1 = 0;
    queue1[rear1++] = root;
    struct Node* parents[100];
    parents[rear1 - 1] = NULL;

    while (front1 < rear1) {
        struct Node* curr = queue1[front1];
        struct Node* parent = parents[front1++];

        lastNode = curr;
        lastParent = parent;

        if (curr->left) {
            queue1[rear1] = curr->left;
            parents[rear1++] = curr;
        }
        if (curr->right) {
            queue1[rear1] = curr->right;
            parents[rear1++] = curr;
        }
    }

    // Replace target's value with the last node's value
    target->data = lastNode->data;

    // Remove the last node
    if (lastParent) {
        if (lastParent->left == lastNode) lastParent->left = NULL;
        else lastParent->right = NULL;
        free(lastNode);
    } else {
        free(lastNode);
        return NULL;
    }

    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to create a new node
struct Node* createNode(int d) {
    struct Node* newNode = 
      (struct Node*)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    struct Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    root->left->right = createNode(6);

    printf("Original tree (in-order): ");
    inorder(root);
    printf("\n");

    int valToDel = 3;
    root = deleteNode(root, valToDel);

    printf("Tree after deleting %d (in-order): ", valToDel);
    inorder(root);
    printf("\n");

    return 0;
}
