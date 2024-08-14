class Solution {
public:
    string reverseWords(string s) {
        string result="";
        stack<string> st;
        stringstream ss(s);
        string res="";

        while(getline(ss,res,' '))
        {
            for(auto x : res)
            {
                if(x!=' ')
                {
                    st.push(res);
                    break;
                }
                else{
                   break;
                }
            }
        }

        while(!st.empty())
        {
           result+=st.top();
           result+=' ';
            st.pop();
        }
        result.pop_back();
        

        

        return result;
        
    }
};