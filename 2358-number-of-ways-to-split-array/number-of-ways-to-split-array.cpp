class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), res = 0;
        long long leftsum = nums[0];
        long long sum = accumulate(nums.begin(), nums.end(), 0LL); 
        sum -= nums[0];

        for (int i = 1; i < n; i++) {
            if (leftsum >= sum)
                res++;

            leftsum += nums[i];
            sum -= nums[i];
        }
        return res;
    }
};
