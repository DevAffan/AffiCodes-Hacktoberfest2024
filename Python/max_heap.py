class MaxHeap:
    """
    A class that implements a Max Heap data structure. The largest element is at the root of the heap.
    """

    def __init__(self, maxsize):
        """
        Initialize the heap with a maximum size.

        Parameters:
        maxsize (int): The maximum number of elements the heap can hold.
        """
        self.maxsize = maxsize
        self.arr = [None] * maxsize
        self.heapSize = 0

    def maxHeapify(self, i):
        """
        Ensure the max heap property for the subtree rooted at index i.

        Parameters:
        i (int): The index of the root of the subtree to heapify.
        """
        l = self.lchild(i)
        r = self.rchild(i)

        largest = i
        if l < self.heapSize and self.arr[l] > self.arr[largest]:
            largest = l
        if r < self.heapSize and self.arr[r] > self.arr[largest]:
            largest = r
        if largest != i:
            self.arr[largest], self.arr[i] = self.arr[i], self.arr[largest]
            self.maxHeapify(largest)

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
        return (2 * i) + 1

    def rchild(self, i):
        """
        Return the index of the right child of the node at index i.

        Parameters:
        i (int): The index of the node whose right child is needed.

        Returns:
        int: The index of the right child node.
        """
        return 2 * i + 2

    def getMax(self):
        """
        Return the maximum element from the heap (the root).

        Returns:
        int: The maximum element in the heap. If the heap is empty, returns None.
        """
        return self.arr[0] if self.heapSize > 0 else None

    def getCurSize(self):
        """
        Return the current number of elements in the heap.

        Returns:
        int: The current size of the heap.
        """
        return self.heapSize

    def insertKey(self, x):
        """
        Insert a new key into the heap while maintaining the max heap property.

        Parameters:
        x (int): The key to be inserted.
        """
        if self.heapSize == self.maxsize:
            print("\nOverflow. Can't insert the key.\n")
            return

        self.heapSize += 1
        i = self.heapSize - 1
        self.arr[i] = x

        # Fix the max heap property if it's violated
        while i != 0 and self.arr[i] > self.arr[self.parent(i)]:
            self.arr[i], self.arr[self.parent(i)] = self.arr[self.parent(i)], self.arr[i]
            i = self.parent(i)

    def removeMax(self):
        """
        Remove and return the maximum element (root) from the heap.

        Returns:
        int: The removed maximum element from the heap. If the heap is empty, returns None.
        """
        if self.heapSize <= 0:
            return None
        if self.heapSize == 1:
            self.heapSize -= 1
            return self.arr[0]

        root = self.arr[0]
        self.arr[0] = self.arr[self.heapSize - 1]
        self.heapSize -= 1

        # Fix the max heap property
        self.maxHeapify(0)

        return root


if __name__ == "__main__":
    h = MaxHeap(15)

    h.insertKey(3)
    h.insertKey(10)
    h.insertKey(12)
    h.insertKey(8)
    h.insertKey(2)
    h.insertKey(14)

    print(h.getMax())
    h.removeMax()
    print(h.getMax())
