class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0, leftSum = 0, res = 0;
        int n = nums.size();

        for (int num : nums) {
            totalSum += num;
        }

        for (int i = 0; i < n - 1; i++) { 
            leftSum += nums[i];
            if (leftSum >= totalSum - leftSum) {
                res++;
            }
        }

        return res;
    }
};
