// BFS is a graph traversal algorithm that explores all neighbors at the present depth prior to moving on to nodes at the next depth level.

// Key Characteristics:

// Traversal Method: Visits nodes layer by layer.
// Data Structure: Utilizes a queue to keep track of nodes to be explored.
// Use Cases: Finding the shortest path in unweighted graphs, traversing trees, and level-order traversal of trees.
// Time Complexity: O(V + E)

// V = number of vertices (nodes)
// E = number of edges
// Space Complexity: O(V)

// Due to the storage of visited nodes and the queue.
// Code Explanation
// Node Class:

// Represents a graph node with a value (val) and a list of neighboring nodes (nbs).
// Contains methods to initialize a node and add neighbors.
// Graph Class:

// Maintains a list of nodes in the graph.
// Provides a method to add nodes to the graph.
// BFS Class:

// Contains the bfs method to initiate the traversal.
// Uses a queue to track nodes to visit:
// Marks the starting node as visited and adds it to the queue.
// While the queue is not empty, it:
// Dequeues the front node.
// Prints the value of the visited node.
// Enqueues unvisited neighboring nodes.
// Main Class:

// Creates a graph by instantiating nodes and establishing connections.
// Initializes a Graph object and adds nodes to it.
// Calls the bfs method to perform breadth-first traversal starting from a specified node.

import java.util.*;

class Node
{
	int val;
	List<Node> nbs; //list of neighbours 
	
	public Node(int val)
	{
		this.val=val;
		this.nbs = new ArrayList<>();
	}
	
	public void addNbs(Node nb)
	{
		nbs.add(nb);
	}
}

class Graph
{
	List<Node> nodes;
	
	public Graph()
	{
		this.nodes = new ArrayList<>();
	}
	
	public void addNode(Node n)
	{
		nodes.add(n);
	}
}

class BFS {
    public static void bfs(Node start) {
        Set<Node> visited = new HashSet<>();
        Queue<Node> queue = new LinkedList<>();

        visited.add(start);
        queue.offer(start);

        while (!queue.isEmpty()) {
            Node current = queue.poll();
            System.out.println("Visited node: " + current.val);

            for (Node x : current.nbs) {
                if (!visited.contains(x)) {
                    visited.add(x);
                    queue.offer(x);
                }
            }
        }
    }
}


public class Main {
    public static void main(String[] args) {
        // Create nodes
        Node node0 = new Node(0);
        Node node1 = new Node(1);
        Node node2 = new Node(2);
        Node node3 = new Node(3);
        Node node4 = new Node(4);

        // Create edges
        node0.addNbs(node1);
        node0.addNbs(node2);
        node1.addNbs(node3);
        node2.addNbs(node4);

        // Create graph
        Graph graph = new Graph();
        graph.addNode(node0);
        graph.addNode(node1);
        graph.addNode(node2);
        graph.addNode(node3);
        graph.addNode(node4);

        System.out.println("BFS Traversal:");
        BFS.bfs(node0);
    }
}
