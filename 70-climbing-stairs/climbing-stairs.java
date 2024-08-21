class Solution {
    public int climbStairs(int n) {
        int[] dp = new int[n + 1];
        int pre1 = 1;
        int pre2 = 0;
        int curr = 0;

        for(int i = 1; i <= n; i++){
            int left = pre1;
            int right = 0;
            if(i > 1)
            right = pre2;

            curr = left + right;
            pre2 = pre1;
            pre1 = curr;
        }

        return pre1;
    }
}