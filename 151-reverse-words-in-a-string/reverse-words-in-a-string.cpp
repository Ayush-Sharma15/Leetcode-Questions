class Solution {
public:
    string reverseWords(string s) {
        string s1 = "", ans = "";
        stack<string> st;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                s1 += s[i]; 
            } else if(!s1.empty()) {
                st.push(s1); 
                s1 = ""; 
            }
        }

        if(!s1.empty()) {
            st.push(s1);
        }

        while(!st.empty()) {
            ans += st.top(); 
            st.pop();
            if(!st.empty()) ans += " "; 
        }

        return ans;
    }
};
