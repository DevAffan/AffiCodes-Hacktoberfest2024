import java.util.*;
class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();

        Solution1 nm1 = new Solution1();
        System.out.println(nm1.uniquePaths(m, n));

        Solution1 nm2 = new Solution1();
        System.out.println(nm2.uniquePaths(m, n));

        Solution1 nm3 = new Solution1();
        System.out.println(nm3.uniquePaths(m, n));

        Solution1 nm4 = new Solution1();
        System.out.println(nm4.uniquePaths(m, n));

        sc.close();
    }
}

// Recursion
class Solution1 {

    public int uniquePaths(int m, int n) {

        return task1(m-1, n-1);
    }
    private int task1(int m, int n)
    {
        if(m < 0 || n < 0)
        {
            return 0;
        }
        if(m == 0 && n == 0)
        {
            return 1;
        }
        return task1(m-1, n) + task1(m, n-1);
    }
}


// Memoization
class Solution2 {

    public int uniquePaths(int m, int n) {

        int dp[][] = new int[m][n];
        for(int i[]: dp)
        {
            Arrays.fill(i,-1);
        }
        return task1(m-1, n-1, dp);
    }
    private int task1(int m, int n, int dp[][])
    {
        if(m < 0 || n < 0)
        {
            return 0;
        }
        if(m == 0 && n == 0)
        {
            return 1;
        }
        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }
        return dp[m][n] = task1(m-1, n, dp) + task1(m, n-1, dp);
    }
}


// Tabulation method
class Solution3 {

    public int uniquePaths(int m, int n) {

        int dp[][] = new int[m+1][n+1];
        for(int i=0; i<=m; i++)
        {
            dp[i][0] = 1;
        }
        for(int i=0; i<=n; i++)
        {
            dp[0][i] = 1;
        }
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
}


// Tabulation method with space optimization
class Solution4 {

    public int uniquePaths(int m, int n) {

        int prev[] = new int[n+1];
        for(int i=0; i<=m; i++)
        {
            prev[0] = 1;
        }
        for(int i=1; i<=m; i++)
        {
            int cur[] = new int[n+1];
            cur[0] = 1;
            for(int j=1; j<=n; j++)
            {
                cur[j] = prev[j] + cur[j-1];
            }
            prev = cur;
        }
        return prev[n-1];
    }
}