class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = 0; 
        string result = "";  
        for (char ch : s) {
            if (ch == '(') {
                if (n > 0) {  
                    result += ch;
                }
                n += 1;
            } else if (ch == ')') {
                n -= 1;
                if (n > 0) { 
                    result += ch;
                }
            }
        }
        return result;
    }
};
