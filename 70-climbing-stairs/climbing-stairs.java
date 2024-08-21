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
        Arrays.fill(dp, -1);
        return helper(n, dp);
    }
}