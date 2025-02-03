class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int inc_count = 1, dec_count = 1, maxlen = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc_count++;
                dec_count = 1; // Reset decreasing count
            } else if (nums[i] < nums[i - 1]) {
                dec_count++;
                inc_count = 1; // Reset increasing count
            } else {
                inc_count = 1; // Reset both on equal elements
                dec_count = 1;
            }
            maxlen = max(maxlen, max(inc_count, dec_count));
        }
        return maxlen;
    }
};