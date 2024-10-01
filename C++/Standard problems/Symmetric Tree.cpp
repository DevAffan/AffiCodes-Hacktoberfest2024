#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check if two trees are mirror images of each other
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true; // Both are null
    if (!t1 || !t2) return false; // One is null
    return (t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
}

// Function to check if a tree is symmetric
bool isSymmetric(TreeNode* root) {
    return isMirror(root, root);
}

// Function to insert a value into the binary tree
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to print the tree in level order
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

int main() {
    TreeNode* root = NULL;
    vector<int> values = {5, 3, 8, 3, 4, 8, 7}; // Example values to create a tree
    for (int val : values) {
        root = insert(root, val);
    }

    cout << "Level Order Traversal of the Tree: ";
    printLevelOrder(root);

    // Check if the tree is symmetric
    if (isSymmetric(root)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}
