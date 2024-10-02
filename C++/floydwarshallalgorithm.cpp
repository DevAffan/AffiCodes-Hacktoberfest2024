// Floyd-Warshall Algorithm

// The Floyd-Warshall Algorithm is an efficient algorithm used to find the shortest paths between all pairs of vertices 
//in a weighted graph. 
// Unlike Dijkstra's algorithm, which finds the shortest path from a single source, Floyd-Warshall computes the shortest 
//path between every 
// pair of nodes. 
// The graph can have negative weight edges, but the algorithm does not work with graphs that contain negative weight cycles.

// Key Concepts:

// Graph Representation:

// The graph is represented by an adjacency matrix. If there is an edge from vertex i to vertex j with weight w, then graph[i][j] = w.
// If there is no edge, graph[i][j] is initialized to infinity (INF).
// graph[i][i] is set to 0 since the distance from any vertex to itself is zero.
// Algorithm Steps:

// The algorithm iterates through each vertex and attempts to improve the shortest paths between every pair of vertices by 
//using that vertex as an intermediate step.
// For each pair of vertices (i, j), check if the path i -> k -> j is shorter than the current known path i -> j. 
//If it is, update the shortest distance.
// Time Complexity:

// The algorithm has a time complexity of O(V^3), where V is the number of vertices. This is because it runs three nested loops.

//Pseudocode of Floyd-Warshall Algorithm:

// for each k in V:
//     for each i in V:
//         for each j in V:
//             if distance[i][j] > distance[i][k] + distance[k][j]:
//                 distance[i][j] = distance[i][k] + distance[k][j]

// C++ Code for Floyd-Warshall Algorithm:

// Here is a detailed implementation of the Floyd-Warshall algorithm with proper comments:
//==========================================================
#include <iostream>
#include <vector>
using namespace std;

#define INF 1e9  // A large value to represent infinity

// Function to print the solution matrix
void printSolution(const vector<vector<int>>& dist, int V) {
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << "   ";
            }
        }
        cout << endl;
    }
}

// Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& graph, int V) {
    // dist[][] will be the output matrix that will contain the shortest distances between every pair
    vector<vector<int>> dist = graph;

    // Loop over all vertices as the intermediate vertex
    for (int k = 0; k < V; k++) {
        // Loop over all pairs of vertices (i, j)
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Check if the vertex k is on the shortest path from i to j
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the result
    printSolution(dist, V);
}

int main() {
    // Number of vertices in the graph
    int V = 4;

    // Adjacency matrix representation of the graph
    // INF indicates no direct path between vertices
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    // Execute the Floyd-Warshall algorithm
    floydWarshall(graph, V);

    return 0;
}
//==========================================================
// Explanation of the Code:

// Graph Representation:

// The graph is represented as an adjacency matrix graph. For example, graph[i][j] holds the distance from vertex i to vertex j. If there is no direct edge between them, 
// it's set to a very large value (INF).

// Initialization:

// dist is initialized as a copy of the graph since the algorithm will update the shortest distances while traversing through the graph.
// Main Algorithm:

// The algorithm consists of three nested loops:
// The outermost loop iterates over each vertex k as the intermediate node.
// The next two loops go over all pairs of vertices (i, j) to check if including vertex k provides a shorter path from i to j.
// Distance Update:

// If the current distance dist[i][j] is greater than the distance dist[i][k] + dist[k][j], the distance is updated.
// Print Function:

// After calculating the shortest paths between all pairs, the result is printed using printSolution(), where INF is printed for any pair of vertices that 
// are not connected.

// Input Example:
// The input graph is represented by the adjacency matrix:

// From/To	0	1	2	3
// 0	0	5	INF	10
// 1	INF	0	3	INF
// 2	INF	INF	0	1
// 3	INF	INF	INF	0
// This means:

// Vertex 0 has edges to vertex 1 with weight 5 and vertex 3 with weight 10.
// Vertex 1 has an edge to vertex 2 with weight 3.
// Vertex 2 has an edge to vertex 3 with weight 1.
// Vertex 3 has no outgoing edges.
// Output Example:
// sql

// Shortest distances between every pair of vertices:
// 0   5   8   9   
// INF 0   3   4   
// INF INF 0   1   
// INF INF INF 0  

// Explanation of Output:

// The shortest distance from vertex 0 to vertex 2 is 8 (going through vertex 1).
// The shortest distance from vertex 1 to vertex 3 is 4 (going through vertex 2).
// All other distances are computed in a similar way.

// Real-Life Applications:

// Network Routing: Used in network routing algorithms to find the shortest path between all pairs of nodes in a communication network.
// Map Navigation: In GPS systems or applications like Google Maps, finding the shortest route between different destinations.
// Game Development: Used in game development for determining optimal paths between points in a game world.
// The Floyd-Warshall algorithm is particularly useful when you need to calculate the shortest path between all pairs of vertices in a dense graph, and it 
// works even with negative weight edges (as long as there are no negative weight cycles).

