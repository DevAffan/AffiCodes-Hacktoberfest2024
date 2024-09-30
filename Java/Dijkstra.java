/*Question:
 * Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing. The destination cell should be 1.

Example:
grid[][] = {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}}
source = {0, 1}
destination = {2, 2}
Output:
3
Explanation: The path followed is (0,1)-->(1,1)-->(2,1)-->(2,2)

Approach is we initialize a 2D distance matrix with default values of infinite except the sorce row and column cell because we start from that cell hence the distance 
required to reach source from source is 0. Now we move to the adjacent cells like top, bottom, left and right and put values in those cells as distance required to reach previos
distance +1 . For example if we are going to (1,1) from (0,1) we put the distance value in cell (1,1) as 1 because distance value of cell (0,1) was 0 and similarly we will continue to
do it for the first iteration and store the paths in our queue to keep track of where to go next. Now for each iteration we will check if the value already stored in the distance matrix cell
is less than current if it is we dont repopulate and also dont store it in queue but if it is more we store the current value and also store it in queue, basically we do bfs traversal with
a queue or a priority queue (note priority queue is used when the distances values are not uniform).Finally when traversal continues till we exhaust the queue and the result is we get all the 
minimum distances to reach each cell from source cell.
Solution:
*/
import java.util.*;

class tuple { 
    int first, second, third; 
    tuple(int _first, int _second, int _third) {
        this.first = _first; 
        this.second = _second; 
        this.third = _third; 
    }
}
class Solution {

    int shortestPath(int[][] grid, int[] source, int[] destination) {

        // Edge Case: if the source is only the destination.
        if(source[0] == destination[0] && 
           source[1] == destination[1]) return 0; 

        // Create a queue for storing cells with their distances from source
        // in the form {dist,{cell coordinates pair}}.
        Queue<tuple> q = new LinkedList<>();  
        int n = grid.length; 
        int m = grid[0].length;

        // Create a distance matrix with initially all the cells marked as
        // unvisited and the source cell as 0. 
        int[][] dist = new int[n][m]; 
        for(int i = 0;i<n;i++) {
            for(int j =0;j<m;j++) {
                dist[i][j] = (int)(1e9); 
            }
        }
        dist[source[0]][source[1]] = 0; 
        q.add(new tuple(0, source[0], source[1])); 

        // The following delta rows and delts columns array are created such that
        // each index represents each adjacent node that a cell may have 
        // in a direction.
        int dr[] = {-1, 0, 1, 0}; 
        int dc[] = {0, 1, 0, -1}; 
 
        // Iterate through the maze by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while(!q.isEmpty()) {
            tuple it = q.peek(); 
            q.remove(); 
            int dis = it.first; 
            int r = it.second; 
            int c = it.third; 
            
            // Through this loop, we check the 4 direction adjacent nodes
            // for a shorter path to destination.
            for(int i = 0;i<4;i++) {
                int newr = r + dr[i]; 
                int newc = c + dc[i]; 
                
                // Checking the validity of the cell and updating if dist is shorter.
                if(newr >= 0 && newr < n && newc >= 0 && newc < m 
                && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]) {
                    dist[newr][newc] = 1 + dis; 

                    // Return the distance until the point when
                    // we encounter the destination cell.
                    if(newr == destination[0] && 
                       newc == destination[1]) return dis + 1; 
                    q.add(new tuple(1+dis, newr, newc)); 
                }
            }
        }
        // If no path is found from source to destination.
        return -1; 
    }
}

class Main {

    public static void main(String[] args) {
       
        int[] source={0,1};
        int[] destination={2,2};
        
        int[][] grid={{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}};

        Solution obj = new Solution();
        int res = obj.shortestPath(grid, source, destination);
        
        System.out.print(res);
        System.out.println();
    }
}