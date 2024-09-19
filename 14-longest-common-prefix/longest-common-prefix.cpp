class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        if (n == 0)
            return "";
        
        int res = s[0].length();

        for (int i = 1; i < n; i++) {
            int count = 0;
            for (int j = 0; j < min(s[i-1].length(), s[i].length()); j++) {
                if (s[i-1][j] == s[i][j])
                    count++;
                else
                    break;
            }
            res = min(res, count);
        }
        return s[0].substr(0, res);
    }
};
