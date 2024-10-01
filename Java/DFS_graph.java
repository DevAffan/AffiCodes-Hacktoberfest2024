// DFS is a graph traversal algorithm that explores as far along a branch as possible before backtracking.

// Key Characteristics:

// Traversal Method: Visits nodes in a depthward motion before moving laterally.
// Data Structure: Can be implemented using recursion (as in the code) or an explicit stack.
// Use Cases: Finding connected components, pathfinding, topological sorting, and solving puzzles (e.g., mazes).
// Time Complexity: O(V + E)

// V = number of vertices (nodes)
// E = number of edges
// Space Complexity: O(V)

// Due to the storage of visited nodes and recursion stack.
// Code Explanation
// Node Class:

// Represents a graph node with a value (val) and a list of neighboring nodes (nbs).
// Contains methods to initialize a node and add neighbors.

// Graph Class:

// Contains a list of nodes in the graph.
// Provides a method to add nodes to the graph.
// DFS Class:

// Contains the dfs method to initiate the traversal.
// Uses a recursive helper method dfsRecursive that:
// Marks the current node as visited.
// Prints the value of the visited node.
// Recursively visits unvisited neighboring nodes.
// Main Class:

// Creates a graph by instantiating nodes and adding edges (connections).
// Initializes a Graph object and adds nodes to it.
// Calls the dfs method to perform depth-first traversal starting from a specified node.

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

class DFS
{
	public static void dfs(Node start)
	{
		Set<Node> visited = new HashSet<>();
		dfsRecursive(start,visited);
	}
	
	private static void dfsRecursive(Node n,Set<Node> visited)
	{
		visited.add(n);
		System.out.println("Visited node: " + n.val);
		
		for(Node x:n.nbs)
		{
			if(!visited.contains(x))
			{
				dfsRecursive(x,visited);
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

        // Perform DFS
        System.out.println("DFS Traversal:");
        DFS.dfs(node0);

    }
}
