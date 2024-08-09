class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int i=1;
        int c=1;
        int ans=0;
        for(i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]-nums[i-1]==1){
                    c+=1;
                }else{
                    ans=max(ans,c);
                    c=1;
                }
            }
        }
        return max(ans,c);
    }
};