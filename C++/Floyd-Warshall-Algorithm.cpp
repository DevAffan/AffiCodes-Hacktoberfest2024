// C++ Program for Floyd-Warshall Algorithm

/*
Time Complexity: O(V^3), where V is the number of vertices.
Auxiliary Space: O(V^2) due to the distance matrix used to store the shortest paths.

Input: 
- The number of vertices V.
- An adjacency matrix of size V x V where each element represents the weight of the edge between vertices.
  Use 0 for no edge and INT_MAX for infinity (no direct connection).

Output:
- The shortest distances between every pair of vertices.
*/

#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist = graph;

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, INT_MAX));

    cout << "Enter the adjacency matrix (use 0 for no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (i == j) {
                graph[i][j] = 0;
            }
        }
    }

    floydWarshall(graph);
    return 0;
}

/*

The Floyd-Warshall algorithm is a dynamic programming approach to finding the shortest paths in a weighted graph with positive or negative edge weights (but no negative cycles). 

The main idea is to use a 2D array to represent the distances between each pair of vertices and iteratively update these distances by considering each vertex as an intermediate point in the path. 

At each step, for every pair of vertices (i, j), we check if the distance from i to j through vertex k is shorter than the currently known distance from i to j. If it is shorter, we update the distance.

*/
