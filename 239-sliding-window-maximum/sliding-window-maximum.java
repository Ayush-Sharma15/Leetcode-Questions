class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++){
            if(i % k == 0)
            left[i] = nums[i];
            else
            left[i] = Math.max(left[i - 1], nums[i]);
            if((n - i - 1) % k == 0)
            right[n - i - 1] = nums[n - i - 1];
            else
            right[n - i - 1] = Math.max(right[n - i], nums[n - i - 1]);
        }

        int[] ans = new int[n - k + 1];
        int j = 0;
        for(int i = 0; i < n - k + 1; i++){
            ans[j++] = Math.max(right[i], left[i + k - 1]);
        }
        return ans;
    }
}