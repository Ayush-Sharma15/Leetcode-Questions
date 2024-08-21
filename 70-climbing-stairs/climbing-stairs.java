class Solution {
    public static int helper(int n, int[] dp){
        if(n == 0)
        return 1;

        if(dp[n] != -1)
        return dp[n];

        int left = helper(n - 1, dp);
        int right = 0;
        if(n > 1)
        right = helper(n - 2, dp);

        return dp[n] = right + left;
    }
    public int climbStairs(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            int left = dp[i - 1];
            int right = 0;
            if(i > 1)
            right = dp[i - 2];

            dp[i] = left + right;
        }

        return dp[n];
    }
}