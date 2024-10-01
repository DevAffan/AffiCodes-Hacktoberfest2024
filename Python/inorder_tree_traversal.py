                            
# Node class for the binary tree
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

# Function to perform inorder traversal
# of the tree and store values in 'arr'
def inorder(root, arr):
    # If the current node is None
    # (base case for recursion), return
    if root is None:
        return
    # Recursively traverse the left subtree
    inorder(root.left, arr)
    # Append the current node's
    # value into the list
    arr.append(root.data)
    # Recursively traverse 
    # the right subtree
    inorder(root.right, arr)

# Function to initiate inorder traversal
# and return the resulting list
def in_order(root):
    # Create an empty list to
    # store inorder traversal values
    arr = []
    # Call the inorder traversal function
    inorder(root, arr)
    # Return the resulting list
    # containing inorder traversal values
    return arr

# Main function
if __name__ == "__main__":
    # Creating a sample binary tree
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    # Getting inorder traversal
    result = in_order(root)

    # Displaying the inorder traversal result
    print("Inorder Traversal:", end=" ")
    # Output each value in the
    # inorder traversal result
    for val in result:
        print(val, end=" ")
    print()