class Node:
    def __init__(self, data, next_node=None):
        self.data = data
        self.next = next_node
# Function to calculate the length of a linked list
def length_of_linked_list(head):
    cnt = 0
    temp = head
    
    # Traverse the linked list and count nodes
    while temp is not None:
        temp = temp.next
        cnt += 1
  
    return cnt
# Main function
def main():
    arr = [2, 5, 8, 7]
    # Create a linked list
    head = Node(arr[0])
    head.next = Node(arr[1])
    head.next.next = Node(arr[2])
    head.next.next.next = Node(arr[3])
    # Print the length of the linked list
    print("Length of the linked list:", length_of_linked_list(head))
main()