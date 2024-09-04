class Solution {
public:
    vector<vector<int>> FindCombinations(int ind, int target, vector<int>& arr,
                                         vector<vector<int>>& ans,
                                         vector<int>& ds) {
        
        if (target < 0 or ind >= arr.size()){
            if (target == 0) {
            ans.push_back(ds);
        }
            return ans;
            }

        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            FindCombinations(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
        }

        FindCombinations(ind + 1, target, arr, ans, ds);

        return ans;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        FindCombinations(0, target, candidates, ans, ds);
        return ans;
    }
};