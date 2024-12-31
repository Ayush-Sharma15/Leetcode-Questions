class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        
        for (int i = 1; i < n; i++) {
            if (i % k == 0) {
                left[i] = nums[i]; // Start of a new block
            } else {
                left[i] = Math.max(left[i - 1], nums[i]);
            }
        }
        
        // Fill right array
        for (int i = n - 2; i >= 0; i--) {
            if ((i + 1) % k == 0) {
                right[i] = nums[i]; // End of a block
            } else {
                right[i] = Math.max(right[i + 1], nums[i]);
            }
        }

        int[] ans = new int[n - k + 1];
        int j = 0;
        for(int i = 0; i < n - k + 1; i++){
            ans[j++] = Math.max(right[i], left[i + k - 1]);
        }
        return ans;
    }
}