class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size(),c=0;
        for(int i=0;i<n;i++){
            if(nums[i]%3==0)
            continue;
            else
            c+=1;
        }
        return c;
    }
};