class Solution {
public:
    void helper(int left, int right, int n, string temp, vector<string>& ans){
        if(temp.length() == 2 * n){
            ans.push_back(temp);
            return;
        }

        if(left < n)
        helper(left + 1, right, n, temp + "(", ans);

        if(right < left)
        helper(left, right + 1, n, temp + ")", ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans ;
        helper(0, 0, n, "", ans);
        return ans;
    }
};