class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid=0,begin=0,upper=nums.size()-1;
        while(begin<=upper){
            mid = begin + (upper - begin) / 2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target)
             {
                upper=mid-1;
             }      
             else
             begin=mid+1;
            }

        return begin;    

    }
};