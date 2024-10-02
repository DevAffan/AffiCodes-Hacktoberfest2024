class MinHeap:
    """
    A class that implements a Min Heap data structure. The smallest element is at the root of the heap.
    """

    def __init__(self, maxsize):
        """
        Initialize the heap with a maximum size.

        Parameters:
        maxsize (int): The maximum number of elements the heap can hold.
        """
        self.maxsize = maxsize
        self.arr = [None] * maxsize
        self.heapsize = 0

    def min_heapify(self, i):
        """
        Ensure the min heap property for the subtree rooted at index i.

        Parameters:
        i (int): The index of the root of the subtree to heapify.
        """
        l = self.lchild(i)
        r = self.rchild(i)

        smallest = i

        if l < self.heapsize and self.arr[l] < self.arr[smallest]:
            smallest = l
        if r < self.heapsize and self.arr[r] < self.arr[smallest]:
            smallest = r

        if smallest != i:
            self.arr[smallest], self.arr[i] = self.arr[i], self.arr[smallest]
            self.min_heapify(smallest)

    def parent(self, i):
        """
        Return the index of the parent of the node at index i.

        Parameters:
        i (int): The index of the node whose parent is needed.

        Returns:
        int: The index of the parent node.
        """
        return (i - 1) // 2

    def lchild(self, i):
        """
        Return the index of the left child of the node at index i.

        Parameters:
        i (int): The index of the node whose left child is needed.

        Returns:
        int: The index of the left child node.
        """
        return (i * 2 + 1)

    def rchild(self, i):
        """
        Return the index of the right child of the node at index i.

        Parameters:
        i (int): The index of the node whose right child is needed.

        Returns:
        int: The index of the right child node.
        """
        return (i * 2 + 2)

    def getmin(self):
        """
        Return the minimum element from the heap (the root).

        Returns:
        int: The minimum element in the heap. If the heap is empty, returns None.
        """
        return None if self.heapsize <= 0 else self.arr[0]

    def insert_key(self, x):
        """
        Insert a new key into the heap while maintaining the min heap property.

        Parameters:
        x (int): The key to be inserted.
        """
        if self.heapsize == self.maxsize:
            print("Overflow.. Can't insert the key into the heap!")
            return

        self.heapsize += 1
        i = self.heapsize - 1
        self.arr[i] = x

        while i != 0 and self.arr[i] < self.arr[self.parent(i)]:
            self.arr[i], self.arr[self.parent(i)] = self.arr[self.parent(i)], self.arr[i]
            i = self.parent(i)

    def remove_min(self):
        """
        Remove and return the minimum element (root) from the heap.

        Returns:
        int: The removed minimum element from the heap. If the heap is empty, returns None.
        """
        if self.heapsize <= 0:
            return None
        if self.heapsize == 1:
            self.heapsize -= 1
            return self.arr[0]

        root = self.arr[0]
        self.arr[0] = self.arr[self.heapsize - 1]
        self.heapsize -= 1

        self.min_heapify(0)

        return root


if __name__ == "__main__":
    h = MinHeap(15)

    h.insert_key(2)
    h.insert_key(10)
    h.insert_key(5)
    h.insert_key(14)
    h.insert_key(3)

    print(h.getmin())
    h.remove_min()

    print(h.getmin())
    h.remove_min()

    print(h.getmin())
    h.remove_min()
