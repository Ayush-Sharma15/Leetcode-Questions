class Solution {
    public int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        int []dp=new int[n+1];
        int p1=1;
        int p2=2;
        for(int i=3;i<n+1;i++){
            dp[i]=p1+p2;
            p1=p2;
            p2=dp[i];
        }
        return dp[n];
    }
}