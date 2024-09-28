# Node class represents a node in 
# a linked list

class Node:
    def __init__(self, data, next_node=None):
        # Data stored in the node
        self.data = data       
        # Pointer to the next node in the list
        self.next = next_node  

# Function to find the middle 
# node of a linked list
def find_middle(head):
    # Initialize the slow pointer to the head.
    slow = head   
    
    # Initialize the fast pointer to the head.
    fast = head   

    # Traverse the linked list using
    # the Tortoise and Hare algorithm.
    while fast and fast.next and slow:
        # Move fast two steps.
        fast = fast.next.next 
        # Move slow one step.
        slow = slow.next       

    # Return the slow pointer,
    # which is now at the middle node.
    return slow  


# Creating a sample linked list: 
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
head.next.next.next.next = Node(5)

# Find the middle node
middle_node = find_middle(head)

# Display the value of the middle node
print("The middle node value is:", middle_node.data)