class Solution {
public:
// prefix sum pattern

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int prefixSumAti = 0;
        int prefixSum = 0;
        int maxSum = INT_MIN;
        for(int j=0 ; j<n ; j++){
            prefixSum += nums[j];
            maxSum = max(maxSum , prefixSum - prefixSumAti);
            if(prefixSum < prefixSumAti){
                i = j;
                prefixSumAti = prefixSum;
            }

        }    
        return maxSum;
    }
};