class Solution {
    void allCombination(int ind , int k , int sum , vector<vector<int>>& ans , vector<int>& ds){
        if(k==0 and sum==0){
            ans.push_back(ds);
            return;
        }
        if(k==0)
        return;

        for(int i=ind ;i<=9 ; i++){
            ds.push_back(i);
            allCombination(i+1 , k-1 , sum-i , ans , ds );
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        allCombination(1 , k , n , ans , ds );

        return ans;
    }
};