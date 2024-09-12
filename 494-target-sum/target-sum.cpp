class Solution {

    void helper( int ind , int sum , int& count , vector<int>& nums , int target){
        if(sum==target and ind == nums.size()){
            count++;
            return;
        }
        if(ind == nums.size())
        return;

        helper(ind+1, sum + nums[ind] , count , nums , target);

        helper(ind+1 , sum - nums[ind] , count , nums , target);

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        helper(0 , 0, count , nums , target);

        return count;

    }
};