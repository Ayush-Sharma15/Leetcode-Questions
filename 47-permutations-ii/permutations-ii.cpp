class Solution {
    void permute(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans , vector<int>& freq){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(i > 0 && nums[i]==nums[i-1] && !freq[i - 1]) continue;
            if(!freq[i]){
                freq[i]=1;
                ds.push_back(nums[i]);
                permute( nums, ds, ans, freq);
                freq[i]=0;
                ds.pop_back();
        }
        }
    }
    

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>ds;
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int>freq(nums.size(), 0);

        permute( nums , ds , ans , freq );

        return ans;
    }
};