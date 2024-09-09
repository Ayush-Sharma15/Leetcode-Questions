class Solution {
    public static void helper(int left, int right, int n, String temp, List<String> ans){
        if(temp.length() == 2 * n){
            ans.add(temp);
            return;
        }

        if(left < n)
        helper(left + 1, right, n, temp + "(", ans);

        if(right < left)
        helper(left, right + 1, n, temp + ")", ans);
    }
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        helper(0, 0, n, "", ans);
        return ans;
    }
}