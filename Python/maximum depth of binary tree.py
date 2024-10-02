#To find maximum depth of binary tree

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def maxDepth(root):
    if root is None:
        return 0
    else:
        left_depth = maxDepth(root.left)
        right_depth = maxDepth(root.right)
        return max(left_depth, right_depth) + 1

# Helper function to build a binary tree from user input
def buildTree(values):
    if not values:
        return None
    root = TreeNode(values[0])
    queue = [root]
    i = 1
    while i < len(values):
        current = queue.pop(0)
        if values[i] is not None:
            current.left = TreeNode(values[i])
            queue.append(current.left)
        i += 1
        if i < len(values) and values[i] is not None:
            current.right = TreeNode(values[i])
            queue.append(current.right)
        i += 1
    return root

# Input: list of values (None for empty nodes)
input_values = input("Enter the values of the binary tree level-wise, with 'None' for empty nodes (e.g., 1 2 3 None 4 None 5): ").split()

# Convert input values to a list of integers and 'None' for empty nodes
values = [int(x) if x != 'None' else None for x in input_values]

# Build the binary tree
root = buildTree(values)

# Find and print the maximum depth
print("Maximum depth of the binary tree:", maxDepth(root))
