//T.C -> O(n^3)  S.C -> O(n^2)
public class FloydWarshallInPlace {
    //doing floyd warshall in place just updating the given matrix with the shortest distance
    public static void floydWarshall(int[][] matrix) {
        int n = matrix.length; // n is the number of nodes (vertices)
        
        //initializing unreachable nodes to infinity and distance from node to itself to 0.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = (int) 1e9; // Mark unreachable nodes with a large number (infinity)
                }
                if (i == j) {
                    matrix[i][j] = 0; // Distance from a node to itself is 0
                }
            }
        }
        
        //main algorithm
        // Iterate over all possible intermediate nodes k
        for (int k = 0; k < n; k++) {
            // For each node i
            for (int i = 0; i < n; i++) {
                // For each node j, calculate the shortest path from i to j via k
                for (int j = 0; j < n; j++) {
                    //going from i to j (i -> j) via k
                    matrix[i][j] = Math.min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        
        //marking nodes that cannot be visited in any way as -1 at the end of algorithm
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == (int) 1e9) {
                    matrix[i][j] = -1; // Mark unreachable nodes back to -1
                }
            }
        }
    }

    // Function to print the resulting matrix after applying Floyd-Warshall
    public static void printMatrix(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    System.out.print("INF "); // Print "INF" for unreachable nodes
                } else {
                    System.out.print(matrix[i][j] + "   "); // Print the distance for reachable nodes
                }
            }
            System.out.println(); // Print a new line after each row
        }
    }

    public static void main(String[] args) {
        //example matrix as a test case 
        int[][] matrix = {
            {0, 3, -1, 7},
            {8, 0, 2, -1},
            {5, -1, 0, 1},
            {-1, 2, 3, 0}
        };

        floydWarshall(matrix); // Apply Floyd-Warshall algorithm on the matrix
        printMatrix(matrix); // Print the result
    }
}
