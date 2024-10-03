/* A Naive recursive implementation
of 0-1 Knapsack problem */
class GfG {

    // Returns the maximum value that
    // can be put in a knapsack of
    // capacity W
    static int knapSack(int W, int wt[], int val[], int n)
    {
        // Base Case
        if (n == 0 || W == 0)
            return 0;

        // If weight of the nth item is
        // more than Knapsack capacity W,
        // then this item cannot be included
        // in the optimal solution
        if (wt[n - 1] > W)
            return knapSack(W, wt, val, n - 1);

        // Return the maximum of two cases:
        // (1) nth item included
        // (2) not included
        else
            return Math.max(knapSack(W, wt, val, n - 1), 
             val[n - 1] + knapSack(W - wt[n-1], wt, val, n-1));
    }

    // Driver code
    public static void main(String args[])
    {
        int profit[] = new int[] { 60, 100, 120 };
        int weight[] = new int[] { 10, 20, 30 };
        int W = 50;
        int n = profit.length;
        System.out.println(knapSack(W, weight, profit, n));
    }
}


//TEST CASES 
/*
Let, weight[] = {1, 2, 3}, profit[] = {10, 15, 40}, Capacity = 6


If no element is filled, then the possible profit is 0.
weight⇢
item⇣/	0	1	2	3	4	5	6
0	0	0	0	0	0	0	0
1	 	 	 	 	 	 	 
2	 	 	 	 	 	 	 
3	 	 	 	 	 	 	 
For filling the first item in the bag: If we follow the above mentioned procedure, the table will look like the following.
weight⇢
item⇣/	0	1	2	3	4	5	6
0	0	0	0	0	0	0	0
1	0	10	10	10	10	10	10
2	 	 	 	 	 	 	 
3	 	 	 	 	 	 	 
For filling the second item:  
When jthWeight = 2, then maximum possible profit is max (10, DP[1][2-2] + 15) = max(10, 15) = 15.
When jthWeight = 3, then maximum possible profit is  max(2 not put, 2 is put into bag) = max(DP[1][3], 15+DP[1][3-2]) = max(10, 25) = 25.
weight⇢
item⇣/	0	1	2	3	4	5	6
0	0	0	0	0	0	0	0
1	0	10	10	10	10	10	10
2	0	10	15	25	25	25	25
3	 	 	 	 	 	 	 
For filling the third item:
When jthWeight = 3, the maximum possible profit is max(DP[2][3], 40+DP[2][3-3]) = max(25, 40) = 40.
When jthWeight = 4, the maximum possible profit is max(DP[2][4], 40+DP[2][4-3]) = max(25, 50) = 50.
When jthWeight = 5, the maximum possible profit is max(DP[2][5], 40+DP[2][5-3]) = max(25, 55) = 55.
When jthWeight = 6, the maximum possible profit is max(DP[2][6], 40+DP[2][6-3]) = max(25, 65) = 65.
weight⇢
item⇣/	0	1	2	3	4	5	6
0	0	0	0	0	0	0	0
1	0	10	10	10	10	10	10
2	0	10	15	25	25	25	25
3	0	10	15	40	50	55	65

*/